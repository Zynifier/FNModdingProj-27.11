// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkeletalMeshComponentBudgeted.h"
#include "FortVehicleSkelMeshComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Object", "Mesh|SkeletalAsset", "Object", "Mobility", "Trigger"))
class UFortVehicleSkelMeshComponent : public USkeletalMeshComponentBudgeted
{
	GENERATED_BODY()

public:
	UFortVehicleSkelMeshComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

