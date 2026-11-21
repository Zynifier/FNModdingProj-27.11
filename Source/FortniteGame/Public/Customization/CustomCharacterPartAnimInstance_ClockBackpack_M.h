// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_ClockBackpack_M.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_ClockBackpack_M : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Cuckoo")
	void PopOutCuckooOnKill();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CollisionBone")
	FVector BoneAPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CollisionBone")
	float AimOffsetMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FRotator BackpackRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FName BackpackRotatorBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FName BackpackRotatorBaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FVector2D BackpackRotatorMapInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FVector2D BackpackRotatorMapOutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pendulum")
	FRotator PendulumRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pendulum")
	float PendulumFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pendulum")
	float PendulumAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PendulumDynamics")
	float PendulumDynamicsAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PendulumDynamics")
	float PendulumDynamicsSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PendulumDynamics")
	float PendulumDynamicsCrouchWalkAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PendulumDynamics")
	FVector2D PendulumDynamicsSpeedMapInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PendulumDynamics")
	FVector2D PendulumDynamicsSpeedMapOutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClockHands")
	FRotator HourHandRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClockHands")
	float HourHandPitchMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClockHands")
	FRotator MinuteHandRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClockHands")
	float MinuteHandPitchMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cuckoo")
	bool bIsCuckooOut;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cuckoo")
	bool bCuckooOutOnKillRequested;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cuckoo")
	float CuckooDynamicsAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cuckoo")
	float CuckooOutTimeRemaining;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cuckoo")
	float CuckooOutDurationOnKill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cuckoo")
	float CuckooOutDurationInFrontEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cuckoo")
	int32 CuckooFrontEndInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Llama")
	FVector CurrentLlamaScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Llama")
	FVector DefaultLlamaScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Llama")
	FVector CuckooOutLlamaScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Llama")
	float DefaultLlamaScaleInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Llama")
	float CuckooOutLlamaScaleInterpSpeed;

};

