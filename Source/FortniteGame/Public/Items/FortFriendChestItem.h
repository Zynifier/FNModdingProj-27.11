// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Items/FortAccountItem.h"
#include "FortFriendChestItem.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortFriendChestItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 granted_this_period;

	UPROPERTY()
	int32 granted_this_season;

	UPROPERTY()
	FDateTime period_reset_time;

	UPROPERTY()
	int32 catchup_bank;

	UPROPERTY()
	int32 GrantedThisSession;

};

