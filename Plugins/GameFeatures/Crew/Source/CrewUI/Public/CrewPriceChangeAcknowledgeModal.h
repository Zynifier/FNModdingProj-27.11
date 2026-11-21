// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Context/AthenaBattlePassCrewStructs.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "CrewPriceChangeAcknowledgeModal.generated.h"

class UCommonButtonBase;
class UFortSubscriptionCancellationModal;

UCLASS(Abstract)
class UCrewPriceChangeAcknowledgeModal : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ExitModal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnModalBackout();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPriceChangeAcknowledgeBodyTable(const TArray<FCrewTableRow>& PriceChangeByRegionRows);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPriceChangeAcknowledgeBodyText(const FText& BodyText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPriceChangeAcknowledgeCancelSubscriptionButtonText(const FText& CancelSubscriptionButtonText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPriceChangeAcknowledgeCheckboxText(const FText& CheckboxText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPriceChangeAcknowledgeConfirmButtonText(const FText& ConfirmButtonText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPriceChangeAcknowledgeMoreInfoText(const FText& ConfirmButtonText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPriceChangeAcknowledgeMoreInfoUrl(const FText& MoreInfoUrl);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPriceChangeAcknowledgeTitle(const FText& Title);

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPriceChangeAcknowledgeModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Accept;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPriceChangeAcknowledgeModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CancelSubscription;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPriceChangeAcknowledgeModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MoreInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPriceChangeAcknowledgeModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TextURL;

	UPROPERTY(EditDefaultsOnly, Category="CrewPriceChangeAcknowledgeModal")
	TSoftClassPtr<UFortSubscriptionCancellationModal> CancellationInfoModalClass;

};

