// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortBadgeCount.generated.h"

class UFortBadgeItemDefinition;

USTRUCT(BlueprintType)
struct FFortBadgeCount : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortBadgeCount")
	TObjectPtr<UFortBadgeItemDefinition> Badge;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortBadgeCount")
	int32 Count;

};

USTRUCT()
struct FFortBadgeCountArray : public FFastArraySerializer
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FFortBadgeCount> Badges;

};

