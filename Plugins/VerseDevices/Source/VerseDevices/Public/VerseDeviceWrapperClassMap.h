// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VerseDeviceWrapperClassMap.generated.h"

class AActor;
class UVerseCreativeObject;

UCLASS(BlueprintType)
class VERSEDEVICES_API UVerseDeviceWrapperClassMap : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Verse")
	TMap<TSoftClassPtr<AActor>, TSubclassOf<UVerseCreativeObject>> DeviceClassMap;

};

