// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaCommonPrioritizedWidget.h"
#include "AthenaDiscoverabilityDisplay_Extension.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UAthenaDiscoverabilityDisplay_Extension : public UAthenaCommonPrioritizedWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCommonArrivalEvent(const FGameplayTag& NewTag);

protected:
	UPROPERTY(EditDefaultsOnly, Category="AthenaDiscoverabilityDisplay_Extension")
	bool bShouldHandleLastPOITag;

};

