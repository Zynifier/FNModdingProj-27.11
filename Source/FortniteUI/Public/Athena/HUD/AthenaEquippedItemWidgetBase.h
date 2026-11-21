// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/AthenaEquippedItemInfoWidget.h"
#include "AthenaEquippedItemWidgetBase.generated.h"

class UCommonTextBlock;
class UVerticalBox;
class UWidgetAnimation;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class FORTNITEUI_API UAthenaEquippedItemWidgetBase : public UAthenaEquippedItemInfoWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="AthenaEquippedItemWidgetBase")
	float OutroDelayTime;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaEquippedItemWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> SwitchPopup;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaEquippedItemWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> SwitchPopupText;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaEquippedItemWidgetBase", meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> NameIntro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaEquippedItemWidgetBase", meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> NameOutro;

private:
	UFUNCTION(BlueprintCallable)
	void OnPopUpOnSwitchDone();

};

