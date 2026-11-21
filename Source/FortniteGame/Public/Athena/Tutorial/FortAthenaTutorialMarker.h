// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortStaticMeshActor.h"
#include "FortAthenaTutorialMarker.generated.h"

UCLASS(HideCategories=("Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaTutorialMarker : public AFortStaticMeshActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Objective Marker")
	void OnMarkerVisibilityChanged(bool isActive);

	UFUNCTION(BlueprintImplementableEvent, Category="Objective Marker")
	void PlayInTransition();

};

