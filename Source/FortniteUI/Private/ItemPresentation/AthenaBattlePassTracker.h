// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaBattlePassTracker.generated.h"

class UAthenaBattlePassItemTracker;
class UBattlePassScreenPurchaseButton;
class UCommonRichTextBlock;

USTRUCT(BlueprintType)
struct FAthenaRewardTracker
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaBattlePassTracker : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AthenaBattlePassTracker")
	FText OutfitsText;

	UPROPERTY(EditAnywhere, Category="AthenaBattlePassTracker")
	FText VBucksText;

	UPROPERTY(EditAnywhere, Category="AthenaBattlePassTracker")
	FText EmotesText;

	UPROPERTY(EditAnywhere, Category="AthenaBattlePassTracker")
	FText MoreRewardsText;

	UPROPERTY(EditAnywhere, Category="AthenaBattlePassTracker")
	FText BuyBattlePassTextFormat;

private:
	UFUNCTION()
	void HandlePassPurchaseFlowStarted();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBattlePassTracker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_PaidItemsCollected;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBattlePassTracker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaBattlePassItemTracker> BattlePassItemTracker_01;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBattlePassTracker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaBattlePassItemTracker> BattlePassItemTracker_02;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBattlePassTracker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaBattlePassItemTracker> BattlePassItemTracker_03;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBattlePassTracker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaBattlePassItemTracker> BattlePassItemTracker_04;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBattlePassTracker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPurchaseButton> Button_PurchaseBattlePass;

};

