// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "FortItemCardConfigurationData.generated.h"

class UCommonTextStyle;

USTRUCT(BlueprintType)
struct FFortItemCard_DefenderWeaponTypeIcon_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_DefenderWeaponTypeIcon_Configuration")
	FVector2D IconConstraints;

};

USTRUCT(BlueprintType)
struct FFortItemCard_DetailAreaBorder_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_DetailAreaBorder_Configuration")
	float MinimumHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_DetailAreaBorder_Configuration")
	FMargin Padding;

};

USTRUCT(BlueprintType)
struct FFortItemCard_DurabilityMeter_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_DurabilityMeter_Configuration")
	float MeterThickness;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_DurabilityMeter_Configuration")
	FMargin MeterPadding;

};

USTRUCT(BlueprintType)
struct FFortItemCard_PowerRatingBlock_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_Configuration")
	FSlateBrush MoonbeamBorderBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_Configuration")
	FMargin MoonbeamBorderExteriorPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_Configuration")
	FMargin MoonbeamBorderPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_Configuration")
	FMargin CustomRatingInternalPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_Configuration")
	FVector2D CustomRatingIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_Configuration", meta=(AssetBundles="Client"))
	TSoftClassPtr<UCommonTextStyle> CustomRatingTextStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_Configuration")
	FVector2D ComparisonIndicatorSize;

};

USTRUCT(BlueprintType)
struct FFortItemCard_PowerRatingBlock_ItemInstance_Configuration : public FFortItemCard_PowerRatingBlock_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_ItemInstance_Configuration")
	FSlateBrush PowerRatingIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_ItemInstance_Configuration", meta=(AssetBundles="Client"))
	TSoftClassPtr<UCommonTextStyle> PowerRatingTextStyle;

};

USTRUCT(BlueprintType)
struct FFortItemCard_StackCountBlock_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_StackCountBlock_Configuration")
	bool bShowShorthandStackCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_StackCountBlock_Configuration", meta=(AssetBundles="Client"))
	TSoftClassPtr<UCommonTextStyle> TextStyle;

};

USTRUCT(BlueprintType)
struct FFortItemCard_TierMeter_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_TierMeter_Configuration")
	FVector2D PipSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_TierMeter_Configuration")
	float InterPipPadding;

};

USTRUCT(BlueprintType)
struct FFortItemCard_L_ItemInstance_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FMargin PowerRatingBlockPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FFortItemCard_PowerRatingBlock_ItemInstance_Configuration PowerRatingBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FMargin TraitBoxPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FVector2D FirstTraitSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	float PaddingBetweenTraitIcons;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FVector2D SecondTraitSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FMargin TierMeterPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FFortItemCard_TierMeter_Configuration TierMeter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_ItemInstance_Configuration")
	FFortItemCard_DurabilityMeter_Configuration DurabilityMeter;

};

USTRUCT(BlueprintType)
struct FFortItemCard_LevelMeter_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_LevelMeter_Configuration")
	float MeterThickness;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_LevelMeter_Configuration")
	FMargin MeterPadding;

};

USTRUCT(BlueprintType)
struct FFortItemCard_NameplateBorder_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_NameplateBorder_Configuration")
	FMargin Padding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_NameplateBorder_Configuration")
	FSlateBrush Brush;

};

USTRUCT(BlueprintType)
struct FFortItemCard_PowerRatingBlock_PersonnelAndSchematics_Configuration : public FFortItemCard_PowerRatingBlock_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_PersonnelAndSchematics_Configuration")
	FSlateBrush PersonnelPowerRatingIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_PersonnelAndSchematics_Configuration", meta=(AssetBundles="Client"))
	TSoftClassPtr<UCommonTextStyle> PersonnelPowerRatingTextStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_PersonnelAndSchematics_Configuration")
	FSlateBrush SchematicPowerRatingIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_PowerRatingBlock_PersonnelAndSchematics_Configuration", meta=(AssetBundles="Client"))
	TSoftClassPtr<UCommonTextStyle> SchematicPowerRatingTextStyle;

};

