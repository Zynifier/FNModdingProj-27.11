// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortAccoladeItem.generated.h"

UCLASS(BlueprintType)
class UFortAccoladeItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FortAccoladeItem", meta=(AllowPrivateAccess="TRUE"))
	int32 last_earned_day;

	UPROPERTY(BlueprintReadOnly, Category="FortAccoladeItem", meta=(AllowPrivateAccess="TRUE"))
	int32 earned_count;

};

