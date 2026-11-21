// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortVehicleDynAnimInstance.h"
#include "FortVehicleDynAnimInstance_Ferret.generated.h"

class AFortAthenaFerretVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleDynAnimInstance_Ferret : public UFortVehicleDynAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortAthenaFerretVehicle> FerretVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance_Ferret")
	FRotator BobbleHeadJiggle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance_Ferret")
	FRotator PaperJiggle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance_Ferret")
	FRotator CurrentDriveJiggleRandom;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance_Ferret")
	FRotator CurrentDriveJiggleRandom2;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance_Ferret")
	FRotator WingRotations;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance_Ferret")
	float WingJiggleAlpha;

};

