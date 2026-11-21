// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Creative/Commandlets/IslandProcessing/FortIslandTextRemovalTaskFullSpawnPatcher.h"
#include "FortIslandTextRemovalTaskTemplateRecordPatcher.generated.h"

class AActor;
class UActorComponent;
class UObject;

UCLASS()
class UFortIslandTextRemovalTaskTemplateRecordPatcher : public UFortIslandTextRemovalTaskFullSpawnPatcher
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TMap<FGuid, TObjectPtr<AActor>> CurrentGuidToActorMap;

	UPROPERTY()
	TMap<TSoftClassPtr<AActor>, UClass*> LoadedActorClasses;

	UPROPERTY()
	TMap<TSoftClassPtr<UActorComponent>, UClass*> LoadedActorComponentClasses;

	UPROPERTY()
	TSet<TSoftClassPtr<AActor>> InvalidCreativeDeviceClasses;

};

