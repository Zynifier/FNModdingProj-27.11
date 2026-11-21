// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortArmoryScreen.generated.h"

class UFortCampaignHeroLoadoutItem;
class UFortItem;
class UFortItemTileView;
enum class EFortFrontendInventoryFilter : uint8;
enum class EFortItemInspectionMode : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UFortArmoryScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Utility")
	void PushHeroLoadoutScreen(UFortCampaignHeroLoadoutItem* HeroLoadout);

	UFUNCTION(BlueprintCallable, Category="Utility")
	void PushItemInspectionScreen(UFortItem* ItemToInspect, EFortItemInspectionMode Mode, UFortItemTileView* CycleTileView = nullptr, bool bReadOnly = false, bool bAllowFavoriting = true, bool bIsTemporaryItem = false, bool bAllowRarityUpgrading = true);

	UFUNCTION(BlueprintCallable, Category="Utility")
	void PushItemManagementScreen(EFortFrontendInventoryFilter ItemManagementFilter, UFortItem* ItemToSelect, bool bShowAutoMulch = false);

};

