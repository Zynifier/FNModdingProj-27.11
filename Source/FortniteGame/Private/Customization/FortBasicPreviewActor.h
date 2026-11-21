// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FortBasicPreviewActor.generated.h"

UCLASS(Abstract, BlueprintType)
class AFortBasicPreviewActor : public AActor, public IFortUICameraFrameTargetInterface
{
	GENERATED_BODY()

};

