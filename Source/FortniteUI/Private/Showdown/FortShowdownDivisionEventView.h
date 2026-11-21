// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CommonButtonLegacy.h"
#include "Showdown/FortShowdownDetailView.h"
#include "FortShowdownDivisionEventView.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortLazyImage;
class UProgressBar;
class UScrollBox;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortShowdownDivisionEventView : public UFortShowdownDetailView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetAmountEarnedWithinDivision() const;

	UFUNCTION(BlueprintPure)
	int32 GetDivisionRank() const;

	UFUNCTION(BlueprintPure)
	FText GetLeagueDisplayName() const;

	UFUNCTION(BlueprintPure)
	FText GetLeagueDisplayNameByDivision(int32 InDivision) const;

	UFUNCTION(BlueprintPure)
	int32 GetNumericalDisplayAmountForNextDivision() const;

	UFUNCTION(BlueprintPure)
	int32 GetRequiredAmountToAdvanceDivision() const;

	UFUNCTION(BlueprintPure)
	int32 GetTotalNumberOfDivisions() const;

	UFUNCTION(BlueprintPure)
	bool IsDivisionEvent() const;

protected:
	UFUNCTION(BlueprintPure)
	int32 GetTotalDivisionPoints() const;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortDivisionDetailsInfo : public UFortShowdownDivisionEventView
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBoxes_DivisionProgressRanks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ResetTimeContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ResetTime;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortDivisionPayoutInfo : public UFortShowdownDivisionEventView
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDivisionChanged(int32 NewDivision);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBoxes_DivisionRanksButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionPayoutInfo", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Left;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionPayoutInfo", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Right;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Payouts;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_League;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DivsionRank;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionPayoutInfo", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Payouts;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPayoutInfoEntry : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPayoutInfoEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Points;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPayoutInfoEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PointsLabel;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortShowdownDivisionRankButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRankButtonSelected(bool bIsSelected);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownDivisionRankButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_DivisionIcon;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortShowdownDivisionRankProgressView : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetInProgress(float NewPercent, bool bIsInProgress);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownDivisionRankProgressView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_DivisionIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownDivisionRankProgressView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> Bar_DivisionProgress;

};

