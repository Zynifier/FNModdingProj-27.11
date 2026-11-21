// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ActivityBrowser/FortActivityBrowserRowView.h"
#include "FortActivityDiscoverViewV2.generated.h"

class UCommonActivatableWidget;
class UDiscoverSelectedActivityViewModel;
class UFortDiscoverBackgroundManager;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActivityRequested);

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityDiscoverViewV2 : public UFortActivityBrowserRowView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void FireDiscoverExitedAnalyticEvent();

	UFUNCTION(BlueprintPure)
	bool IsShowingPromotedContent() const;

	UFUNCTION(BlueprintPure)
	bool IsShowingSeasonalContent() const;

	UFUNCTION(BlueprintCallable)
	void StartDiscoverAnalyticSession();

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE", DisplayName="On Activity Requested"))
	FOnActivityRequested OnActivityRequested;

private:
	UFUNCTION(BlueprintCallable)
	void UpdateMiscActionBindingVisibility(bool bVisible);

	UPROPERTY(Transient)
	TObjectPtr<UFortDiscoverBackgroundManager> DiscoverBackgroundManager;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortActivityDiscoverViewV2", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<UDiscoverSelectedActivityViewModel> SelectedActivityVM;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityDiscoverViewV2")
	TSoftClassPtr<UCommonActivatableWidget> SoftCustomMatchmakingModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityDiscoverViewV2")
	TSoftClassPtr<UCommonActivatableWidget> SoftSpectateMatchModalClass;

	UPROPERTY(EditAnywhere, Category="FortActivityDiscoverViewV2", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackToTopInputAction;

	UPROPERTY(EditAnywhere, Category="FortActivityDiscoverViewV2")
	FDataTableRowHandle CustomKeyInputAction;

	UPROPERTY(EditAnywhere, Category="FortActivityDiscoverViewV2")
	FDataTableRowHandle ShowSpectateMatchModalInputAction;

	UPROPERTY(EditAnywhere, Category="FortActivityDiscoverViewV2")
	FDataTableRowHandle JoinAsSpectatorInputAction;

	UPROPERTY(EditAnywhere, Category="FortActivityDiscoverViewV2")
	FDataTableRowHandle JoinAsPlayerInputAction;

	UPROPERTY(EditAnywhere, Category="FortActivityDiscoverViewV2")
	FDataTableRowHandle SelectActivityInputAction_Touch;

};

