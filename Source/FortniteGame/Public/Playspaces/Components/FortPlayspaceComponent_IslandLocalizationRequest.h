// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "FortPlayspaceComponent_IslandLocalizationRequest.generated.h"

class APlayspace;
class UFortLevelSaveComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPlayspaceComponent_IslandLocalizationRequest : public UFortPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortLevelSaveComponent> SaveComponent;

	UPROPERTY(Transient)
	TObjectPtr<APlayspace> ParentPlayspace;

};

