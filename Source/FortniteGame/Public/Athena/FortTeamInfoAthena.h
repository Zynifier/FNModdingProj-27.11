// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortBotTeamInfoAthena.h"
#include "FortTeamInfo.h"
#include "FortTeamInfoAthena.generated.h"

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortTeamInfoAthena : public AFortTeamInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FFortBotTeamInfoAthena BotInfo;

};

