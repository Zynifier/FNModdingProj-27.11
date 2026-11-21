// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FortPlayerCameraBase.h"
#include "FortPlayerCameraSpectator.generated.h"

class UFortCinematicCamera;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Transform|Actor", "Rendering", "Activation", "Replication", "INPUT", "Actor", "LOD", "Transform|Actor", "Rendering", "Activation", "Replication", "INPUT", "Actor", "HLOD"))
class AFortPlayerCameraSpectator : public AFortPlayerCameraBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortCinematicCamera> SpectatorCam;

};

