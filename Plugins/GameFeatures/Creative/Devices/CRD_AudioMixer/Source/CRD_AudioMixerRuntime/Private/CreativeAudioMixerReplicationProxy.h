// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/CreativePlayerReplicationProxy.h"
#include "CreativeAudioMixerReplicationProxy.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class ACreativeAudioMixerReplicationProxy : public ACreativePlayerReplicationProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated)
	bool bIsActive;

};

