// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_Vehicle.generated.h"

class AActor;
class AFortPlayerPawn;

UCLASS()
class UFortContextualTutorial_Vehicle : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void AileronRollCallback();

	UFUNCTION()
	void HandleVehicleStateChanged(AFortPlayerPawn* PlayerPawn, AActor* NewVehicle, AActor* OldVehicle);

};

