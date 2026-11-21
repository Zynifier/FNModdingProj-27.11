// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortSkyDiveContrailPreviewActor.generated.h"

class UAthenaSkyDiveContrailItemDefinition;

UCLASS(Abstract, BlueprintType, meta=(ChildCanTick))
class AFortSkyDiveContrailPreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="SkyDiveContrails")
	void PreviewContrail(const UAthenaSkyDiveContrailItemDefinition* Contrail);

};

