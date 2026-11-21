// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "AdaptiveCosmeticStats.generated.h"

class UStatManager;

USTRUCT(BlueprintType)
struct FFortClientObservedStat : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortClientObservedStat")
	FName StatName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortClientObservedStat")
	int32 StatValue;

};

USTRUCT()
struct FFortClientObservedStatArray : public FFastArraySerializer
{
	GENERATED_BODY()

protected:
	UPROPERTY(NotReplicated)
	TObjectPtr<UStatManager> MyStatManager;

	UPROPERTY()
	TArray<FFortClientObservedStat> ObservedStats;

};

