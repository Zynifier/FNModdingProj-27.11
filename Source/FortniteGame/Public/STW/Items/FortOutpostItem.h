// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortCloudSaveItem.h"
#include "STW/Items/FortOutpostItemDefinition.h"
#include "FortOutpostItem.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortOutpostItem : public UFortCloudSaveItem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FFortOutpostCoreInfo outpost_core_info;

};

