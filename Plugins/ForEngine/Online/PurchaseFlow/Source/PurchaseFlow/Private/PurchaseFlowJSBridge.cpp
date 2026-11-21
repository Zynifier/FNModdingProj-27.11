// Copyright Epic Games, Inc. All Rights Reserved.

#include "PurchaseFlowJSBridge.h"

FString UPurchaseFlowJSBridge::GetDefaultExternalBrowserID(const FString& Url)
{
	return FString();
}

FString UPurchaseFlowJSBridge::GetExternalBrowserName(const FString& BrowserId)
{
	return FString();
}

FString UPurchaseFlowJSBridge::GetExternalBrowserPath(const FString& BrowserId)
{
	return FString();
}

bool UPurchaseFlowJSBridge::LaunchExternalBrowserUrl(const FString& Url)
{
	return false;
}

bool UPurchaseFlowJSBridge::LaunchValidatedExternalBrowserUrl(const FString& AllowedBrowserID, const FString& Url)
{
	return false;
}

void UPurchaseFlowJSBridge::Receipt(FPurchaseFlowReceiptParam Receipt)
{
}

void UPurchaseFlowJSBridge::RequestClose(const FString& CloseInfo)
{
}
