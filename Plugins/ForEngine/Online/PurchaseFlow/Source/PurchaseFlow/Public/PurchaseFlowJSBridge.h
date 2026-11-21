// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PurchaseFlowJSBridge.generated.h"

USTRUCT()
struct FPurchaseFlowItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ItemId;

	UPROPERTY()
	FString EntitlementId;

	UPROPERTY()
	FString ValidationInfo;

};

USTRUCT()
struct FPurchaseFlowOffer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString OfferNamespace;

	UPROPERTY()
	FString OfferId;

	UPROPERTY()
	int32 Quantity;

	UPROPERTY()
	TArray<FPurchaseFlowItem> Items;

};

USTRUCT()
struct PURCHASEFLOW_API FPurchaseFlowReceiptParam
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TransactionId;

	UPROPERTY()
	FString TransactionState;

	UPROPERTY()
	TArray<FPurchaseFlowOffer> Offers;

};

UCLASS()
class UPurchaseFlowJSBridge : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	FString GetDefaultExternalBrowserID(const FString& Url);

	UFUNCTION()
	FString GetExternalBrowserName(const FString& BrowserId);

	UFUNCTION()
	FString GetExternalBrowserPath(const FString& BrowserId);

	UFUNCTION()
	bool LaunchExternalBrowserUrl(const FString& Url);

	UFUNCTION()
	bool LaunchValidatedExternalBrowserUrl(const FString& AllowedBrowserID, const FString& Url);

	UFUNCTION()
	void Receipt(FPurchaseFlowReceiptParam Receipt);

	UFUNCTION()
	void RequestClose(const FString& CloseInfo);

};

