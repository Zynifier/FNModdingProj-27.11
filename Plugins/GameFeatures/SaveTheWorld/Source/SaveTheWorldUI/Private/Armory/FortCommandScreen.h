// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortCommandScreen.generated.h"

class UFortCampaignHeroLoadoutItem;
class UFortItem;
class UFortItemTileView;
enum class EFortItemInspectionMode : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UFortCommandScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Input", meta=(BlueprintProtected="true"))
	void HandleShowAllStats();

	UFUNCTION(BlueprintImplementableEvent, Category="Input", meta=(BlueprintProtected="true"))
	void HandleUpgradeInspectHero();

	UFUNCTION(BlueprintCallable, Category="Utility")
	void PushHeroLoadoutScreen(UFortCampaignHeroLoadoutItem* HeroLoadout);

	UFUNCTION(BlueprintCallable, Category="Utility")
	void PushItemInspectionScreen(UFortItem* ItemToInspect, EFortItemInspectionMode Mode, UFortItemTileView* CycleTileView = nullptr, bool bReadOnly = false, bool bAllowFavoriting = true, bool bIsTemporaryItem = false, bool bAllowRarityUpgrading = true);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(RowType="/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ShowAllStatsActionData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(RowType="/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle InspectHeroActionData;

};

