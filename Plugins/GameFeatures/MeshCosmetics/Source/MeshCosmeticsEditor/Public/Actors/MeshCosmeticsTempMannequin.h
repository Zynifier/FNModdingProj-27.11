// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Extensions/MeshCosmeticsCustomizationTypes.h"
#include "LiveLink/FortLiveMannequin.h"
#include "MeshCosmeticsTempMannequin.generated.h"

class UCustomizableObject;
class UCustomizableObjectInstance;

USTRUCT()
struct FJumpsuitMannequinFloatParam
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="JumpsuitMannequinFloatParam")
	FString ParamName;

	UPROPERTY(EditAnywhere, Category="JumpsuitMannequinFloatParam")
	float Value;

};

USTRUCT()
struct FJumpsuitMannequinIntParam
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="JumpsuitMannequinIntParam")
	FString ParamName;

	UPROPERTY(EditAnywhere, Category="JumpsuitMannequinIntParam")
	FString Value;

};

UCLASS(HideCategories=("Materials"))
class AMeshCosmeticsTempMannequin : public AFortLiveMannequin
{
	GENERATED_BODY()

public:
	UFUNCTION(Category="Test", meta=(CallInEditor="true"))
	void ReapplyVariants();

	UPROPERTY(EditAnywhere, Category="Test")
	TArray<FJumpsuitMannequinIntParam> IntParams;

	UPROPERTY(EditAnywhere, Category="Test")
	TArray<FJumpsuitMannequinFloatParam> FloatParams;

private:
	UPROPERTY(Transient)
	TMap<UCustomizableObject*, UCustomizableObjectInstance*> CustomizableObjectInstances;

	UPROPERTY()
	FMeshCosmeticsImageProviderWrapper ImageProviderWrapper;

};

