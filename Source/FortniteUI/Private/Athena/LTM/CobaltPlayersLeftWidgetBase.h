// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "CobaltPlayersLeftWidgetBase.generated.h"

UCLASS()
class UCobaltPlayersLeftWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDisplay(int32 NewTeamPlayersLeft, int32 NewEnemyPlayersLeft);

};

