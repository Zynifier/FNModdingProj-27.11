// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Styling/SlateBrush.h"
#include "FortRarityData.h"
#include "FortItemDetailsVM.generated.h"

class UFortItemVM;
class UMaterialInterface;
class UTexture2D;

UENUM(BlueprintType)
enum class EItemAccessRestriction : uint8
{
	UnsatisfiedExclusiveItem = 0,
	LockedEmote = 1,
	CosmeticRestrictions = 2,
	AllArchived = 3,
	RatingGated = 4,
	Unknown = 5,
};

UCLASS(Abstract)
class UFortItemDetailsVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortItemVM> Item;

	UPROPERTY(BlueprintReadWrite, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	FText DisplayName;

	UPROPERTY(BlueprintReadWrite, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	FText ItemDescription;

	UPROPERTY(BlueprintReadWrite, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	FText ItemShortDescription;

	UPROPERTY(BlueprintReadWrite, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	FText ItemRichDescription;

	UPROPERTY(BlueprintReadWrite, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	FText ItemCategoryName;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	FText AccessRestrictionDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	bool bHasAccessRestriction;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	EItemAccessRestriction AccessRestrictionType;

	UPROPERTY(BlueprintReadWrite, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	bool bShouldShowRarity;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	FText RarityDisplayText;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	FFortColorPalette RarityColorPalette;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	bool bIsSeriesItem;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UMaterialInterface> SeriesItemCardMaterial;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UMaterialInterface> SeriesBackgroundMaterial;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UTexture2D> SeriesBackgroundTexture;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UTexture2D> InactivePreviewImage;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UTexture2D> WidePreviewImage;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UTexture2D> LargePreviewImage;

	UPROPERTY(BlueprintReadWrite, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	bool bShouldShowClass;

	UPROPERTY(BlueprintReadWrite, Category="FortItemDetailsVM", meta=(AllowPrivateAccess))
	FSlateBrush ClassIcon;

};

