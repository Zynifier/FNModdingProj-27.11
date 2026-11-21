// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "Camera/FortFirstPersonState.h"
#include "Inherit3PAnimationUpdateFunction.generated.h"

UENUM(BlueprintType)
enum class EModifierInheritanceType : uint8
{
	RelativeMotion = 0,
	AbsoluteMotion = 1,
};

UENUM(BlueprintType)
enum class EModifierPriority : uint8
{
	Min = 0,
	VeryLow = 1,
	Low = 2,
	Default = 3,
	High = 4,
	VeryHigh = 5,
	Max = 6,
};

USTRUCT(BlueprintType)
struct FFortFirstPersonModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortFirstPersonModifier")
	bool bEnabled;

	UPROPERTY(EditAnywhere, Category="FortFirstPersonModifier", meta=(EditCondition="bActive"))
	EModifierPriority Priority;

	UPROPERTY(EditAnywhere, Category="FortFirstPersonModifier", meta=(ClampMax="1.0", ClampMin="0.0", EditCondition="bActive"))
	float MotionDecayRate;

	UPROPERTY(EditAnywhere, Category="FortFirstPersonModifier")
	EModifierInheritanceType InheritanceType;

	UPROPERTY(EditAnywhere, Category="FortFirstPersonModifier", meta=(EditCondition="bActive"))
	FTransform InheritRatios;

	UPROPERTY(EditAnywhere, Category="FortFirstPersonModifier", meta=(EditCondition="bActive"))
	FTransform Offset;

	UPROPERTY(Transient)
	float RelativeMotionRatio;

};

UCLASS(BlueprintType)
class UInherit3PAnimationUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Inherit3PAnimationUpdateFunction")
	EMotionTarget Target;

	UPROPERTY(EditAnywhere, Category="Inherit3PAnimationUpdateFunction")
	FVector TranslationInheritRatios;

	UPROPERTY(EditAnywhere, Category="Inherit3PAnimationUpdateFunction")
	FRotator RotationInheritRatios;

	UPROPERTY(EditAnywhere, Category="Inherit3PAnimationUpdateFunction", meta=(ClampMax="1.0", ClampMin="0.0"))
	float MotionBlendRate;

	UPROPERTY(EditAnywhere, Category="Inherit3PAnimationUpdateFunction", meta=(ClampMax="1.0", ClampMin="0.0"))
	float MotionDecayRate;

	UPROPERTY(EditAnywhere, Category="Inherit3PAnimationUpdateFunction", meta=(ClampMax="1.0", ClampMin="0.01"))
	float ModifierBlendRate;

	UPROPERTY(EditAnywhere, Category="Inheritance Modifiers")
	FFortFirstPersonModifier EquipModifier;

	UPROPERTY(EditAnywhere, Category="Inheritance Modifiers")
	FFortFirstPersonModifier ReloadModifier;

	UPROPERTY(EditAnywhere, Category="Inheritance Modifiers", meta=(ClampMax="5.0", ClampMin="0.0"))
	float SecondsToModifyOnFire;

	UPROPERTY(EditAnywhere, Category="Inheritance Modifiers", meta=(EditCondition="SecondsToModifyOnFire>0"))
	FFortFirstPersonModifier FireModifier;

	UPROPERTY(EditAnywhere, Category="Inheritance Modifiers")
	FFortFirstPersonModifier MantleModifier;

	UPROPERTY(EditAnywhere, Category="Inheritance Modifiers")
	FFortFirstPersonModifier HurdleModifier;

	UPROPERTY(EditAnywhere, Category="Inheritance Modifiers")
	FFortFirstPersonModifier SprintModifier;

	UPROPERTY(EditAnywhere, Category="Inherit3PAnimationUpdateFunction", meta=(ClampMax="10000.0", ClampMin="0.0"))
	float MaxYawRate;

private:
	UPROPERTY(Transient)
	FTransform AccumulatedTransform;

	UPROPERTY(Transient)
	FTransform SmoothedAccumulatedTransform;

	UPROPERTY(Transient)
	FTransform DebugTransform;

	UPROPERTY(Transient)
	FTransform RuntimeInheritRatios;

	UPROPERTY(Transient)
	float InheritScalar;

	UPROPERTY(Transient)
	FFortFirstPersonModifier TargetModifier;

	UPROPERTY(Transient)
	FFortFirstPersonModifier PreviousModifier;

	UPROPERTY(Transient)
	FFortFirstPersonModifier BlendedModifier;

	UPROPERTY(Transient)
	FFortFirstPersonModifier BaseModifier;

	UPROPERTY(Transient)
	float ModifierBlendAlpha;

};

