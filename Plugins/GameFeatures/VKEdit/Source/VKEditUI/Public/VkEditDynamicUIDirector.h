// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicUI/DynamicUIDirectorBase.h"
#include "VkEditDynamicUIDirector.generated.h"

class UDynamicUIScene;

UCLASS(HideCategories=("Actor", "ActorTick", "Collision", "Cooking", "DataLayers", "Events", "HLOD", "Input", "LOD", "Physics", "Rendering", "Replication", "WorldPartition"))
class VKEDITUI_API AVkEditDynamicUIDirector : public ADynamicUIDirectorBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Dynamic UI Director")
	TObjectPtr<UDynamicUIScene> MemorySamplingScene;

};

