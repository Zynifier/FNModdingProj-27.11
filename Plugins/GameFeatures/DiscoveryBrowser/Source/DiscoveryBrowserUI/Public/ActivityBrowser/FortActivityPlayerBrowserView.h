// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserView.h"
#include "Creative/DAD/FortCreativeDiscoverySurface.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "FortActivityPlayerBrowserView.generated.h"

class UFortActivityTileView;
class UFortGameActivityProvider;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityPlayerBrowserView : public UFortActivityBrowserView, public IFortTabInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void PlayViewIntro();

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Tile View Updated"))
	void BP_OnTileViewUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayViewIntro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnQueryActivitiesComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnQueryActivitiesStarted();

	UPROPERTY()
	TObjectPtr<UFortGameActivityProvider> ActivityProvider;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityPlayerBrowserView", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityTileView> TileView_PlayerActivities;

private:
	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FName TabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(EditInstanceOnly, Category="FortActivityPlayerBrowserView")
	EFortCreativeDiscoveryPlayHistoryType PlayHistoryProviderType;

};

