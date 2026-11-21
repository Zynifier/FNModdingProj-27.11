// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Acquire.generated.h"

USTRUCT()
struct FAcquireRewardPair
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="AcquireRewardPair")
	FGameplayTagContainer ItemTags;

	UPROPERTY(VisibleAnywhere, Category="AcquireRewardPair")
	int32 ItemCount;

};

USTRUCT()
struct FFortVerbMessage_Acquire : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Acquire")
	TArray<FAcquireRewardPair> ItemsAcquired;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Acquire")
	FGameplayTagContainer AcquireSource;

};

