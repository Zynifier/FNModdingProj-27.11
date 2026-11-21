// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortMusicPackPreviewActor.generated.h"

class UAthenaMusicPackItemDefinition;

UCLASS(Abstract, BlueprintType)
class AFortMusicPackPreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Cosmetics")
	void PreviewMusicPack(const UAthenaMusicPackItemDefinition* MusicPack);

};

