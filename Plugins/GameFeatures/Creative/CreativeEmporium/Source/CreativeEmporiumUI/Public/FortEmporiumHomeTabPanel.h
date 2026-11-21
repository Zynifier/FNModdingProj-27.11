// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeContentBrowserTabPanelBase.h"
#include "FortEmporiumHomeTabPanel.generated.h"

class UFortEmporiumHomeListView;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEmporiumHomeTabPanel : public UFortCreativeContentBrowserTabPanelBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumHomeTabPanel")
	FName FeaturedItemTag;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumHomeTabPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEmporiumHomeListView> FortEmporiumHomeListView_Options;

};

