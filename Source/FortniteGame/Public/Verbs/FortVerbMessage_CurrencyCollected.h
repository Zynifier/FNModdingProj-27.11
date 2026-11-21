// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_CurrencyCollected.generated.h"

USTRUCT()
struct FFortVerbMessage_CurrencyCollected : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_CurrencyCollected")
	int32 CollectedAmount;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_CurrencyCollected")
	FSubjectTagsPair CollectedItemSpawnSource;

};

