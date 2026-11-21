// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "UI/FortTooltipInterface.h"
#include "FortHomebaseNodeItem.generated.h"

UCLASS(MinimalAPI)
class UFortHomebaseNodeItem : public UFortAccountItem, public IFortTooltipInterface
{
	GENERATED_BODY()

};

