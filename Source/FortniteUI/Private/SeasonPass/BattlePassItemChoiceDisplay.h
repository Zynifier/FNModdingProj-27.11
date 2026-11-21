// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "BattlePassItemChoiceDisplay.generated.h"

class UAthenaCosmeticItemDefinition;
class UCommonButtonLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassItemChoiceDisplay : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCosmeticItemChanged(const UAthenaCosmeticItemDefinition* CosmeticItem);

private:
	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SelectAlter;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SelectEgo;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SelectBase;

};

