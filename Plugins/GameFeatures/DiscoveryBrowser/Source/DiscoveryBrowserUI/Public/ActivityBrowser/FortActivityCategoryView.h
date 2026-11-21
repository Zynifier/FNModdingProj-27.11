// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "ActivityBrowser/FortActivityBrowserView.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "FortActivityCategoryView.generated.h"

class UFortActivityCategoryTilePanel;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityCategoryView : public UFortActivityBrowserView, public IFortTabInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	const UFortActivityCategoryTilePanel* GetCurrentSelectedPanel() const;

	UFUNCTION(BlueprintNativeEvent)
	UFortActivityCategoryTilePanel* GetTopMostVisiblePanel() const;

	UFUNCTION(BlueprintCallable)
	UFortActivityCategoryTilePanel* NavigateFromPanel(EUINavigation Direction, UFortActivityCategoryTilePanel* NavigatingPanel);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCategoryTilePanelSelected(const UFortActivityCategoryTilePanel* SelectedPanel);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSurfaceDataReady();

private:
	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FName TabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityCategoryView", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityCategoryTilePanel> TilePanel_Featured;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityCategoryView", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityCategoryTilePanel> TilePanel_All;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActivityCategoryTilePanel> CurrentSelectedPanel;

};

