// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BattlePassLandingPageBase.h"
#include "BattlePassLandingPageS27.generated.h"

class UAthenaSeasonItemData_BattleStar;
class UBattlePassLandingPageButton;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassLandingPageS27 : public UBattlePassLandingPageBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBattlePassSubscriptionAllowed(const bool bSubscriptionAllowed);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLandingPageS27", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassLandingPageButton> Button_Rewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLandingPageS27", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassLandingPageButton> Button_CharacterCustomizer;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLandingPageS27", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassLandingPageButton> Button_BonusRewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLandingPageS27", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassLandingPageButton> Button_Quests;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLandingPageS27", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassLandingPageButton> Button_JoinSubscription;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLandingPageS27", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassLandingPageButton> Button_WeeklyRewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassLandingPageS27", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SeasonNumber;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaSeasonItemData_BattleStar> SeasonData_BattleStar;

};

