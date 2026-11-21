// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHoldableButton.h"
#include "BattlePassCrewPurchaseButton.generated.h"

class UCommonTextBlock;
class UWidget;

UENUM(BlueprintType)
enum class EBattlePassPurchaseButtonCurrencyType : uint8
{
	None = 0,
	Mtx = 1,
	RealMoney = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UBattlePassCrewPurchaseButton : public UFortHoldableButton
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCurrencyUpdated();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="BattlePassCrewPurchaseButton")
	EBattlePassPurchaseButtonCurrencyType CurrencyType;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassCrewPurchaseButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Label;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassCrewPurchaseButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SecondaryLabel;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassCrewPurchaseButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FinalCost;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassCrewPurchaseButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Container_SecondaryLabel;

};

