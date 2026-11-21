// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_AddToInventory.generated.h"

USTRUCT()
struct FFortVerbMessage_AddToInventory : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_AddToInventory")
	int32 Amount;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_AddToInventory")
	bool bIsBrandNewItem;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_AddToInventory")
	FGuid ItemGuid;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_AddToInventory")
	FSubjectTagsPair Item;

};

