// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "ScalableFloat.h"
#include "Building/BuildingProp_ConversationCompatible.h"
#include "FortUrgentQuestData.h"
#include "BuildingProp_BountyBoard.generated.h"

class AActor;
class AFortMinigame;
class AFortPlayerPawn;
class AFortPlayerStateAthena;
enum class EFortMinigameState : uint8;
enum class EFortQuestState : uint8;

USTRUCT()
struct FPawnBountyInteractionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	AFortPlayerPawn* PawnInInteractRange;

	UPROPERTY(Transient)
	bool bBountyAvailable;

	UPROPERTY(Transient)
	bool bBountyInProgress;

};

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_BountyBoard : public ABuildingProp_ConversationCompatible
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void NotifyBountyEnded(AFortPlayerStateAthena* HunterPlayerState, const FGameplayTag& UrgentQuestTag, const EFortQuestState QuestState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBountyBoardReset();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnBountyEnded(AFortPlayerStateAthena* HunterPlayerState, const FGameplayTag& UrgentQuestTag);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnBountyStarted(const TArray<AFortPlayerStateAthena*>& HunterPlayerStates);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnLocalPlayerGrantedBounty(AFortPlayerStateAthena* HunterPlayerState, const FUrgentQuestData& UrgentQuestData);

	UFUNCTION()
	void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StartUpdatingInteractionText(const AActor* TriggeredActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StopUpdatingInteractionText(const AActor* TriggeredActor);

	UPROPERTY(EditAnywhere, Category="BuildingProp_BountyBoard")
	bool bAllowGrantMultipleBountiesToSingleSquad;

	UPROPERTY(EditAnywhere, Category="BuildingProp_BountyBoard", meta=(ClampMax="5", ClampMin="0.25", UIMax="5", UIMin="0.25"))
	float InteractionTextRefreshRate;

	UPROPERTY(EditAnywhere, Category="BuildingProp_BountyBoard")
	FScalableFloat NumberOfPlayersToSelectFrom;

	UPROPERTY(EditAnywhere, Category="BuildingProp_BountyBoard")
	FScalableFloat bAllowBountiesOnFriendlies;

	UPROPERTY(EditAnywhere, Category="BuildingProp_BountyBoard")
	FGameplayTagQuery TargetFilter;

	UPROPERTY(EditAnywhere, Category="BuildingProp_BountyBoard")
	FText NoBountiesAvailableInteractionText;

	UPROPERTY(EditAnywhere, Category="BuildingProp_BountyBoard")
	FText BountyInProgressInteractionText;

	UPROPERTY(BlueprintReadOnly, Category="BuildingProp_BountyBoard")
	FText FailedInteractionTextToUse;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_BountyBoard")
	FLinearColor InteractSubTextColor;

private:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastSetInteractionText(const TArray<FPawnBountyInteractionInfo>& PawnBountyInteractionInfo);

	UFUNCTION()
	void OnRep_PlayersGrantedBounty();

	UPROPERTY(Transient)
	TArray<AFortPlayerPawn*> PawnsInInteractRange;

	UPROPERTY(Transient)
	TSet<AFortPlayerStateAthena*> PlayersGrantedBountySet;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayersGrantedBounty)
	TArray<AFortPlayerStateAthena*> PlayersGrantedBounty;

};

