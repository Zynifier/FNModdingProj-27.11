// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/AnimInputs/FortAnimInput_VehicleDriverAnimAsset.h"
#include "FortVehicleAnimSet.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortVehicleAnimSet : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AnimSet")
	FFortAnimInput_VehicleDriverAnimAsset DefaultAnimAsset;

	UPROPERTY(EditAnywhere, Category="AnimSet")
	FFortAnimInput_VehicleDriverAnimAsset FemaleOverrideAnimAsset;

};

