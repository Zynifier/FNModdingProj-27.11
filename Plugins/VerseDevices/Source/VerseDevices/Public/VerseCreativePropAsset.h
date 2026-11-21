// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseCreativePropAsset.generated.h"

class AActor;
class ULevelSaveRecord;
class UObject;

UCLASS(MinimalAPI)
class UVerseCreativePropAsset : public UObject
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="VerseCreativePropAsset")
	TSoftObjectPtr<UObject> AssetForEditor;
#endif

private:
	UPROPERTY()
	FName AssetPathName;

	UPROPERTY()
	TObjectPtr<ULevelSaveRecord> LevelSaveRecord;

	UPROPERTY()
	TSoftClassPtr<AActor> ActorClass;

};

