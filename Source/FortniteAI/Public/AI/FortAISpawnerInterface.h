// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAISpawnerInterface.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class UFortAISpawnerInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortAISpawnerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Spawner")
	bool IsReadyToReceiveNewSpawnGroup();

	UFUNCTION(BlueprintImplementableEvent, Category="Spawner")
	bool OnReceiveSpawnGroup();

};

