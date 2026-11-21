// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanelSlot.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "MobileHUDLayoutLegacyConverter.generated.h"

class UInstancedPropertyUpgradeMappingBase;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FWidgetLayoutProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WidgetLayoutProxy")
	FGameplayTag Key;

	UPROPERTY(EditAnywhere, Category="WidgetLayoutProxy")
	FAnchorData AnchorData;

	UPROPERTY(EditAnywhere, Category="WidgetLayoutProxy")
	FVector2D DefaultContentSize;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FWidgetMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WidgetMapping")
	FGameplayTagContainer KeyTags;

	UPROPERTY(EditAnywhere, Category="WidgetMapping")
	FGameplayTag ReplacementTag;

	UPROPERTY(EditAnywhere, Category="WidgetMapping")
	bool bUseLegacyTagAsBehavior;

	UPROPERTY(EditAnywhere, Category="WidgetMapping")
	FGameplayTagContainer AlternativeWidgetTags;

	UPROPERTY(EditAnywhere, Category="WidgetMapping")
	FGameplayTag ClassTag;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FWidgetMappingContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WidgetMappingContainer")
	FGameplayTag LegacyTag;

	UPROPERTY(EditAnywhere, Category="WidgetMappingContainer")
	FWidgetMapping DefaultMapping;

	UPROPERTY(EditAnywhere, Category="WidgetMappingContainer", meta=(TitleProperty="ContextTag"))
	TArray<FWidgetMapping> ContextMappings;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FWidgetPropertyUpgradeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WidgetPropertyUpgradeData")
	FGameplayTag Key;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="WidgetPropertyUpgradeData")
	TObjectPtr<UInstancedPropertyUpgradeMappingBase> InstancedPropertyData0;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="WidgetPropertyUpgradeData")
	TObjectPtr<UInstancedPropertyUpgradeMappingBase> InstancedPropertyData1;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="WidgetPropertyUpgradeData")
	TObjectPtr<UInstancedPropertyUpgradeMappingBase> InstancedPropertyData2;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="WidgetPropertyUpgradeData")
	TObjectPtr<UInstancedPropertyUpgradeMappingBase> InstancedPropertyData3;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="WidgetPropertyUpgradeData")
	TMap<FName, TObjectPtr<UInstancedPropertyUpgradeMappingBase>> InstancedFloatPropertyToTagPropertyMap;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FWidgetVisibilityOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WidgetVisibilityOverride")
	FGameplayTag Key;

	UPROPERTY(EditAnywhere, Category="WidgetVisibilityOverride")
	FGameplayTagContainer VisibleOverrides;

	UPROPERTY(EditAnywhere, Category="WidgetVisibilityOverride")
	FGameplayTagContainer AllowedOverrides;

	UPROPERTY(EditAnywhere, Category="WidgetVisibilityOverride")
	FGameplayTagContainer HideOverrides;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class UInstancedPropertyUpgradeMappingBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Default")
	FGameplayTag PropertyTag;

};

UCLASS()
class UInstancedPropertyUpgradeMapping_Flag : public UInstancedPropertyUpgradeMappingBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Default")
	int32 Index;

};

UCLASS()
class UInstancedPropertyUpgradeMapping_Float : public UInstancedPropertyUpgradeMappingBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Default")
	FVector2D LegacyRange;

	UPROPERTY(EditAnywhere, Category="Default")
	FVector2D Range;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UMobileHUDLayoutLegacyConverter : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="MobileHUDLayoutLegacyConverter")
	FText ConvertedProfiletName;

	UPROPERTY(EditDefaultsOnly, Category="MobileHUDLayoutLegacyConverter", meta=(TitleProperty="LegacyTag"))
	TMap<FGameplayTag, FGameplayTag> GlobalTagClassOverrides;

	UPROPERTY(EditDefaultsOnly, Category="MobileHUDLayoutLegacyConverter", meta=(TitleProperty="LegacyTag"))
	TArray<FWidgetMappingContainer> TagMappings;

	UPROPERTY(EditDefaultsOnly, Category="MobileHUDLayoutLegacyConverter", meta=(TitleProperty="Key"))
	TArray<FWidgetVisibilityOverride> VisibilityOverrides;

	UPROPERTY(EditDefaultsOnly, Category="MobileHUDLayoutLegacyConverter", meta=(TitleProperty="Key"))
	TArray<FWidgetPropertyUpgradeData> PropertyUpgradeMappings;

	UPROPERTY(EditDefaultsOnly, Category="MobileHUDLayoutLegacyConverter", meta=(TitleProperty="Key"))
	TArray<FWidgetLayoutProxy> WidgetLayoutProxies;

	UPROPERTY(EditDefaultsOnly, Category="MobileHUDLayoutLegacyConverter")
	FVector2D LegacyCanvasSize;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="MobileHUDLayoutLegacyConverter", meta=(TitleProperty="LegacyTag"))
	FGameplayTagContainer DebugTags;
#endif

};

