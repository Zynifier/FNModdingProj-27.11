// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "UObject/NoExportTypes.h"
#include "FortLockerConfig.generated.h"

class UCommonActivatableWidget;
class UFortLockerCategoryConfig;
class UFortLockerCategoryFilterConfig;
class UFortLockerCategoryGroupConfig;
class UFortLockerCategorySortConfig;
class UMaterialInstance;
class UTexture2D;
class UUserWidget;

UENUM(BlueprintType)
enum class EForLockerCategorySlotPriority : uint8
{
	Primary = 0,
	Secondary = 1,
	Tertiary = 2,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortLockerCategorySlotInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategorySlotInfo")
	FText CategoryName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategorySlotInfo")
	FText CategoryDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategorySlotInfo")
	EForLockerCategorySlotPriority Priority;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategorySlotInfo")
	TObjectPtr<UTexture2D> DefaultEmptyTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategorySlotInfo")
	TObjectPtr<UMaterialInstance> CategoryIcon;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortLockerCategoryConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	int32 Prority;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	int32 SortOrder;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	bool bShowIfEmpty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	bool bDisplayAsModal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	bool bAllowEmptySelection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	bool bCanApplyToAll;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	TSubclassOf<UUserWidget> CustomCategoryItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	TSubclassOf<UCommonActivatableWidget> CustomCategoryEditor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	FFortLockerCategorySlotInfo SlotInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryConfig")
	TArray<FFortLockerCategorySlotInfo> AdditionalSlotInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category="FortLockerCategoryConfig")
	TArray<UFortLockerCategorySortConfig*> SortConfigs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category="FortLockerCategoryConfig")
	TArray<UFortLockerCategoryFilterConfig*> FilterConfigs;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortLockerCategorySortFilterConfig : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortLockerCategorySortFilterConfig")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortLockerCategorySortFilterConfig")
	FSlateBrush Icon;

};

UCLASS(EditInlineNew, CollapseCategories, MinimalAPI, BlueprintType, Blueprintable)
class UFortLockerCategoryFilterConfig : public UFortLockerCategorySortFilterConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryFilterConfig")
	FText EmptyFilterDisplay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryFilterConfig")
	FText EmptyArchivedFilterDisplay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryFilterConfig")
	bool bAllowEmptySlotItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryFilterConfig")
	bool bAlwaysShowEquippedItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryFilterConfig")
	bool bIsArchiveFilter;

};

UCLASS(MinimalAPI)
class UFortLockerCategoryGroupConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryGroupConfig")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryGroupConfig")
	TObjectPtr<UTexture2D> DefaultEmptyTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryGroupConfig")
	TArray<TObjectPtr<UFortLockerCategoryConfig>> Categories;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryGroupConfig")
	int32 SortOrder;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLockerCategoryGroupConfig")
	float PriorityScale;

};

UCLASS(EditInlineNew, CollapseCategories, MinimalAPI, BlueprintType, Blueprintable)
class UFortLockerCategorySortConfig : public UFortLockerCategorySortFilterConfig
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortLockerConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortLockerConfig")
	TArray<TObjectPtr<UFortLockerCategoryGroupConfig>> CategoryGroups;

	UPROPERTY(EditDefaultsOnly, Category="FortLockerConfig")
	bool bAllowOverrides;

	UPROPERTY(EditDefaultsOnly, Category="FortLockerConfig")
	bool bAllowSorting;

};

