// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "EntityToActorAdapterComponent.generated.h"

UCLASS(EditInlineNew, HideCategories=("Activation", "ComponentReplication", "Tags", "Cooking", "AssetUserData", "Collision", "Object", "LOD", "Lighting", "Transform", "TextureStreaming"), ClassGroup=("Actor"), meta=(EnforceSingleEntityComponent))
class ENTITYACTOR_API UEntityToActorAdapterComponent : public UEntityComponent
{
	GENERATED_BODY()

};

