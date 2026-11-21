// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/FortAthenaVehicle.h"
#include "FortAthenaLivingWorldStaticPointProvider.h"
#include "FortAthenaLivingWorldVehiclePointProvider.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AFortAthenaLivingWorldVehiclePointProvider : public AFortAthenaLivingWorldStaticPointProvider
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	FGameplayTagContainer ForceMods;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	FScalableFloat ForceModsAllowed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	TEnumAsByte<EVehicleInitialOverlapBehavior::Type> InitialOverlapBehavior;

};

