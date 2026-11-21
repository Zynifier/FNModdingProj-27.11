// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/NoExportTypes.h"
#include "ActorMetadata/FortActorMetadata.h"
#include "ObjectTracking/FortBudgetCategory.h"
#include "FortCreativeBudgeter.generated.h"

class AActor;
class UActorComponent;
class UCreativeAssetCostDirectory;
class UFortCreativeRealEstatePlotItemDefinition;
class UObject;

UENUM()
enum class ECreativeAssetCostFilterMethod : uint8
{
	IncludeOnly = 0,
	Exclude = 1,
};

USTRUCT()
struct FCreativeAssetMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 AssetSize;

private:
	UPROPERTY()
	FString StringObjectPtr_DEPRECATED;

	UPROPERTY()
	FName NameObjectPtr;

	UPROPERTY(Transient)
	TSoftObjectPtr<UObject> ObjectPtr;

};

USTRUCT()
struct FCreativeActorMemoryCost
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FCreativeAssetMetaData> AssetDependencies;

	UPROPERTY()
	int32 InstanceMemoryCost;

	UPROPERTY()
	int32 AssetMemoryCost;

	UPROPERTY()
	TSoftClassPtr<AActor> ActorId;

};

USTRUCT()
struct FCreativeActorMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="CreativeActorMetaData")
	int32 AssetSize;

	UPROPERTY(VisibleAnywhere, Category="CreativeActorMetaData")
	int32 InstanceSize;

	UPROPERTY(VisibleAnywhere, Category="CreativeActorMetaData")
	int32 SimulationCost;

	UPROPERTY(VisibleAnywhere, Category="CreativeActorMetaData")
	int32 DrawCall;

	UPROPERTY(VisibleAnywhere, Category="CreativeActorMetaData")
	int32 AudioCost;

	UPROPERTY(VisibleAnywhere, Category="CreativeActorMetaData")
	int32 NetworkCost;

	UPROPERTY(VisibleAnywhere, Category="CreativeActorMetaData")
	uint8 bCostOverridden : 1;

	UPROPERTY()
	TArray<FCreativeAssetMetaData> AssetDependencies;

};

USTRUCT()
struct FCreativeAssetCostFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CreativeAssetCostFilter")
	TArray<FName> PlaysetDefinitions;

	UPROPERTY(EditDefaultsOnly, Category="CreativeAssetCostFilter")
	ECreativeAssetCostFilterMethod Method;

};

USTRUCT()
struct FFortCreativeAssetCostData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FCreativeActorMetaData> MetaDataMap_DEPRECATED;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeAssetCostData")
	TMap<FName, FCreativeActorMetaData> NameMetaDataMap;

	UPROPERTY()
	FFortActorMetadata ActorMetadata_Legacy;

	UPROPERTY()
	FFortActorMetadata ActorMetadata;

};

USTRUCT(BlueprintType)
struct FFortCreativeBudget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 UsedBudget;

	UPROPERTY()
	int32 PreviewBudget;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeBudget")
	EFortBudgetCategory Category;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeBudget")
	bool bCritical;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeBudget")
	int32 BudgetLowend;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeBudget")
	int32 FixedInstanceCost;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeBudget")
	int32 EditMargin;

private:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeBudget")
	int32 TotalBudget;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeBudget")
	int32 StaticAssetCostTotalBudget;

};

USTRUCT()
struct FFortCreativeBudgetClassInstanceLimit
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName ActorClass;

	UPROPERTY(Config)
	int32 MaxNumberOfInstances;

};

USTRUCT()
struct FFortCreativeBudgetComponentSimulationCost
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TSoftClassPtr<UActorComponent> ComponentClass;

	UPROPERTY(Config)
	int32 SimulationCost;

};

USTRUCT()
struct FFortCreativeBudgetLinkedClassInstanceLimit
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName ActorClass;

	UPROPERTY(Config)
	FName LinkedActorClass;

};

