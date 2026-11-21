// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CreativeUserContentManager.generated.h"

class AActor;
class ULevelSaveRecord;
class ULevelSaveRecordThumbnailGenerator;

USTRUCT()
struct FCreativeThumbnailCacheData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UCreativeUserContentManager : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FName, TObjectPtr<ULevelSaveRecord>> LevelSaveRecords;

	UPROPERTY()
	TMap<FName, FCreativeThumbnailCacheData> SaveThumbnails;

	UPROPERTY(Transient)
	TObjectPtr<ULevelSaveRecordThumbnailGenerator> ThumbnailGenerator;

	UPROPERTY(EditDefaultsOnly, Category="Creative")
	TSoftClassPtr<AActor> ThumbnailStageActorClassSoftClassPtr;

};

