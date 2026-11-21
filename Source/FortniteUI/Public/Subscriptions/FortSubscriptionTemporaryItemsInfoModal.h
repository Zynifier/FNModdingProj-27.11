// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subscriptions/FortSubscriptionPlatformModal.h"
#include "FortSubscriptionTemporaryItemsInfoModal.generated.h"

UCLASS(Abstract)
class UFortSubscriptionTemporaryItemsInfoModal : public UFortSubscriptionPlatformModal
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetPlatformGenericEntries(const TArray<FText>& Entries);

};

