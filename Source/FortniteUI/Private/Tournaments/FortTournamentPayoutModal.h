// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "Online/FortTournamentManagerTypes.h"
#include "FortTournamentPayoutModal.generated.h"

class UCommonActionWidget;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortTournamentPayoutThresholdEntry;

USTRUCT()
struct FRewardsDataIds
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<UFortTournamentPayoutThresholdEntry*> ThresholdEntries;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTournamentPayoutModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void InitializeTabButton(UCommonButtonLegacy* TabButton, const FText& TabText);

	UFUNCTION(BlueprintImplementableEvent)
	void NotifyNoPayouts();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTabVisibilityChange(bool bIsVisible);

	UFUNCTION(BlueprintCallable)
	void SetEventWindowId(const FString& EventId, const FString& EventWindowId);

	UFUNCTION(BlueprintCallable)
	void UpdateEventWindow(const FString& EventId, const FString& EventWindowId);

	UPROPERTY(EditDefaultsOnly, Category="FortTournamentPayoutModal", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TabViewLeftAction;

	UPROPERTY(EditDefaultsOnly, Category="FortTournamentPayoutModal", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TabViewRightAction;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTournamentPayoutModal")
	UCommonButtonGroupLegacy* ViewButtonGroup;

private:
	UFUNCTION()
	void HandleViewTabSelectionChanged(UCommonButtonLegacy* TabButton, int32 TabIdx);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TournamentName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SessionName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ThresholdTypeLabel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_PayoutThresholds;

	UPROPERTY(Transient)
	TArray<FTournamentLeaderboardPayoutTableData> LeaderboardsPayoutTableData;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="UCommonButtonLegacy"))
	UDynamicEntryBox* EntryBox_ViewButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonActionWidget* ActionWidget_TabLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonActionWidget* ActionWidget_TabRight;

	UPROPERTY()
	TMap<UCommonButtonLegacy*, FRewardsDataIds> TabButtonsToRewardsIds;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTournamentPayoutThresholdEntry : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPayoutDataSet(int32 EntryIndex);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Threshold;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Rewards;

};

