// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortRepeatableDailiesCardItem.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortRepeatableDailiesCardItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FortRepeatableDailiesCardItem", meta=(AllowPrivateAccess="TRUE"))
	int32 days_since_season_start_grant;

};

