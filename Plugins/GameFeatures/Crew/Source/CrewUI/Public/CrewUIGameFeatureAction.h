// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "CrewUIGameFeatureAction.generated.h"

class UBattlePassCrewPurchaseContainer;
class UCrewMultiSubscriptionAlertModal;
class UCrewPriceChangeAcknowledgeModal;
class UCrewPurchaseScreen;
class UCrewStandaloneSubscriptionContentContainer;
class UCrewSubscriptionContentContainer;
class UFortItemDefinition;
class UFortProgressiveContentContainer;
class UFortTemporaryItemsScreen;
class UMaterialInterface;

USTRUCT(BlueprintType)
struct FFortProgressiveReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortProgressiveReward")
	TArray<FCosmeticVariantInfo> DefaultVariantPreviewOverrides;

	UPROPERTY(EditAnywhere, Category="FortProgressiveReward")
	TSoftObjectPtr<UMaterialInterface> TileMaterial;

	UPROPERTY(EditAnywhere, Category="FortProgressiveReward")
	bool bHidden;

	UPROPERTY(EditAnywhere, Category="FortProgressiveReward")
	bool bAllowPreviewStyles;

private:
	UPROPERTY(EditAnywhere, Category="FortProgressiveReward")
	TSoftObjectPtr<UFortItemDefinition> RewardDef;

};

USTRUCT(BlueprintType)
struct FFortProgressiveStageOverrideDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortProgressiveStageOverrideDisplayData")
	TArray<FCosmeticVariantInfo> DefaultVariantPreviewOverrides;

	UPROPERTY(EditAnywhere, Category="FortProgressiveStageOverrideDisplayData")
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="FortProgressiveStageOverrideDisplayData")
	TSoftObjectPtr<UMaterialInterface> TileMaterial;

	UPROPERTY(EditAnywhere, Category="FortProgressiveStageOverrideDisplayData")
	bool bAllowPreviewStyles;

};

USTRUCT(BlueprintType)
struct FFortProgressiveUIStage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Unlocking Items")
	TArray<FFortProgressiveReward> Rewards;

	UPROPERTY(EditAnywhere, Category="FortProgressiveUIStage")
	bool bUseOverrideDisplayData;

	UPROPERTY(EditAnywhere, Category="FortProgressiveUIStage", meta=(EditCondition="bUseOverrideDisplayData"))
	FFortProgressiveStageOverrideDisplayData OverrideDisplayData;

};

USTRUCT(BlueprintType)
struct FFortProgressiveSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortProgressiveSet")
	FString FulfillmentId;

	UPROPERTY(EditAnywhere, Category="FortProgressiveSet")
	FText SetName;

	UPROPERTY(EditAnywhere, Category="FortProgressiveSet")
	TSoftObjectPtr<UMaterialInterface> TileMaterial;

	UPROPERTY(EditAnywhere, Category="FortProgressiveSet")
	TArray<FFortProgressiveUIStage> Stages;

};

UCLASS(MinimalAPI, meta=(DisplayName="Crew UI Action"))
class UCrewUIGameFeatureAction : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="CrewUIGameFeatureAction", meta=(AssetBundles="MenuAthena"))
	TSoftClassPtr<UBattlePassCrewPurchaseContainer> BattlePassCrewContainerClass;

	UPROPERTY(EditAnywhere, Category="CrewUIGameFeatureAction", meta=(AssetBundles="MenuAthena"))
	TSoftClassPtr<UCrewSubscriptionContentContainer> CrewContentContainerClass;

	UPROPERTY(EditAnywhere, Category="CrewUIGameFeatureAction", meta=(AssetBundles="MenuAthena"))
	TSoftClassPtr<UCrewStandaloneSubscriptionContentContainer> CrewStandaloneContentContainerClass;

	UPROPERTY(EditAnywhere, Category="CrewUIGameFeatureAction", meta=(AssetBundles="MenuAthena, ZoneAthena"))
	TSoftClassPtr<UCrewPurchaseScreen> CrewPurchaseScreenClass;

	UPROPERTY(EditAnywhere, Category="CrewUIGameFeatureAction", meta=(AssetBundles="MenuAthena, ZoneAthena"))
	TSoftClassPtr<UFortProgressiveContentContainer> ProgressionScreenClass;

	UPROPERTY(EditAnywhere, Category="CrewUIGameFeatureAction", meta=(AssetBundles="MenuAthena, ZoneAthena"))
	TSoftClassPtr<UFortTemporaryItemsScreen> TemporaryItemsScreenClass;

	UPROPERTY(EditAnywhere, Category="CrewUIGameFeatureAction", meta=(AssetBundles="MenuAthena"))
	TSoftClassPtr<UCrewPriceChangeAcknowledgeModal> CrewPriceChangeAcknowledgeModalClass;

	UPROPERTY(EditAnywhere, Category="CrewUIGameFeatureAction", meta=(AssetBundles="MenuAthena"))
	TSoftClassPtr<UCrewMultiSubscriptionAlertModal> MultiSubAlertModalClass;

	UPROPERTY(EditDefaultsOnly, Category="CrewUIGameFeatureAction")
	TArray<FFortProgressiveSet> ProgressiveCosmeticSets;

};

