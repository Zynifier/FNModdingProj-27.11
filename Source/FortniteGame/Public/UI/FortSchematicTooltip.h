// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortAccountItemTooltip.h"
#include "FortSchematicTooltip.generated.h"

class UFortWorldItem;

UCLASS(BlueprintType, Blueprintable, meta=(ShortTooltip="Gathers data from schematics for display tooltips."))
class UFortSchematicTooltip : public UFortAccountItemTooltip
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortWorldItem> Item;

};

