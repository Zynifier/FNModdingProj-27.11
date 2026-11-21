// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "VoteInitiationActor.generated.h"

class UVoteBroadcasterComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Collision", "Input", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AVoteInitiationActor : public AInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UVoteBroadcasterComponent> VoteBroadcasterComponent;

};

