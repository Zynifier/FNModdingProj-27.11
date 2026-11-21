// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "StoreAlertWidget.generated.h"

class UCatalogMessaging;
class UStoreToastRequest;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UStoreAlertWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void DisplayStoreUpdated(UStoreToastRequest* NewStoreUpdatedRequest);

	UFUNCTION(BlueprintCallable)
	void SetupRequest();

	UPROPERTY(BlueprintReadWrite, Category="StoreAlertWidget")
	TObjectPtr<UStoreToastRequest> StoreUpdatedRequest;

	UPROPERTY(EditDefaultsOnly, Category="StoreAlertWidget")
	TObjectPtr<UCatalogMessaging> CatalogMessaging;

};

