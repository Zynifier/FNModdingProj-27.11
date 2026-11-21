// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortWaterFloodSetupActor.generated.h"

class UTexture2D;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AFortWaterFloodSetupActor : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="WaterFlood", meta=(CallInEditor="true"))
	void OnSetOceanFloodHeight(const int32 Step);

protected:
	UFUNCTION(BlueprintCallable)
	void SetMinimapData(TSoftObjectPtr<UTexture2D> BaseTexture, TSoftObjectPtr<UTexture2D> DiscoveryMaskTexture);

};

