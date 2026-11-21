// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortSubscriptionPlatformModal.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract, MinimalAPI)
class UFortSubscriptionPlatformModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FText GetSubscriptionNextBillingDateAsText() const;

	UFUNCTION(BlueprintPure)
	bool IsOnActiveSubscriptionPlatform() const;

protected:
	UFUNCTION(BlueprintCallable)
	virtual void ExitModal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnModalBackout();

	UFUNCTION(BlueprintCallable)
	void SendSubscriptionAnalyticsEvent(const FString& Interaction);

	UFUNCTION(BlueprintImplementableEvent)
	void SetPlatformSpecificEntries(const TArray<FText>& Entries);

	UFUNCTION(BlueprintImplementableEvent)
	void SetPlatformSpecificQRCode(const FString& QRCodeAssetURL);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_TouchBack;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortSubscriptionPlatformModal")
	FString ModalId;

};

