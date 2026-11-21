// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/AthenaSeasonItemData.h"
#include "AthenaSeasonItemData_EngagementEvent.generated.h"

class UFortGiftBoxItemDefinition;

UCLASS()
class UAthenaSeasonItemData_EngagementEvent : public UAthenaSeasonItemData
{
	GENERATED_BODY()

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonItemData_EngagementEvent")
	TSoftObjectPtr<UFortGiftBoxItemDefinition> BattleStarGiftBox;
#endif

};

