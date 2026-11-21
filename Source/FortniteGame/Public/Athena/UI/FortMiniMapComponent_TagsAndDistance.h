// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UI/FortMiniMapComponent.h"
#include "FortMiniMapComponent_TagsAndDistance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "VisibleDistance", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFortMiniMapComponent_TagsAndDistance : public UFortMiniMapComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortMiniMapComponent_TagsAndDistance")
	FScalableFloat MapViewableDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortMiniMapComponent_TagsAndDistance")
	FScalableFloat MiniMapViewableDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortMiniMapComponent_TagsAndDistance")
	FGameplayTagContainer ValidGameplayTags;

};

