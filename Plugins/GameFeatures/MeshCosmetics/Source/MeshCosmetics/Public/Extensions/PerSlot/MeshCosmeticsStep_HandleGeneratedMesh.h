// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Extensibility/FortCosmeticItemAdditionalData.h"
#include "Cosmetics/Extensibility/FortCosmeticStep.h"
#include "MeshCosmeticsStep_HandleGeneratedMesh.generated.h"

UCLASS(meta=(DisplayName="Specify Material Only Mutable Parameters", ShortTooltip="Specify Mutable parameters which do not cause a change in geometry, physics, or animation assets."))
class UMeshCosmeticsAdditionalData_SpecifyMaterialOnlyParams : public UFortCosmeticItemAdditionalData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CustomizableObjectParameters")
	TArray<FName> MaterialOnlyParameterNames;

};

UCLASS()
class UMeshCosmeticsStep_HandleGeneratedMesh : public UFortCosmeticStep
{
	GENERATED_BODY()

};

