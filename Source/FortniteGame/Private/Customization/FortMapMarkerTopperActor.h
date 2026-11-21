// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortMapMarkerTopperActor.generated.h"

class UAthenaMapMarkerItemDefinition;

UCLASS(Abstract, BlueprintType)
class AFortMapMarkerTopperActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Spray")
	void OnMarkerMoved();

	UFUNCTION(BlueprintImplementableEvent, Category="Spray")
	void PreviewMapMarker(const UAthenaMapMarkerItemDefinition* Marker);

	UFUNCTION(BlueprintImplementableEvent, Category="Spray")
	void SetLiveMapMarker(const UAthenaMapMarkerItemDefinition* Marker);

};