USTRUCT()
struct FFortCreativeBudgetOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FString ActorClass;

	UPROPERTY(Config)
	int32 AssetCost;

	UPROPERTY(Config)
	float AssetCostMultiplier;

	UPROPERTY(Config)
	int32 InstanceCost;

	UPROPERTY(Config)
	float InstanceCostMultiplier;

	UPROPERTY(VisibleAnywhere, Category="FortCreativeBudgetOverride")
	int32 SimulationCost;

	UPROPERTY(VisibleAnywhere, Category="FortCreativeBudgetOverride")
	int32 DrawCall;

	UPROPERTY(VisibleAnywhere, Category="FortCreativeBudgetOverride")
	int32 AudioCost;

	UPROPERTY(VisibleAnywhere, Category="FortCreativeBudgetOverride")
	int32 NetworkCost;

};

USTRUCT()
struct FFortCreativeBudgetPickupInstanceLimit
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName ItemDefinition;

	UPROPERTY(Config)
	int32 MaxNumberOfInstances;

};

USTRUCT(BlueprintType)
struct FFortCreativeGridCellBudget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeGridCellBudget", meta=(ClampMin="0", UIMin="0"))
	int32 CellBudget;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeGridCellBudget", meta=(ClampMin="0", UIMin="0"))
	int32 CellBudgetEditMargin;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCreativeGridCellBudget")
	EFortBudgetCategory Category;

};

USTRUCT()
struct FFortCreativeBudgetPlotBudgetOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TSoftObjectPtr<UFortCreativeRealEstatePlotItemDefinition> PlotItemDefinitionClass;

	UPROPERTY(Config)
	TArray<FFortCreativeBudget> Budgets;

	UPROPERTY(Config)
	bool bCreativeHeatmapThermometerEnabled;

	UPROPERTY(Config)
	float CreativeHeatmapThermometerCellSize;

	UPROPERTY(Config)
	float CreativeHeatmapThermometerInfluenceDistanceMultiplier;

	UPROPERTY(Config)
	TArray<FFortCreativeGridCellBudget> CreativeHeatmapThermometerBudgetOverrides;

};

UCLASS(MinimalAPI)
class UCreativeAssetCostDirectory : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CreativeAssetCostDirectory")
	FFortCreativeAssetCostData CostDirectory;

	UPROPERTY(VisibleAnywhere, Category="CreativeAssetCostDirectory")
	TMap<FString, int32> ComponentSimulationCostDirectory;

	UPROPERTY(EditDefaultsOnly, Category="CreativeAssetCostDirectory")
	FCreativeAssetCostFilter AssetFilter;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Transient, Category="SaveOptions")
	FString OptionalFullCSVSavePath;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="SaveOptions")
	EFortActorTemplateCostUpdateMethod CostUpdateMethod;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Transient, Category="SaveOptions")
	bool bPressToGenerateCSVNow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Transient, Category="SaveOptions")
	TArray<FString> ObjectsToRemoveFromCostDirectory;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Transient, Category="SaveOptions")
	bool bPressToRemoveAssetFromCostDirectoryNow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Transient, Category="SaveOptions")
	TSoftObjectPtr<UCreativeAssetCostDirectory> PreviousAssetCostDirectory;
#endif

};

UCLASS(Config=Game, DefaultConfig, MinimalAPI)
class UFortCreativeBudgeterData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TArray<FFortCreativeBudgetOverride> CostOverrides;

	UPROPERTY(Config)
	TArray<FFortCreativeBudgetClassInstanceLimit> TransientClassLimits;

	UPROPERTY(Config)
	TArray<FFortCreativeBudgetPickupInstanceLimit> TransientPickupLimits;

	UPROPERTY(Config)
	TArray<FFortCreativeBudgetClassInstanceLimit> SavedClassLimits;

	UPROPERTY(Config)
	TArray<FFortCreativeBudgetLinkedClassInstanceLimit> LinkedClassLimits;

	UPROPERTY(Config)
	TArray<FFortCreativeBudgetComponentSimulationCost> ComponentSimulationCosts;

	UPROPERTY(Config)
	TArray<FFortCreativeBudget> Budgets;

	UPROPERTY(Config)
	TArray<FFortCreativeBudgetPlotBudgetOverride> PlotBudgetOverrides;

	UPROPERTY(Config)
	bool bEnableInstanceTracking;

};

