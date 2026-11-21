// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkeletalMeshComponentBudgeted.h"
#include "FortPooledSkelMeshComponent.generated.h"

class UMaterialInterface;

UCLASS(HideCategories=("Object", "Mesh|SkeletalAsset", "Object", "Mobility", "Trigger"))
class UFortPooledSkelMeshComponent : public USkeletalMeshComponentBudgeted
{
	GENERATED_BODY()

public:
	UFortPooledSkelMeshComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY()
	TArray<TObjectPtr<UMaterialInterface>> SavedMaterials;

};

