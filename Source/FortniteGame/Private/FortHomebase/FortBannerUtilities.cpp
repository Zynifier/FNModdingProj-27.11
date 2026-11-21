// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortHomebase/FortBannerUtilities.h"

FHomebaseBannerColor UFortBannerUtilities::GetBannerColor(UFortHomebaseBannerColorItem* BannerColor)
{
	return FHomebaseBannerColor();
}

FText UFortBannerUtilities::GetBannerColorCategoryName(const FName& CategoryRowName)
{
	return FText();
}

FName UFortBannerUtilities::GetBannerColorCategoryRowName(const FName& BannerColorRowName)
{
	return FName();
}

FHomebaseBannerColor UFortBannerUtilities::GetBannerColorFromRowName(const FName& BannerColorRowName)
{
	return FHomebaseBannerColor();
}

UFortHomebaseBannerColorItem* UFortBannerUtilities::GetBannerColorItemFromRowName(AFortPlayerController* FortPC, const FName& BannerColorRowName)
{
	return nullptr;
}

FLinearColor UFortBannerUtilities::GetBannerColorPrimaryColor(const UFortHomebaseBannerColorItem* BannerColor)
{
	return FLinearColor();
}

FLinearColor UFortBannerUtilities::GetBannerColorPrimaryColorFromRowName(const FName& BannerColorRowName)
{
	return FLinearColor();
}

FLinearColor UFortBannerUtilities::GetBannerColorSecondaryColor(const UFortHomebaseBannerColorItem* BannerColor)
{
	return FLinearColor();
}

FLinearColor UFortBannerUtilities::GetBannerColorSecondaryColorFromRowName(const FName& BannerColorRowName)
{
	return FLinearColor();
}

void UFortBannerUtilities::GetBannerColorsForCategory(AFortPlayerController* FortPC, const FName& CategoryRowName, TArray<UFortAccountItem*>& BannerColors)
{
}

bool UFortBannerUtilities::GetBannerFullUsageRightsFromRowName(const FName& BannerIconRowName)
{
	return false;
}

FText UFortBannerUtilities::GetBannerIconCategoryName(const FName& CategoryRowName)
{
	return FText();
}

FName UFortBannerUtilities::GetBannerIconCategoryRowName(const FName& BannerIconRowName)
{
	return FName();
}

UFortHomebaseBannerIconItem* UFortBannerUtilities::GetBannerIconItemFromRowName(AFortPlayerController* FortPC, const FName& BannerIconRowName)
{
	return nullptr;
}

void UFortBannerUtilities::GetBannerIconsForCategory(AFortPlayerController* FortPC, const FName& CategoryRowName, TArray<UFortAccountItem*>& BannerIcons)
{
}

TSoftObjectPtr<UTexture2D> UFortBannerUtilities::GetBannerLargeIconAsset(UFortHomebaseBannerIconItem* BannerIcon, EBannerUsageContext Usage)
{
	return TSoftObjectPtr<UTexture2D>();
}

TSoftObjectPtr<UTexture2D> UFortBannerUtilities::GetBannerLargeIconAssetFromRowName(const FName& BannerIconRowName, EBannerUsageContext Usage)
{
	return TSoftObjectPtr<UTexture2D>();
}

TSoftObjectPtr<UTexture2D> UFortBannerUtilities::GetBannerSmallIconAsset(UFortHomebaseBannerIconItem* BannerIcon, EBannerUsageContext Usage)
{
	return TSoftObjectPtr<UTexture2D>();
}

TSoftObjectPtr<UTexture2D> UFortBannerUtilities::GetBannerSmallIconAssetFromRowName(const FName& BannerIconRowName, EBannerUsageContext Usage)
{
	return TSoftObjectPtr<UTexture2D>();
}

FLinearColor UFortBannerUtilities::GetPrimaryColor(const FHomebaseBannerColor& BannerColor)
{
	return FLinearColor();
}

FName UFortBannerUtilities::GetRowNameForBannerColorItem(UFortHomebaseBannerColorItem* BannerColor)
{
	return FName();
}

FName UFortBannerUtilities::GetRowNameForBannerIconItem(UFortHomebaseBannerIconItem* BannerIcon)
{
	return FName();
}

FLinearColor UFortBannerUtilities::GetSecondaryColor(const FHomebaseBannerColor& BannerColor)
{
	return FLinearColor();
}

TSoftObjectPtr<UFortHomebaseBannerIconItemDefinition> UFortBannerUtilities::GetSoftBannerDefinitionFromLegacyName(const FName& BannerIconRowName)
{
	return TSoftObjectPtr<UFortHomebaseBannerIconItemDefinition>();
}
