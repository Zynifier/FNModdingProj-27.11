// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "FortHomebase/FortHomebaseTypes.h"
#include "FortBannerUtilities.generated.h"

class AFortPlayerController;
class UFortAccountItem;
class UFortHomebaseBannerColorItem;
class UFortHomebaseBannerIconItem;
class UFortHomebaseBannerIconItemDefinition;
class UTexture2D;
enum class EBannerUsageContext : uint8;

UCLASS()
class UFortBannerUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Banner")
	static FHomebaseBannerColor GetBannerColor(UFortHomebaseBannerColorItem* BannerColor);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FText GetBannerColorCategoryName(const FName& CategoryRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FName GetBannerColorCategoryRowName(const FName& BannerColorRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FHomebaseBannerColor GetBannerColorFromRowName(const FName& BannerColorRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static UFortHomebaseBannerColorItem* GetBannerColorItemFromRowName(AFortPlayerController* FortPC, const FName& BannerColorRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FLinearColor GetBannerColorPrimaryColor(const UFortHomebaseBannerColorItem* BannerColor);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FLinearColor GetBannerColorPrimaryColorFromRowName(const FName& BannerColorRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FLinearColor GetBannerColorSecondaryColor(const UFortHomebaseBannerColorItem* BannerColor);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FLinearColor GetBannerColorSecondaryColorFromRowName(const FName& BannerColorRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static void GetBannerColorsForCategory(AFortPlayerController* FortPC, const FName& CategoryRowName, TArray<UFortAccountItem*>& BannerColors);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static bool GetBannerFullUsageRightsFromRowName(const FName& BannerIconRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FText GetBannerIconCategoryName(const FName& CategoryRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FName GetBannerIconCategoryRowName(const FName& BannerIconRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static UFortHomebaseBannerIconItem* GetBannerIconItemFromRowName(AFortPlayerController* FortPC, const FName& BannerIconRowName);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static void GetBannerIconsForCategory(AFortPlayerController* FortPC, const FName& CategoryRowName, TArray<UFortAccountItem*>& BannerIcons);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static TSoftObjectPtr<UTexture2D> GetBannerLargeIconAsset(UFortHomebaseBannerIconItem* BannerIcon, EBannerUsageContext Usage);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static TSoftObjectPtr<UTexture2D> GetBannerLargeIconAssetFromRowName(const FName& BannerIconRowName, EBannerUsageContext Usage);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static TSoftObjectPtr<UTexture2D> GetBannerSmallIconAsset(UFortHomebaseBannerIconItem* BannerIcon, EBannerUsageContext Usage);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static TSoftObjectPtr<UTexture2D> GetBannerSmallIconAssetFromRowName(const FName& BannerIconRowName, EBannerUsageContext Usage);

	UFUNCTION(BlueprintPure, Category="Banner")
	static FLinearColor GetPrimaryColor(const FHomebaseBannerColor& BannerColor);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FName GetRowNameForBannerColorItem(UFortHomebaseBannerColorItem* BannerColor);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static FName GetRowNameForBannerIconItem(UFortHomebaseBannerIconItem* BannerIcon);

	UFUNCTION(BlueprintPure, Category="Banner")
	static FLinearColor GetSecondaryColor(const FHomebaseBannerColor& BannerColor);

	UFUNCTION(BlueprintCallable, Category="Banner")
	static TSoftObjectPtr<UFortHomebaseBannerIconItemDefinition> GetSoftBannerDefinitionFromLegacyName(const FName& BannerIconRowName);

};

