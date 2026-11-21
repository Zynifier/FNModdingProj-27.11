// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortConversationOptionBrief.h"
#include "FortItemTransactionBrief.generated.h"

class UFortItem;
class UFortTransactionStrip;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortItemTransactionBrief : public UFortConversationOptionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnTransactionInfoReceived(UFortItem* Item);

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortTransactionStrip> TransactionStrip_Main;

	UPROPERTY(Transient)
	TObjectPtr<UFortItem> DisplayItem;

};

