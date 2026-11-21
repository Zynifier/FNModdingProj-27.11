// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAIAnimInstance.h"
#include "FortHuskAnimInstance.generated.h"

enum class EFortHuskAnimType : uint8;

UENUM()
enum class EFortHuskAnimType : uint8
{
	Basic = 0,
	Dwarf = 1,
	BlasterBig = 2,
	Weak = 3,
	TinyHead = 4,
	Beehive = 5,
	Husky = 6,
	Sploder = 7,
	Zapper = 8,
};

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortHuskAnimInstance : public UFortAIAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="HuskAnimInstance")
	EFortHuskAnimType GetHuskAnimType() const;

	UFUNCTION(BlueprintCallable, Category="HuskAnimInstance")
	void SetHuskAnimType(EFortHuskAnimType NewHuskAnimType);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	EFortHuskAnimType HuskAnimType;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	float FallAsleepAnimDuration;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	float AltFallAsleepAnimDuration;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	float WakeUpAnimDuration;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	float FallAsleepToSleepingCrossfade;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	float WakeUpToIdleCrossfade;

	UPROPERTY(EditAnywhere, Category="AI")
	float DefaultToDwarfScaleRatio;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHuskAnimInstance")
	float LookAtAlpha;

	UPROPERTY(EditAnywhere, Category="AI")
	float LookAtInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHuskAnimInstance")
	float AdjustedLowerBodyWeight;

	UPROPERTY(EditAnywhere, Category="AI")
	float AdjustedLowerBodyInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHuskAnimInstance")
	float RunPlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHuskAnimInstance")
	float ZapperOverrideWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement")
	float RunStartPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement")
	float AuthoredJogSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Movement")
	int32 MovementStyleIsWalking;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortHuskAnimInstance")
	uint8 bForceFullBodyMontage : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHuskAnimInstance")
	uint8 bIsDwarf : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHuskAnimInstance")
	uint8 bIsZapper : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_IdleToMove : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_IdleToFallAsleep : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_IdleToStunned : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_IdleToKnockedbackDown : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_IdleToKnockedbackUp : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_MoveToIdle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_FallAsleepToSleeping : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_SleepingToWakeUp : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_WakeUpToIdle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_StunnedToIdle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_KnockedbackDownToIdle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_KnockedbackUpToKnockedbackDown : 1;

};

