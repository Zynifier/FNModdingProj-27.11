// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "WindFields/WindField.h"
#include "RadialWindField.generated.h"

class UCurveFloat;
class UOperatorField;
class URadialFalloff;
class URadialVector;

UCLASS(BlueprintType, Blueprintable)
class ARadialWindField : public AWindField
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field|Cosmetic Field")
	FScalableFloat FieldRadius;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field|Cosmetic Field")
	FScalableFloat FieldStrength;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field|Physics Field")
	FScalableFloat ForceRadius;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field|Physics Field")
	FScalableFloat ForceStrength;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field|Physics Field")
	TObjectPtr<UCurveFloat> ForceStrengthDistanceFalloff;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field|Pawn Field")
	FName PawnForceName;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field|Pawn Field")
	FScalableFloat PawnForceStrength;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field|Pawn Field")
	TObjectPtr<UCurveFloat> PawnForceStrengthDistanceFalloff;

	UPROPERTY(EditAnywhere, Transient, Category="Radial Wind Field|Pawn Field")
	bool bPawnForceIsPush;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<URadialVector> RadialVector;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<URadialFalloff> RadialFalloff;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UOperatorField> OperatorField;

};

