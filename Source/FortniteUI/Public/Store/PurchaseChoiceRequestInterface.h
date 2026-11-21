// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PurchaseChoiceRequestInterface.generated.h"

class AFortPlayerController;
class IPurchaseChoiceRequesterInterface;
class UFortStoreFrontOfferInfo;

UINTERFACE(MinimalAPI)
class UPurchaseChoiceRequesterInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEUI_API IPurchaseChoiceRequesterInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void CancelPurchase();

	UFUNCTION(BlueprintNativeEvent)
	UFortStoreFrontOfferInfo* GetPurchaseChoiceOfferInfo() const;

	UFUNCTION(BlueprintNativeEvent)
	AFortPlayerController* GetPurchaseChoiceOwningPlayer() const;

	UFUNCTION(BlueprintNativeEvent)
	void StartPurchase(int32 PriceIndex);

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BroadcastPurchaseChoiceRequestedEvent(const TScriptInterface<IPurchaseChoiceRequesterInterface>& Requester);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsPurchaseChoiceRequestedEventBound() const;

};

