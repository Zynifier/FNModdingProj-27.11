// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortAthenaVehicle.h"
#include "FortAthenaSimpleCar.generated.h"

class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaSimpleCar : public AFortAthenaVehicle
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> MeshComponent;

};

