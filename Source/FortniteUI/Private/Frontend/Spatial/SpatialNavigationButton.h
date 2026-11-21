// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CommonButtonLegacy.h"
#include "SpatialNavigationButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpatialNavigationButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AthenaSpatialNavigationButton", meta=(Categories="ERG.Camera"))
	FGameplayTag CameraTagToNavigateTo;

};

