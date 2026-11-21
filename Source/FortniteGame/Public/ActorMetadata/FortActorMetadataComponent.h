// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorMetadata/FortActorMetadata.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortActorMetadataComponent.generated.h"

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortActorMetadataComponent : public UActorComponent, public ILevelSaveSpawnable
{
	GENERATED_BODY()

private:
	UPROPERTY(SaveGame)
	FName TemplateID;

	UPROPERTY(SaveGame)
	FFortActorTemplateAssetData TemplateAssetData;

};

