// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "TempestLightningComponent.generated.h"

class AActor;
class AFortGameplayEffectDeliveryActor;
class AFortPawn;
class UEnvQuery;
class UGameplayEffect;
class UTargetingPreset;

USTRUCT()
struct FTempestLightningBoltData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPawn> SourcePawn;

	UPROPERTY()
	TObjectPtr<AFortGameplayEffectDeliveryActor> LightningBolt;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> TargetActors;

	UPROPERTY()
	TArray<TObjectPtr<AFortPawn>> TargetPawns;

};

USTRUCT(BlueprintType)
struct FTempestLightningBoltEffectContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TempestLightningBoltEffectContainer")
	FGameplayTagQuery TargetFilter;

	UPROPERTY(EditDefaultsOnly, Category="TempestLightningBoltEffectContainer")
	TSubclassOf<UGameplayEffect> GameplayEffect;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Tempest"), meta=(BlueprintSpawnableComponent))
class SUPERSTORMRUNTIME_API UTempestLightningComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UTempestLightningComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	float GetCloudHeight() const;

	UFUNCTION(BlueprintPure)
	float GetLightningRadius() const;

private:
	UPROPERTY(EditAnywhere, Category="Lightning")
	TSubclassOf<AFortGameplayEffectDeliveryActor> LightningBoltClass;

	UPROPERTY(EditAnywhere, Category="Lightning")
	TArray<FTempestLightningBoltEffectContainer> LightningBoltTargetEffectContainers;

	UPROPERTY(EditAnywhere, Category="Lightning | Targeting")
	TObjectPtr<UTargetingPreset> LightningBoltTargetingPreset;

	UPROPERTY(EditAnywhere, Category="Lightning | Targeting")
	TObjectPtr<UEnvQuery> FindTargetablePawnsQuery;

	UPROPERTY(EditAnywhere, Category="Lightning | Targeting")
	TObjectPtr<UEnvQuery> FindTargetableLocationQuery;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Lightning | Targeting")
	FName EnvironmentQueryParamName_LightningRadius;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Lightning | Targeting")
	FName EnvironmentQueryParamName_MinLightningTargetDistance;

	UPROPERTY(EditAnywhere, Category="Lightning | Targeting")
	FScalableFloat LightningCloudHeight;

	UPROPERTY(EditAnywhere, Category="Lightning | Targeting")
	FScalableFloat LightningRadius;

	UPROPERTY(EditAnywhere, Category="Lightning | Targeting")
	FScalableFloat MinLightningTargetDistance;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningFrequencyMin;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningFrequencyMax;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningBoltsMin;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningBoltsMax;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningBoltIntervalMin;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningBoltIntervalMax;

	UPROPERTY(EditAnywhere, Category="Lightning | Targeting")
	FScalableFloat LightningBoltSeparationDistance;

	UPROPERTY(EditAnywhere, Category="Lightning | Targeting")
	FScalableFloat LightningStruckPawnReselectionInterval;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningBoltTelegraphDuration;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningBoltImpactIgnitionRadius;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningBoltGrassIgnitionRadius;

	UPROPERTY(EditAnywhere, Category="Lightning")
	FScalableFloat LightningBoltGrassFirePropagationFuel;

	UPROPERTY(EditAnywhere, Category="Lightning | Gameplay Cues", meta=(Categories="GameplayCue"))
	FGameplayTag LightningAreaTargetTelegraphCue;

	UPROPERTY(EditAnywhere, Category="Lightning | Gameplay Cues", meta=(Categories="GameplayCue"))
	FGameplayTag LightningBoltTargetTelegraphCue;

	UPROPERTY(Transient)
	TArray<FTempestLightningBoltData> LightningBoltData;

};

