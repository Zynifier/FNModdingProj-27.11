// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FortCustomCameraController.h"
#include "Pawns/FortPlayerPawn.h"
#include "FortFirstPersonCameraController.generated.h"

class AController;
class APawn;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class FORTNITEGAME_API AFortFirstPersonCameraController : public AFortCustomCameraController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortFirstPersonCameraController", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float CameraBlendSwitchMeshTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortFirstPersonCameraController")
	TArray<EBodyPartVisibilityGrouping> BodyPartGroupingsToHide;

protected:
	UPROPERTY(BlueprintReadWrite, Category="FortFirstPersonCameraController")
	float FirstPersonCameraInteractionDistanceScalar;

private:
	UFUNCTION()
	void BindVehicleEvents(APawn* Pawn, AController* OldController, AController* NewController);

};

