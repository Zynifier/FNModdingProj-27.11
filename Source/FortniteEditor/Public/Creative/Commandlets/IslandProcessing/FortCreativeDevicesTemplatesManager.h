// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCreativeDevicesTemplatesManager.generated.h"

class AActor;
class UActorComponent;
class UFortCreativeActorCollection;
class UObject;
class UWorld;

UCLASS()
class UFortCreativeDevicesTemplatesManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<TSoftClassPtr<AActor>, UClass*> LoadedActorClasses;

	UPROPERTY()
	TMap<TSoftClassPtr<UActorComponent>, UClass*> LoadedActorComponentClasses;

	UPROPERTY()
	TSet<TSoftClassPtr<AActor>> InvalidCreativeDeviceClasses;

	UPROPERTY()
	UWorld* ActorTemplatesWorld;

	UPROPERTY()
	TObjectPtr<UFortCreativeActorCollection> CreativeAssetCollection;

};

