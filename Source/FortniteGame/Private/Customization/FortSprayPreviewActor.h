// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortSprayPreviewActor.generated.h"

class UAthenaSprayItemDefinition;

UCLASS(Abstract, BlueprintType)
class AFortSprayPreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Spray")
	void PreviewSpray(const UAthenaSprayItemDefinition* Spray);

};

