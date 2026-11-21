// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortEventPurchaseTrackerItem.generated.h"

UCLASS()
class UFortEventPurchaseTrackerItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FString event_instance_id;

	UPROPERTY()
	TMap<FString, int32> event_purchases;

};

