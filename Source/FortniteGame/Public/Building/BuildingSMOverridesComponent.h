// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "BuildingSMOverridesComponent.generated.h"

class ABuildingSMActor;
class UMaterialInterface;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UBuildingSMOverridesComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UBuildingSMOverridesComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void OnRep_OverrideMeshMaterials();

	UPROPERTY(ReplicatedUsing=OnRep_OverrideMeshMaterials)
	TArray<TObjectPtr<UMaterialInterface>> OverrideMeshMaterials;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingSMActor> OwnerBuilding;

};

