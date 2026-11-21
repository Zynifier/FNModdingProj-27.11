// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Items/FortPersistentTypes.h"
#include "EarnedBadgeEntry.generated.h"

class UFortBadgeItemDefinition;

USTRUCT(BlueprintType)
struct FEarnedBadgePlayerData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="EarnedBadgePlayerData")
	FUniqueNetIdRepl PlayerId;

	UPROPERTY(BlueprintReadOnly, Transient, Category="EarnedBadgePlayerData")
	int32 Count;

};

USTRUCT(BlueprintType)
struct FEarnedBadgeEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="EarnedBadgeEntry")
	TObjectPtr<UFortBadgeItemDefinition> Badge;

	UPROPERTY(BlueprintReadOnly, Transient, Category="EarnedBadgeEntry")
	TArray<FEarnedBadgePlayerData> PlayerData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="EarnedBadgeEntry")
	TEnumAsByte<EFortRewardType::Type> RewardType;

};

USTRUCT()
struct FEarnedBadgeEntryArray : public FFastArraySerializer
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FEarnedBadgeEntry> Items;

};

