// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FortSpawnableByPlacementSystemInterface.generated.h"

class AFortMission;

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortSpawnableByPlacementSystemInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortSpawnableByPlacementSystemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Missions")
	virtual AFortMission* GetMission() const;

	UFUNCTION(BlueprintCallable, Category="Missions")
	virtual FGuid GetMissionGuid() const;

};

