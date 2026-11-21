// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortToyPreviewActor.generated.h"

class UAthenaToyItemDefinition;

UCLASS(Abstract, BlueprintType)
class AFortToyPreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Spray")
	void PreviewToy(const UAthenaToyItemDefinition* Toy);

};

