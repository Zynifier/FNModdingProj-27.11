// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserView.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "FortActivityBrowserRowView.generated.h"

class UFortActivityBrowserListView;
class UFortSwipePanel;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortActivityBrowserRowView : public UFortActivityBrowserView, public IFortTabInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnListViewScrolled(float ItemOffset, float DistanceRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnQueryActivitiesFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRowChanged(const int32 NewCategoryIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta=(DisplayName="Mouse Wheel Scroll Time Threshold"))
	float MouseWheelScrollTimeThreshold;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserRowView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityBrowserListView> BrowserList_Activities;

private:
	UPROPERTY(EditInstanceOnly, Category="Tab Interface")
	FName TabNameId;

	UPROPERTY(EditInstanceOnly, Category="Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserRowView", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortSwipePanel> SwipePanel_Navigation;

};

