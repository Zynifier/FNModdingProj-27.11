// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "CreativePlayerReplicationProxy.generated.h"

class UCreativeProxyManagerComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class FORTNITEGAME_API ACreativePlayerReplicationProxy : public AInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Replicated, Export, Category="CreativePlayerReplicationProxy", meta=(EditInline="true"))
	TObjectPtr<UCreativeProxyManagerComponent> ProxyManagerOwnerComponent;

};

