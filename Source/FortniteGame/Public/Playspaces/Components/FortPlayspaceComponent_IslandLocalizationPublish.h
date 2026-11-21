// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "FortPlayspaceComponent_IslandLocalizationPublish.generated.h"

class UFortLevelSaveComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPlayspaceComponent_IslandLocalizationPublish : public UFortPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortLevelSaveComponent> SaveComponent;

};

