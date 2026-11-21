// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortCosmeticMaterialBlueprintLibrary.generated.h"

class UMaterialInstanceDynamic;
class UMeshComponent;

UCLASS()
class UFortCosmeticMaterialBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(AdvancedDisplay="MaterialName"))
	static UMaterialInstanceDynamic* GetOrCreateDynamicOverlayMaterial(UMeshComponent* MeshComponent, const FName MaterialName = NAME_None);

	UFUNCTION(BlueprintCallable)
	static void ResetScalarParameterOnMaterials(UMeshComponent* MeshComponent, const FName ParameterName);

	UFUNCTION(BlueprintCallable)
	static void ResetScalarParameterOnOverlayMaterial(UMeshComponent* MeshComponent, const FName ParameterName);

	UFUNCTION(BlueprintCallable)
	static void SetScalarParameterValueOnOverlayMaterial(UMeshComponent* MeshComponent, const FName ParameterName, const float ParameterValue);

};

