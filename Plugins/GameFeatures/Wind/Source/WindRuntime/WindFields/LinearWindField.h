// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/RootMotionSource.h"
#include "Math/MathFwd.h"
#include "WindFields/WindField.h"
#include "LinearWindField.generated.h"

class UCurveFloat;
class UOperatorField;
class URadialFalloff;
class URadialVector;

USTRUCT()
struct FRootMotionSource_ConstantWindForce : public FRootMotionSource
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Force;

	UPROPERTY()
	TObjectPtr<UCurveFloat> StrengthOverTime;

};

UCLASS(BlueprintType, Blueprintable)
class ALinearWindField : public AWindField
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field")
	FVector Direction;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field")
	float FieldStrength;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field")
	float ForceStrength;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field")
	FName PawnForceName;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field")
	float PawnForceStrength;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<URadialVector> RadialVector;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<URadialFalloff> RadialFalloff;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UOperatorField> OperatorField;

};

