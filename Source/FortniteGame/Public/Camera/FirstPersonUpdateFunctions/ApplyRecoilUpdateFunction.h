// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "Camera/FortFirstPersonState.h"
#include "ApplyRecoilUpdateFunction.generated.h"

UENUM(BlueprintType)
enum class ERecoilType : uint8
{
	Fixed = 0,
	RandomNegativeOneToOne = 1,
	RandomZeroToOne = 2,
};

USTRUCT(BlueprintType)
struct FRecoilPart
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RecoilPart")
	FVector Translation;

	UPROPERTY(EditAnywhere, Category="RecoilPart")
	FRotator Rotation;

	UPROPERTY(EditAnywhere, Category="RecoilPart")
	ERecoilType RecoilType;

	UPROPERTY(EditAnywhere, Category="RecoilPart")
	float SpringStiffness;

	UPROPERTY(EditAnywhere, Category="RecoilPart")
	float SpringDamping;

	UPROPERTY(EditAnywhere, Category="RecoilPart")
	float KickVelocity;

};

UCLASS(BlueprintType)
class UApplyRecoilUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ApplyRecoilUpdateFunction")
	EMotionTarget MotionTarget;

	UPROPERTY(EditAnywhere, Category="ApplyRecoilUpdateFunction")
	TArray<FRecoilPart> RecoilParts;

private:
	UPROPERTY(Transient)
	FTransform DeltaTransform;

};

