// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotify_CrownWear.generated.h"

class UCurveVector;
class UFXSystemComponent;
class UTimelineComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class VICTORYCROWNSRUNTIME_API AFortGameplayCueNotify_CrownWear : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyCrownWear(const TArray<UFXSystemComponent*>& ParticleComponents);

	UFUNCTION()
	void OnIntroFXTimelineTick(const FVector CurveValue);

	UFUNCTION(BlueprintCallable)
	void RemoveCrownWear();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Parameters", meta=(MultiLine="true"))
	FScalableFloat IntroFXVisualVolume;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Parameters", meta=(MultiLine="true"))
	FScalableFloat IntroFXTimelineRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Parameters", meta=(MultiLine="true"))
	FScalableFloat IntroFXUpdatePrecision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Parameters", meta=(MultiLine="true"))
	TArray<FScalableFloat> IntroFXUpdateFrequencies;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotify_CrownWear")
	TObjectPtr<UCurveVector> IntroFXCurve;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UTimelineComponent> IntroFXTimeline;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> CrownParticleComponent;

};

