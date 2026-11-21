// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortPlatformPurchaseErrorCodeModal.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;
class UDynamicEntryBox;

UCLASS(Abstract, MinimalAPI)
class UFortPlatformPurchaseErrorCodeModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	virtual void ExitModal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnModalBackout();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlatformPurchaseErrorCodeModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlatformPurchaseErrorCodeModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchBack;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="FortModalBulletEntry"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Descriptions;

};

