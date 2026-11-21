// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/LayerAnimInstance/FortVehicleLayerAnimInstance.h"
#include "FortVehicleLayerAnimInstance_Jackal.generated.h"

class AFortAthenaJackalVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleLayerAnimInstance_Jackal : public UFortVehicleLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Jackal")
	FFortAnimInput_JackalVehicle JackalVehicleInput;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category="FortVehicleLayerAnimInstance_Jackal")
	float AimYaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category="FortVehicleLayerAnimInstance_Jackal")
	float AimPitch;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaJackalVehicle> JackalVehicle;

};

