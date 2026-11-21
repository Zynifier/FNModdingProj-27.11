// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "DeltaFile.h"
#include "ThumbnailSpawnerInterface.h"
#include "LevelRecordSpawner.generated.h"

class AActor;
class UObject;

UCLASS(Config=Game, DefaultConfig, MinimalAPI)
class ULevelRecordSpawner : public UObject, public IDeltaFileApplier, public IThumbnailSpawner
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<FGuid, TObjectPtr<AActor>> AdditionalGuidToActorTableForReferenceFixup;

	UPROPERTY(Transient)
	TMap<FGuid, FGuid> AdditionalGuidToGuidTableForReferenceFixup;

private:
	UFUNCTION()
	bool FailsafeTimerExpired(float dts);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> LoadedDependencies;

	UPROPERTY(Transient)
	TMap<FGuid, TObjectPtr<AActor>> SpawnedActors;

	UPROPERTY(Transient)
	TSubclassOf<UObject> OptionalRootActorClass;

	UPROPERTY(Transient)
	TObjectPtr<AActor> OptionalRootActor;

};

