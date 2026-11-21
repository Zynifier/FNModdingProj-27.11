// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortClientEventInterface.h"
#include "FortStoreRootBase.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FPopulatePrerollOffersCallback, bool, bSuccess);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UFortStoreRootBase : public UCommonActivatablePanelLegacy, public IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void PopulatePrerollOffers(const FPopulatePrerollOffersCallback& Callback);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionWidgetBase")
	void OnUpdateOtherPlatformMTXMessage(bool HasOtherPlatformCurrency, const FText& CurrencyMessageLocText);

};

