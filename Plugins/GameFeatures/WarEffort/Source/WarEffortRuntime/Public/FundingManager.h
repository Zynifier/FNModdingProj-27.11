// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Conversation/DataDrivenServiceTypes.h"
#include "FundingManager.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AFundingManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BroadcaseUpdatedFundsMessage(const FItemFundingUpdatedFundingData& Payload);

};

