// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_AnalyticsAccumulator.generated.h"

UCLASS()
class UFortCheatManager_AnalyticsAccumulator : public UChildCheatManager
{
	GENERATED_BODY()

private:
	UFUNCTION(Exec)
	void FlushFortAnalyticsAccumulator();

};

