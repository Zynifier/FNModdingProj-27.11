// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/CreativePlayerReplicationProxy.h"
#include "CreativeAudioComponent.h"
#include "CreativeAudioPlayerReplicationProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class ACreativeAudioPlayerReplicationProxy : public ACreativePlayerReplicationProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated)
	FCreativeAudioPlayerData InstigatorData;

};

