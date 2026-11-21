// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_CurrencySpent.generated.h"

USTRUCT(meta=(DisplayName="Currency Spent"))
struct FFortVerbMessage_CurrencySpent : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_CurrencySpent")
	int32 AmountSpent;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_CurrencySpent")
	FSubjectTagsPair PurchaseTags;

};

