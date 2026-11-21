// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "McpCatalogEnums.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "CrewMultiSubscriptionAlertModal.generated.h"

class UCommonButtonBase;
class UDynamicEntryBox;

UCLASS(Abstract)
class UCrewMultiSubscriptionAlertModal : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetHowToCancelURL(const FString& MoreInfoUrl);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="FortModalBulletEntry"))
	TObjectPtr<UDynamicEntryBox> EntryBox_BulletPoints;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_OpenHowToURL;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewMultiSubscriptionAlertModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TextURL;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_DoNotRemind;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchClose;

	UPROPERTY(EditDefaultsOnly, Category="CrewMultiSubscriptionAlertModal")
	TArray<FText> BulletPoints;

	UPROPERTY(EditDefaultsOnly, Category="CrewMultiSubscriptionAlertModal")
	TMap<EAppStore, FText> AppStorePlatformMapping;

	UPROPERTY(EditDefaultsOnly, Category="CrewMultiSubscriptionAlertModal")
	FString HowToCancelURL;

	UPROPERTY(EditDefaultsOnly, Category="CrewMultiSubscriptionAlertModal")
	FText PlatformTextStyle;

};

