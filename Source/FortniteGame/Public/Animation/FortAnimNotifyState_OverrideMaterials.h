// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_OverrideMaterials.generated.h"

class UMaterialInterface;

USTRUCT()
struct FFortAnimNotifyMaterialOverride_MaterialPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyMaterialOverride_MaterialPair")
	TObjectPtr<UMaterialInterface> TargetMaterial;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyMaterialOverride_MaterialPair")
	TObjectPtr<UMaterialInterface> OverrideMaterial;

};

USTRUCT()
struct FFortAnimNotifyMaterialOverride_ScalarParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyMaterialOverride_ScalarParameter")
	TArray<TSoftObjectPtr<UMaterialInterface>> TargetMaterials;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyMaterialOverride_ScalarParameter")
	FName ParameterName;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyMaterialOverride_ScalarParameter")
	float ParameterValue;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object"), meta=(DisplayName="Override Materials"))
class UFortAnimNotifyState_OverrideMaterials : public UAnimNotifyState
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_OverrideMaterials")
	TArray<FFortAnimNotifyMaterialOverride_MaterialPair> MaterialOverrides;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_OverrideMaterials")
	TArray<FFortAnimNotifyMaterialOverride_ScalarParameter> BeginParameters;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_OverrideMaterials")
	TArray<FFortAnimNotifyMaterialOverride_ScalarParameter> EndParameters;

};

