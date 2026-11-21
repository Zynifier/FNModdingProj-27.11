// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameplayTagContainer.h"
#include "FortPOICameraActor.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPOICameraActor : public ACameraActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="POICamera")
	FGameplayTag POITag;

};

