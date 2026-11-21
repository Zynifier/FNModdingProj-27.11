// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SpecialActor/FortEventLevelNavigationActor.h"
#include "FortNavigationActor_BattlePassInfo.generated.h"

class UFortItemDefinition;

UCLASS(Abstract)
class AFortNavigationActor_BattlePassInfo : public AFortEventLevelNavigationActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void InitForBattlePassInfo(int32 CurrentLevel, int32 CurrentXp, int32 XpToLevel, const UFortItemDefinition* NextReward);

};

