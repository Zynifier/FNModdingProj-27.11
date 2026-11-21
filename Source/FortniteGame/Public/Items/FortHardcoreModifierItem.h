// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortHardcoreModifierItem.generated.h"

UCLASS(BlueprintType)
class UFortHardcoreModifierItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	bool is_enabled;

};

