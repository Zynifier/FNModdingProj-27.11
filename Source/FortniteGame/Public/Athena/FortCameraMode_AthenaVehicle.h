// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "FortCameraMode_AthenaVehicle.generated.h"

class AFortPawn;
class IFortVehicleInterface;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortCameraMode_AthenaVehicle : public UFortCameraMode_ThirdPerson
{
	GENERATED_BODY()

public:
	UFUNCTION()
	FORTNITEGAME_API void OnPawnExitedVehicleFromSeat(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex);

	UPROPERTY(EditAnywhere, Category="Camera")
	FVector CameraOriginOffset;

};

