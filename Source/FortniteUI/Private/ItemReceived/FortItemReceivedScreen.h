// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemReceived/FortItemReceivedWidgetBase.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortItemReceivedScreen.generated.h"

class UCommonLazyImage;
class UFortGiftBoxItem;

UCLASS(Abstract)
class UFortItemReceivedScreen : public UFortItemReceivedWidgetBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinalGiftingComplete);

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnFinalGiftingComplete OnFinalGiftingComplete;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMessageReceivedScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinalGiftingComplete);

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnFinalGiftingComplete OnMessageClosed;

protected:
	UFUNCTION(BlueprintCallable)
	FText GetBodyAssetString(const FString& Param);

	UFUNCTION(BlueprintCallable)
	FText GetHeaderAssetString(const FString& Param);

	UFUNCTION(BlueprintCallable)
	bool GetTournamentTitleFromCMS(const FString& DisplayDataId, FString& OutTitle);

	UFUNCTION(BlueprintImplementableEvent)
	void OnGiftBoxSet();

	UPROPERTY(BlueprintReadOnly, Category="FortMessageReceivedScreen")
	TObjectPtr<UFortGiftBoxItem> GiftBoxItem;

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLazyImage> GiftBoxImage;

};

