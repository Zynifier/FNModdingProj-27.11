// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LevelSaveRecordThumbnailGenerator.generated.h"

class AActor;
class IThumbnailSpawner;
class UCameraComponent;
class USceneCaptureComponent2D;

UCLASS()
class FORTNITEGAME_API ULevelSaveRecordThumbnailGenerator : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TSoftClassPtr<AActor> StageActorClassPtr;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USceneCaptureComponent2D> SceneCaptureComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY()
	TScriptInterface<IThumbnailSpawner> ActiveSpawner;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> SpawnedActors;

};

