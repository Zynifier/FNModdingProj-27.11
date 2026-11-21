// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Spectator/EventMatchInfo/AthenaEventMatchPlayerWidgetBase.h"
#include "AthenaEventMatchScoreboardPlayerWidgetBase.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaEventMatchScoreboardPlayerWidgetBase : public UAthenaEventMatchPlayerWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Scoreboard Player Widget")
	void SetSquadIdVisible(bool InVisible);

};

