// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_PingCommand.generated.h"

USTRUCT()
struct FFortPingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FFortWorldMarkerData MarkerData;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPawnComponent_PingCommand : public UFortPawnComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FFortPingInfo PingInfo;

};

