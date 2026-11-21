// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "BattlePassRewardChallenges.generated.h"

class UCommonTextBlock;
class UDynamicEntryBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassRewardChallenges : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAllChalengesCompleted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnClearEntries();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitChallenges(const FText& ChallengesTitle);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitPrerequisites();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetChallengesSwitcher(bool bShowChallenges);

	UPROPERTY(EditAnywhere, Category="BattlePassRewardChallenges")
	FText BuyBattlePassText;

	UPROPERTY(EditAnywhere, Category="BattlePassRewardChallenges")
	FText DefaultChallengesTitle;

	UPROPERTY(EditAnywhere, Category="BattlePassRewardChallenges")
	FText UnlocksInXDaysTextFormat;

	UPROPERTY(EditAnywhere, Category="BattlePassRewardChallenges")
	FText UnlocksInXHoursTextFormat;

	UPROPERTY(EditAnywhere, Category="BattlePassRewardChallenges")
	FText UnlocksSoonText;

	UPROPERTY(EditAnywhere, Category="BattlePassRewardChallenges")
	FText HiddenChallengeText;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardChallenges", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PrerequisitesTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardChallenges", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChallengesTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardChallenges", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Prerequisites;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardChallenges", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Challenges;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_UnlocksIn;

};

