// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "GameplayTagContainer.h"
#include "Components/FortControllerComponent.h"
#include "Components/FortInterface_OverrideCanInteract.h"
#include "FortControllerComponent_Ghost.generated.h"

class AFortPawn;
class AFortPlayerControllerGameplay;
class APawn;
class UFortGadgetItemDefinition;
class UGameplayEffect;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortControllerComponent_Ghost : public UFortControllerComponent, public IFortInterface_OverrideCanInteract
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Controller|Ghost Mode")
	void EndGhostMode();

	UFUNCTION(BlueprintPure, Category="Controller|Ghost Mode")
	bool IsInGhostMode() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Controller|Ghost Mode")
	void SetBecomeGhostOnDBNO(bool bEnable);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Controller|Ghost Mode")
	void StartGhostMode();

protected:
	UFUNCTION()
	void HandleAbilityEnded(const FAbilityEndedData& AbilityData);

	UFUNCTION()
	void OnGhostModeChanged(AFortPlayerControllerGameplay* PlayerController, bool bEnteredGhostMode);

	UFUNCTION()
	void OnPawnDBNOStateChange(AFortPawn* Pawn, bool bNewDBNOState);

	UFUNCTION()
	void OnPlayerPossession(APawn* PossessPawn);

	UFUNCTION()
	void ReviveAndBecomeGhosted();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortControllerComponent_Ghost")
	TObjectPtr<UFortGadgetItemDefinition> ItemProvidingGhostMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_Ghost")
	FGameplayTagContainer AbilitiesToBlockWhenGhosted;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_Ghost")
	FGameplayTagContainer GhostModeTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_Ghost")
	uint8 bBecomeInvulnerableWhenGhosted : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_Ghost")
	uint8 bBecomeAIIgnoredWhenGhosted : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_Ghost")
	uint8 bSetHealthAndShieldsToZeroWhenGhosted : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_Ghost")
	uint8 bBecomeGhostOnDBNO : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_Ghost")
	uint8 bOverrideInteractionComponent : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_Ghost")
	uint8 bKeepWeaponHolsteredWhenGhosted : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_Ghost", meta=(EditCondition="bBecomeGhostOnDBNO"))
	TSubclassOf<UGameplayEffect> DBNOToGhostReviveGameplayEffect;

};

