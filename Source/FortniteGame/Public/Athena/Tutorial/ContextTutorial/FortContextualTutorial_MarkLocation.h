// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_MarkLocation.generated.h"

UCLASS()
class UFortContextualTutorial_MarkLocation : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandlePawnLanded(const FHitResult& Hit);

	UFUNCTION()
	void HandleStartSkydivingForActivation();

	UFUNCTION()
	void OnAddMapMarkerOnClient(const FFortWorldMarkerData& Marker);

};

