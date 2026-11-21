// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/AthenaSeasonItemData.h"
#include "AthenaSeasonItemData_FriendChest.generated.h"

class UFortFriendChestItemDefinition;

UCLASS(MinimalAPI, meta=(DisplayName="Friend Chest Data"))
class UAthenaSeasonItemData_FriendChest : public UAthenaSeasonItemData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonItemData_FriendChest")
	TSoftObjectPtr<UFortFriendChestItemDefinition> FreshDripCounter;

};