USTRUCT(BlueprintType)
struct FFortItemCard_L_PersonnelAndSchematics_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FFortItemCard_PowerRatingBlock_PersonnelAndSchematics_Configuration PowerRatingBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FFortItemCard_NameplateBorder_Configuration Nameplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FVector2D ClassIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FVector2D LeadSurvivorTypeIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FVector2D FirstIconSlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	float PaddingBetweenIconSlots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FVector2D SecondIconSlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FFortItemCard_DefenderWeaponTypeIcon_Configuration DefenderWeaponTypeIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FFortItemCard_DetailAreaBorder_Configuration DetailAreaBorder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FFortItemCard_LevelMeter_Configuration LevelMeter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	float TierMeterLeftPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_PersonnelAndSchematics_Configuration")
	FFortItemCard_TierMeter_Configuration TierMeter;

};

USTRUCT(BlueprintType)
struct FFortItemCard_L_TransformKey_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_TransformKey_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_TransformKey_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_L_TransformKey_Configuration")
	FVector2D TransformKeyIconSize;

};

USTRUCT(BlueprintType)
struct FFortItemCard_M_ItemInstance_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FMargin PowerRatingBlockPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FFortItemCard_PowerRatingBlock_ItemInstance_Configuration PowerRatingBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FMargin TraitBoxPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FVector2D FirstTraitSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	float PaddingBetweenTraitIcons;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FVector2D SecondTraitSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FMargin TierMeterPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FFortItemCard_TierMeter_Configuration TierMeter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_ItemInstance_Configuration")
	FFortItemCard_DurabilityMeter_Configuration DurabilityMeter;

};

USTRUCT(BlueprintType)
struct FFortItemCard_M_PersonnelAndSchematics_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FFortItemCard_PowerRatingBlock_PersonnelAndSchematics_Configuration PowerRatingBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FFortItemCard_NameplateBorder_Configuration Nameplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FVector2D ClassIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FVector2D LeadSurvivorTypeIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FVector2D FirstIconSlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	float PaddingBetweenIconSlots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FVector2D SecondIconSlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FFortItemCard_DefenderWeaponTypeIcon_Configuration DefenderWeaponTypeIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FFortItemCard_DetailAreaBorder_Configuration DetailAreaBorder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FFortItemCard_LevelMeter_Configuration LevelMeter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	float TierMeterLeftPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_PersonnelAndSchematics_Configuration")
	FFortItemCard_TierMeter_Configuration TierMeter;

};

USTRUCT(BlueprintType)
struct FFortItemCard_M_TransformKey_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_TransformKey_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_TransformKey_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_M_TransformKey_Configuration")
	FVector2D TransformKeyIconSize;

};

USTRUCT(BlueprintType)
struct FFortItemCard_S_ItemInstance_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FMargin PowerRatingBlockPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FFortItemCard_PowerRatingBlock_ItemInstance_Configuration PowerRatingBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FMargin TraitBoxPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FVector2D FirstTraitSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FMargin TierMeterPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FFortItemCard_TierMeter_Configuration TierMeter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_ItemInstance_Configuration")
	FFortItemCard_DurabilityMeter_Configuration DurabilityMeter;

};

USTRUCT(BlueprintType)
struct FFortItemCard_S_PersonnelAndSchematics_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FFortItemCard_PowerRatingBlock_PersonnelAndSchematics_Configuration PowerRatingBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FFortItemCard_NameplateBorder_Configuration Nameplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FVector2D ClassIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FVector2D LeadSurvivorTypeIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FVector2D FirstIconSlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	float PaddingBetweenIconSlots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FVector2D SecondIconSlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FFortItemCard_DefenderWeaponTypeIcon_Configuration DefenderWeaponTypeIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FFortItemCard_DetailAreaBorder_Configuration DetailAreaBorder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FFortItemCard_LevelMeter_Configuration LevelMeter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	float TierMeterLeftPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_PersonnelAndSchematics_Configuration")
	FFortItemCard_TierMeter_Configuration TierMeter;

};

