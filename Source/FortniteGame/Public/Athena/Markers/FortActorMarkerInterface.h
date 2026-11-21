// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "FortActorMarkerInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UFortActorMarkerInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortActorMarkerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetMarkerData(const FFortWorldMarkerData& MarkerData, const FMarkedActorDisplayInfo& DisplayInfo);

};

