// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemReceived/FortItemReceivedTypes.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortItemNotification.generated.h"

class UCommonButtonLegacy;
class UFortItemInfoPresentationWidget;
class UFortItemPresentationEntry;
class UFortItemReceivedHeaderBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortItemNotification : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CloseScreen();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCloseScreen();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNextItemDisplay();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetButtonText(bool bCanCloseWidget);

	UFUNCTION(BlueprintCallable)
	void OnUpdateScreenInformation();

	UPROPERTY(BlueprintReadOnly, Category="FortItemNotification")
	TArray<FFortReceivedItemLootInfo> ItemDefs;

	UPROPERTY(EditAnywhere, Category="FortItemNotification")
	float BodyTextWrapWidth;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemNotification", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemReceivedHeaderBase> ItemPresentationGenericRewardHeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemPresentationEntry> ItemPresentationEntry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemInfoPresentationWidget> ItemInfoPresentationWidget;

};

