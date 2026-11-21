// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "GameplayTagContainer.h"
#include "Building/TaggingVolumes/FortGameplayTagVolumeInterface.h"
#include "FortGameplayTagVolume.generated.h"

UCLASS(HideCategories=("Collision", "Transform", "Activation", "Actor", "Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameplayTagVolume : public AVolume, public IFortGameplayTagVolumeInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GameplayTag")
	FGameplayTagContainer TagsToApplyOnSave;

};

