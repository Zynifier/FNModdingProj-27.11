// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Volumes/GameplayEffectVolume.h"
#include "WaterVolume_Shallow.generated.h"

class USoundBase;

UCLASS(MinimalAPI, HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AWaterVolume_Shallow : public AGameplayEffectVolume
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WaterVolume_Shallow")
	TObjectPtr<USoundBase> EntrySound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WaterVolume_Shallow")
	TObjectPtr<USoundBase> ExitSound;

	UPROPERTY(EditAnywhere, Category="WaterVolume_Shallow")
	FGameplayTag PlayerPawnActionTag;

	UPROPERTY(EditAnywhere, Category="WaterVolume_Shallow")
	FScalableFloat FluidFrictionOverride;

};

