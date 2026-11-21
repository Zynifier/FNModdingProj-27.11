// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CosmeticLoadoutContext.h"
#include "BasicCosmeticLoadoutContext.generated.h"

UCLASS(MinimalAPI, meta=(Category="Cosmetics|Loadout"))
class UBasicCosmeticLoadoutContext : public UObject, public ICosmeticLoadoutContext
{
	GENERATED_BODY()

};

