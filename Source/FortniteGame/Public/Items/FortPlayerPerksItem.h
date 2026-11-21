// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortPlayerPerksItem.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortPlayerPerksItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FortPlayerPerksItem", meta=(AllowPrivateAccess="TRUE"))
	int32 earned_xp;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerPerksItem", meta=(AllowPrivateAccess="TRUE"))
	int32 previous_level;

};

