// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "FortInteractInterface.h"
#include "BuildingGameplayActorSpawnMachine.generated.h"

class ABuildingGameplayActorSpawnMachine;
class AFortGameStateAthena;
class AFortPawn;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class AFortPlayerStart;
class UFortPlaylist;
class USoundCue;
enum class ESpawnMachineState : uint8;

UENUM(BlueprintType)
enum class ESpawnMachineState : uint8
{
	Default = 0,
	WaitingForUse = 1,
	// Ready to be used by anyone

	BeingUsed = 2,
	// Someone is interacting to trigger use

	Active = 3,
	// Started resurrection

	Complete = 4,
	// Ended resurrection

	OnCooldown = 5,
};

UENUM(BlueprintType)
enum class ESpawnMachineSubTextState : uint8
{
	NoCards = 0,
	VanInUse = 1,
	TeamOnOtherVan = 2,
	None = 3,
	HasResource = 4,
	NoResource = 5,
	NotEnabledForPlayer = 6,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawnMachineLinkedToRebootComponent, const ABuildingGameplayActorSpawnMachine*, SpawnMachineBGA);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorSpawnMachine : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Resurrection")
	float GetCooldownLength() const;

	UFUNCTION(BlueprintPure, Category="Resurrection")
	ESpawnMachineState GetSpawnMachineState() const;

	UFUNCTION(BlueprintPure, Category="Resurrection")
	bool UseResurrectionTetherRange() const;

protected:
	UFUNCTION(BlueprintPure, Category="Interaction")
	bool CanPlayerSquadInteract(const AFortPawn* InteractingPawn, const TEnumAsByte<TInteractionType>& InteractionType) const;

	UFUNCTION(BlueprintNativeEvent, Category="Resurrection")
	void OnBeginLongUse(AFortPlayerControllerAthena* AthenaPC);

	UFUNCTION(BlueprintNativeEvent, Category="Resurrection")
	void OnInterruptLongUse(AFortPlayerControllerAthena* AthenaPC);

	UFUNCTION(BlueprintNativeEvent, Category="Resurrection")
	void OnPlayerPawnResurrected(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintNativeEvent, Category="Resurrection")
	void OnResurrectionCompleted();

	UFUNCTION(BlueprintNativeEvent, Category="Resurrection")
	void OnResurrectionStarted(AFortPlayerControllerAthena* PlayerController);

	UFUNCTION(BlueprintNativeEvent, Category="Resurrection")
	void OnSpawnMachineStateChanged();

	UFUNCTION(BlueprintPure, Category="Resurrection")
	bool RebootPlayersInAir() const;

	UFUNCTION(BlueprintCallable, Category="Resurrection")
	void SetSpawnMachineState(ESpawnMachineState NewState);

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStart> ResurrectLocation;

	UPROPERTY(Transient)
	TArray<FUniqueNetIdRepl> PlayerIdsForResurrection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingGameplayActorSpawnMachine")
	TWeakObjectPtr<AFortPlayerControllerAthena> InstigatorPC;

	UPROPERTY(Transient)
	bool bIsLocallyBeingInteractedWith;

	UPROPERTY(Transient)
	uint8 ActiveTeam;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SpawnMachineState)
	ESpawnMachineState SpawnMachineState;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection")
	FScalableFloat ResurrectionHeightOffset;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection")
	FScalableFloat ResurrectionStartDelay;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection")
	FScalableFloat ResurrectionNextPlayerDelay;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection")
	TObjectPtr<USoundCue> InteractSoundCueLoop;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection")
	FScalableFloat CooldownLengthRow;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|Interaction")
	FText InteractNoCardsSubText;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|Interaction")
	FText InteractVanInUseSubText;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|Interaction")
	FText InteractTeamStartedRebootSubText;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|Interaction")
	FText InteractNotEnabledForPlayerSubText;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|Interaction")
	FText RebootResourceStatusFormatSubText;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|Interaction")
	FLinearColor InteractSubTextFailedColor;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|Interaction")
	FLinearColor InteractSubTextSuccessColor;

	UPROPERTY(Transient)
	ESpawnMachineSubTextState SpawnMachineSubTextState;

	UPROPERTY(Transient, Replicated)
	int32 HandleIntoGameState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Resurrection|Interaction")
	FScalableFloat RebootResourceCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Resurrection|Interaction")
	FScalableFloat ResurrectionHorizontalTetherMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Resurrection|Interaction")
	FScalableFloat ResurrectionVerticalTetherMultiplier;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerControllerAthena> InitiatingPlayer;

	UPROPERTY(BlueprintAssignable)
	FOnSpawnMachineLinkedToRebootComponent OnSpawnMachineLinkedToRebootComponent;

private:
	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnRep_SpawnMachineState();

};

