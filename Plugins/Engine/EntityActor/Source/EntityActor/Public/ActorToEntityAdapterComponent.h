// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorToEntityAdapterComponent.generated.h"

class UEntityComponent;

UCLASS(EditInlineNew, HideCategories=("Activation", "ComponentReplication", "Tags", "Cooking", "AssetUserData", "Collision", "Object", "LOD", "Lighting", "Transform", "TextureStreaming"), ClassGroup=("Entity"), meta=(BlueprintSpawnableComponent))
class ENTITYACTOR_API UActorToEntityAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Transient, SkipSerialization, Category="Entity", meta=(DisplayName="Entity ID"))
	int32 DebugEntityID;
#endif

	// Editor created list of components for this entity, kept in sync with the EntityCoreSubsystem, used for serialization & duplication.

	UPROPERTY(VisibleAnywhere, Instanced, Category="Entity")
	TArray<TObjectPtr<UEntityComponent>> SerializedComponents;

#if WITH_EDITORONLY_DATA
	// Keep track of class names to report components that failed to load because their class is unknown (typically not loaded).
// @fixme Do we want to remove WITH_EDITORONLY_DATA and report this in game as well?

	UPROPERTY()
	TArray<FName> SerializedComponentClassNames;
#endif

	/** Force the owner to be replicated when created at runtime */
	UPROPERTY()
	uint8 bForceOwnerReplication : 1;

};

