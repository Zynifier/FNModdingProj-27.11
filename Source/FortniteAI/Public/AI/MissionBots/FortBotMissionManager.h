// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortBotMissionManager.generated.h"

class AFortPawn;
class UFortBotMissionLogic;

UCLASS()
class UFortBotMissionManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftClassPtr<AFortPawn> BotPawnClass;

protected:
	UPROPERTY()
	TArray<TObjectPtr<AFortPawn>> BotPawns;

	UPROPERTY()
	TArray<TObjectPtr<UFortBotMissionLogic>> ActiveMissionsLogicData;

	UPROPERTY()
	TObjectPtr<UFortBotMissionLogic> PrimaryMissionLogicData;

};

