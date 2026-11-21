// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "EntityFortniteStormControllerComponent.generated.h"

class AEntityFortniteStormSpawner;

UCLASS(meta=(RequireDependantEntityComponent="UActorAdaptorEntityComponent"))
class ENTITYFORTNITE_API UEntityFortniteStormControllerComponent : public UEntityComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Storm Spawner")
	TSubclassOf<AEntityFortniteStormSpawner> StormSpawnerClass;

	UPROPERTY(VisibleAnywhere, Category="Storm Spawner")
	TObjectPtr<AEntityFortniteStormSpawner> StormSpawner;

};

