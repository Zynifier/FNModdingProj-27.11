// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "Movement/FortMovementMode_BaseExtLogic.h"
#include "FortMovementMode_ELTacSprint.generated.h"

class ACharacter;
class AFortPawn;
class AFortWeapon;
class UFortCameraMode;
class UFortComponent_Energy;
class USoundBase;
class USoundMix;

USTRUCT()
struct FFortMovementMode_TacSprintRuntimeData : public FFortMovementMode_BaseExtRuntimeData
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class TACTICALSPRINTRUNTIME_API UFortMovementMode_ELTacSprint : public UFortMovementMode_BaseExtLogic, public IFortHolsterWeaponSourceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleFailedToSprint();

	UFUNCTION()
	void HandleMovementModeChanged(ACharacter* Character, EMovementMode PreviousMovementMode, uint8 PreviousCustomMode);

	UFUNCTION()
	void HandleOnEnergyDrained(UFortComponent_Energy* EnergyComp);

	UFUNCTION()
	void HandleOnEnterAircraft();

	UFUNCTION()
	void HandleOnEnteredEditMode();

	UFUNCTION()
	void HandleOnPawnJump();

	UFUNCTION()
	void HandleOnPlayerWeaponChanged(AFortPawn* InPawn, AFortWeapon* InNewWeapon, AFortWeapon* InPlayerWeapon);

	UFUNCTION()
	void HandleOnReloadCanceling();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag GCEnergyDrain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag GCSpeedLines;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag GCSprintEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat RampUpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat RampDownSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat JumpHeightMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag TutorialGameplayTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTagContainer TutorialAdditionalSourceTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTagContainer TutorialTargetTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag TagPreventWeaponHolster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTagContainer TacticalSprintFail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTagContainer TacticalSprintFailLowEnergy;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> OnEnergyFullyDrainedSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag TacticalBehaviorTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	float MinSpeedForHolster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	float HolsterTimeAttemptDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	float MinEnergyToActivate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	bool bIsCancelledBySliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FScalableFloat MinEnergyToActivateRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FScalableFloat HF_EnergyCostOnStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FScalableFloat HF_EnergyCostPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FScalableFloat HF_EnergyCostOnJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag IgnoreJumpCostTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag TacticalSprintTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag EnergyUseIdentifier;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<USoundMix> SprintStartedSoundMix;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Action")
	TObjectPtr<USoundBase> SprintStartedSound2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FScalableFloat HF_TacSprintEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	TSubclassOf<UFortCameraMode> CameraMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ELTacSprint")
	FGameplayTag CameraModeTag;

};