USTRUCT(BlueprintType)
struct FFortItemCard_S_TransformKey_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_TransformKey_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_TransformKey_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_S_TransformKey_Configuration")
	FVector2D TransformKeyIconSize;

};

USTRUCT(BlueprintType)
struct FFortItemCard_XL_ItemInstance_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FMargin PowerRatingBlockPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FFortItemCard_PowerRatingBlock_ItemInstance_Configuration PowerRatingBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FMargin TraitBoxPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FVector2D FirstTraitSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	float PaddingBetweenTraitIcons;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FVector2D SecondTraitSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FMargin TierMeterPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FFortItemCard_TierMeter_Configuration TierMeter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_ItemInstance_Configuration")
	FFortItemCard_DurabilityMeter_Configuration DurabilityMeter;

};

USTRUCT(BlueprintType)
struct FFortItemCard_XL_PersonnelAndSchematics_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FFortItemCard_PowerRatingBlock_PersonnelAndSchematics_Configuration PowerRatingBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FFortItemCard_NameplateBorder_Configuration Nameplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration", meta=(AssetBundles="Client"))
	TSoftClassPtr<UCommonTextStyle> ItemNameTextStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FVector2D LeadSurvivorTypeIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FVector2D FirstIconSlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	float PaddingBetweenIconSlots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FVector2D SecondIconSlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FFortItemCard_DefenderWeaponTypeIcon_Configuration DefenderWeaponTypeIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FFortItemCard_DetailAreaBorder_Configuration DetailAreaBorder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	float RarityNameTextLeftPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration", meta=(AssetBundles="Client"))
	TSoftClassPtr<UCommonTextStyle> RarityNameTextStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	float ClassIconImageLeftPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FVector2D ClassIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	float PaddingBetweenClassIconAndName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration", meta=(AssetBundles="Client"))
	TSoftClassPtr<UCommonTextStyle> ClassNameTextStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	float TierMeterLeftPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FFortItemCard_TierMeter_Configuration TierMeter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FMargin IconSlotOverNameplatePadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_PersonnelAndSchematics_Configuration")
	FVector2D IconSlotOverNameplateSize;

};

USTRUCT(BlueprintType)
struct FFortItemCard_XL_TransformKey_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_TransformKey_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_TransformKey_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XL_TransformKey_Configuration")
	FVector2D TransformKeyIconSize;

};

USTRUCT(BlueprintType)
struct FFortItemCard_XS_ItemInstance_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_ItemInstance_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_ItemInstance_Configuration")
	FMargin PowerRatingBlockPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_ItemInstance_Configuration")
	FFortItemCard_PowerRatingBlock_ItemInstance_Configuration PowerRatingBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_ItemInstance_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_ItemInstance_Configuration")
	FMargin TraitBoxPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_ItemInstance_Configuration")
	FVector2D FirstTraitSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_ItemInstance_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_ItemInstance_Configuration")
	FFortItemCard_DurabilityMeter_Configuration DurabilityMeter;

};

USTRUCT(BlueprintType)
struct FFortItemCard_XS_PersonnelAndSchematics_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_PersonnelAndSchematics_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_PersonnelAndSchematics_Configuration")
	FVector2D BookmarkImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_PersonnelAndSchematics_Configuration")
	FFortItemCard_DetailAreaBorder_Configuration DetailAreaBorder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_PersonnelAndSchematics_Configuration")
	FVector2D AvailableUpgradeIconSize;

};

USTRUCT(BlueprintType)
struct FFortItemCard_XS_TransformKey_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_TransformKey_Configuration")
	FMargin BackgroundPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_TransformKey_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XS_TransformKey_Configuration")
	FVector2D TransformKeyIconSize;

};

USTRUCT(BlueprintType)
struct FFortItemCard_XXS_ItemInstance_Configuration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCard_XXS_ItemInstance_Configuration")
	FFortItemCard_StackCountBlock_Configuration StackCountBlock;

};

