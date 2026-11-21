// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "Components/FortTaggedNavFiltersComponent.h"
#include "FortInteractInterface.h"
#include "FortAthenaAISpawnerDataComponent_GameplayBase.generated.h"

class APawn;
class UFortAbilitySet;

USTRUCT(BlueprintType)
struct FPickupTagConvertInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parameter")
	FGameplayTagContainer PickupTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parameter")
	FScalableFloat ConvertDamage;

};

USTRUCT()
struct FTeleportSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TeleportSettings")
	FScalableFloat CheckTeleportConditionsTimeInterval;

	UPROPERTY(EditAnywhere, Category="TeleportSettings")
	float TeleportRange;

	UPROPERTY(EditAnywhere, Category="TeleportSettings", meta=(ClampMin="0.0", UIMin="0.0"))
	float TimeNeededOutsideTeleportRange;

	UPROPERTY(EditAnywhere, Category="TeleportSettings")
	FGameplayTag TeleportAbilityTag;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAthenaAIRuntimeParameters_AIConvert : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetCanBeConverted() const;

	UFUNCTION(BlueprintPure)
	bool GetCanBeConvertedFromDBNO() const;

	UFUNCTION(BlueprintPure)
	bool GetForceKillWhenConverterDies() const;

	UFUNCTION(BlueprintPure)
	bool GetForceKillWhenUnconverted() const;

	UFUNCTION(BlueprintPure)
	const TArray<FPickupTagConvertInfo>& GetPickupTagConvertInfos() const;

	UFUNCTION(BlueprintCallable)
	void SetCanBeConverted(const bool bInCanBeConverted);

	UFUNCTION(BlueprintCallable)
	void SetCanBeConvertedFromDBNO(const bool bInCanBeConvertedFromDBNO);

	UFUNCTION(BlueprintCallable)
	void SetForceKillWhenConverterDies(const bool bInForceKillWhenConverterDies);

	UFUNCTION(BlueprintCallable)
	void SetForceKillWhenUnconverted(const bool bInForceKillWhenUnconverted);

private:
	UPROPERTY(Transient)
	bool bCanBeConverted;

	UPROPERTY(Transient)
	bool bCanBeConvertedFromDBNO;

	UPROPERTY(Transient)
	bool bForceKillWhenUnconverted;

	UPROPERTY(Transient)
	bool bForceKillWhenConverterDies;

	UPROPERTY(Transient)
	bool bCopyConverterSpecificRelations;

	UPROPERTY(Transient)
	bool bRemoveFromAllFactions;

	UPROPERTY(Transient)
	bool bAddConverterFactions;

	UPROPERTY(Transient)
	float ReleaseDistanceSq;

	UPROPERTY(Transient)
	float CheckReleaseConditionsTimeInterval;

	UPROPERTY(Transient)
	FGameplayTagContainer AddToFactions;

	UPROPERTY(Transient)
	FGameplayTagContainer RemoveFromFactions;

	UPROPERTY(Transient)
	uint8 PreConversionTeamIndex;

	UPROPERTY(Transient)
	FGameplayTagContainer PreConversionFactions;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAbilitySet>> AbilitySetsForConverted;

	UPROPERTY(Transient)
	FTeleportSettings TeleportSettings;

	UPROPERTY(Transient)
	bool bEnableDBNO;

	UPROPERTY(Transient)
	TEnumAsByte<TInteractionType> DBNOInteractionType;

	UPROPERTY(Transient)
	float DBNOInteractionDuration;

	UPROPERTY(Transient)
	TArray<FPickupTagConvertInfo> PickupTagConvertInfos;

	UPROPERTY(Transient)
	FGameplayTag ConvertIdentifierTag;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_GameplayBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	float GetGlobalSpeedMultiplier() const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnSpawned"))
	void PostOnSpawnedBP(APawn* PawnAI) const;

	UFUNCTION(BlueprintCallable)
	void SetCanBeConverted(const bool bInCanBeConverted);

	UFUNCTION(BlueprintCallable)
	void SetCopyConverterSpecificRelations(const bool bInCopyConverterSpecificRelations);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool ShouldOverrideGlobalSpeedMultiplier() const;

private:
	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	bool bOverrideGlobalSpeedMultiplier;

	UPROPERTY(EditAnywhere, Category="Movement", meta=(AllowPrivateAccess="true", EditCondition="bOverrideGlobalSpeedMultiplier"))
	FScalableFloat GlobalSpeedMultiplier;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanBeConverted;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanBeConvertedFromDBNO;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat ForceKillWhenUnconverted;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat ForceKillWhenConverterDies;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat CopyConverterSpecificRelations;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat RemoveFromAllFactions;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat AddConverterFactions;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat ReleaseDistance;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat CheckReleaseConditionsTimeInterval;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer AddToFactions;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer RemoveFromFactions;

	UPROPERTY(EditAnywhere, Category="Relevancy", meta=(AllowPrivateAccess="true"))
	FScalableFloat PawnCullDistance;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UFortAbilitySet>> AbilitySetsForConverted;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FTeleportSettings TeleportSettings;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	bool bApplyTaggedNavFilters;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true", EditCondition="bApplyTaggedNavFilters", EditConditionHides))
	FFortAITaggedNavFilterData NavFilterData;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	bool bEnableDBNO;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true", EditCondition="bEnableDBNO", EditConditionHides))
	TEnumAsByte<TInteractionType> DBNOInteractionType;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true", EditCondition="bEnableDBNO", EditConditionHides))
	float DBNOInteractionDuration;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	bool bOnlyLeaderInteraction;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FGameplayTag ConvertIdentifierTag;

	UPROPERTY(EditAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	bool bCanSleep;

	UPROPERTY(EditAnywhere, Category="AI", meta=(AllowPrivateAccess="true", EditCondition="bCanSleep", EditConditionHides))
	FGameplayTagQuery SleepForTheseGoalActors;

};

