// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "VerseGameplayTagAssetInterface.h"
#include "VerseGameplayTagContainer.h"
#include "EntityTagContainerComponent.generated.h"

// This intermediate class is used for interop with UHT, specifically the editor metadata for InternalTags property and the implementation of the IGameplyTagAssetInterface

UCLASS(Abstract)
class VERSEGAMEPLAYTAGS_API UEntityTagContainerComponent : public UEntityComponent, public IVerseGameplayTagAssetInterface
{
	GENERATED_BODY()

protected:
	// Used by the editor for specifying gameplay tags
// Use UHT to expose these settings to the editor, UHT can't run directly on verse classes

	UPROPERTY(EditAnywhere, Category="GameplayTags", meta=(DisplayName="Tags", ShowOnlyInnerProperties))
	FVerseGameplayTagContainer InternalTags;

};

