// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BattlePassCrewContentInterface.generated.h"

UENUM(BlueprintType)
enum class EBattlePassCrewContentState : uint8
{
	BattlePass = 0,
	Crew = 1,
	CrewSubscribed = 2,
};

UINTERFACE(MinimalAPI)
class UBattlePassCrewContentInterface : public UInterface
{
	GENERATED_BODY()
};

class IBattlePassCrewContentInterface
{
	GENERATED_BODY()

};

