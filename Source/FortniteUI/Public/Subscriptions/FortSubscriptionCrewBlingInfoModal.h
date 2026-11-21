// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subscriptions/FortSubscriptionPlatformModal.h"
#include "FortSubscriptionCrewBlingInfoModal.generated.h"

UCLASS(Abstract)
class UFortSubscriptionCrewBlingInfoModal : public UFortSubscriptionPlatformModal
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	FText FormatBulletPoint(const FText& InBulletPoint);

	UFUNCTION(BlueprintImplementableEvent)
	void SetPlatformGenericEntries(const TArray<FText>& Entries);

};

