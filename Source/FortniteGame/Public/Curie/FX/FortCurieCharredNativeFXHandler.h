// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curie/FX/FortCurieNativeFXHandler.h"
#include "FortCurieCharredNativeFXHandler.generated.h"

class UFortCurieComponent;

UCLASS()
class UFortCurieCharredNativeFXHandler : public UFortCurieNativeFXHandler
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCurieComponent>> CharredEffectInterpComponents;

	UPROPERTY(Transient)
	float CharredEffectInterpolationSignificanceRequirement;

	UPROPERTY(Transient)
	double PreviousCharTickTime;

};

UCLASS()
class UFortCurieCharredNativeFXHandlerConfig : public UFortCurieNativeFXHandlerConfig
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Char", meta=(ClampMin="0.010000", UIMIn="0.010000"))
	float CharredStateInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Char", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float CharredStateFireAttachedFinalAlpha;

	UPROPERTY(EditDefaultsOnly, Category="Char", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float CharredStateNearFireFinalAlpha;

	UPROPERTY(EditDefaultsOnly, Category="Char", meta=(ClampMin="0", UIMin="0"))
	int32 CharredEffectPrimitiveDataIdx;

};

