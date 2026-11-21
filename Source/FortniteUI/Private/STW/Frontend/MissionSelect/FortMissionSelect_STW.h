// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Types/SlateEnums.h"
#include "FortMissionSelect_STW.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMissionSelectNavigationDelegate, EUINavigation, NavigationDirection);

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMissionSelect_STW : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MissionSelect")
	bool NavigateMissionTiles(EUINavigation Direction);

	UPROPERTY(BlueprintAssignable)
	FMissionSelectNavigationDelegate OnNavigation;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	bool CanCaptureAcceptInput();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HandleBack();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleFindPinnedQuest();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleInputInfo();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleInputRewardsInfo();

	UFUNCTION(BlueprintCallable)
	void SetBackActionEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable)
	void SetFindPinnedQuestActionEnabled(bool bEnabled);

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle FindPinnedQuestInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle RewardsInfoInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle MissionInfoInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackInputAction;

};

