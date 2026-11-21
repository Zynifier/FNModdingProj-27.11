// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_AppleSunSmall_Passive.generated.h"

class ACharacter;
class AFortPlayerPawn;
class UCharacterMovementComponent;
class UGameplayEffect;

UCLASS()
class UFortGameplayAbility_AppleSunSmall_Passive : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void UpdateCanCrashpad();

	UFUNCTION(BlueprintCallable)
	void UpdateIsCloseToGround();

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayAbility_AppleSunSmall_Passive")
	TWeakObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortGameplayAbility_AppleSunSmall_Passive")
	TWeakObjectPtr<UCharacterMovementComponent> CharacterMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	FScalableFloat UpdateIntervalRow;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	TSubclassOf<UGameplayEffect> CanCrashpadGameplayEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	FGameplayTagContainer CanCrashpadGameplayTags;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	FGameplayTagContainer GliderRedeployTags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float UpdateInterval;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float MaxFallVelocity;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float CloseToGroundThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float GroundTraceMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float MaxVelocityJumpPromt;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float DefaultMinVelocityJumpPromt;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float SwimmingMinVelocityJumpPromt;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float CurrentMinVelocityJumpPrompt;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float DefaultMinTimeSinceGroundedForJumpPrompt;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float SwimmingMinTimeSinceGroundedForJumpPrompt;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float CurrentMinTimeSinceGroundedForJumpPrompt;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float TraceDistanceToGround;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameplayAbility_AppleSunSmall_Passive")
	float TimeSinceGrounded;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayAbility_AppleSunSmall_Passive")
	bool bCanCrashpadByJumping;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	bool bPreviousCanCrashpad;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayAbility_AppleSunSmall_Passive")
	bool bIsCloseToGround;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayAbility_AppleSunSmall_Passive")
	bool bIsClambering;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayAbility_AppleSunSmall_Passive")
	bool bBlockedTag;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayAbility_AppleSunSmall_Passive")
	bool bGliderTag;

private:
	UFUNCTION()
	void OnPlayerMovementModeChanged(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

};

