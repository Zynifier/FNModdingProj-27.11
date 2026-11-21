// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortCloudSaveItem.h"
#include "STW/Items/FortDeployableBaseCloudSaveItemDefinition.h"
#include "FortDeployableBaseCloudSaveItem.generated.h"

UCLASS(BlueprintType)
class UFortDeployableBaseCloudSaveItem : public UFortCloudSaveItem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FFortTierProgression tier_progression;

};

