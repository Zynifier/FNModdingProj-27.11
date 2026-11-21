// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaSkyDiveContrailItemDefinition.generated.h"

class UFXSystemAsset;
class UNiagaraSystem;
class UParticleSystem;

USTRUCT()
struct FFloatParticleParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FloatParticleParameter")
	float Value;

	UPROPERTY(EditAnywhere, Category="FloatParticleParameter")
	FName ParameterName;

};

USTRUCT()
struct FVectorParticleParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VectorParticleParameter")
	FVector Value;

	UPROPERTY(EditAnywhere, Category="VectorParticleParameter")
	FName ParameterName;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaSkyDiveContrailItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Visual")
	UFXSystemAsset* GetContrailEffect(bool bInFrontend = false) const;

	UFUNCTION(BlueprintPure, Category="Visual")
	TSoftObjectPtr<UFXSystemAsset> GetContrailSoftPath(bool bInFrontend = false) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> ContrailEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> FrontEndContrailEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UNiagaraSystem> NiagaraContrailEffect;

	UPROPERTY(EditDefaultsOnly, Category="Frontend Preview")
	FVector DefaultVelocityVector;

	UPROPERTY(EditDefaultsOnly, Category="Frontend Preview")
	FName VelocityVectorParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Frontend Preview")
	FName ParaGlideLeanParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Frontend Preview")
	TArray<FVectorParticleParameter> VectorParameters;

	UPROPERTY(EditDefaultsOnly, Category="Frontend Preview")
	TArray<FFloatParticleParameter> FloatParameters;

	UPROPERTY(EditDefaultsOnly, Category="Frontend Preview")
	bool bWaitForFrontendSceneTransition;

};

