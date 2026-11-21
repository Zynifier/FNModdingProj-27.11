// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FortInspectorCameraCreative.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortInspectorCameraCreativePreview.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortInspectorCameraCreativePreview : public AFortInspectorCameraCreative, public ILevelSaveSpawnable
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortInspectorCameraCreativePreview")
	FGuid SavedActorGuid;

};

