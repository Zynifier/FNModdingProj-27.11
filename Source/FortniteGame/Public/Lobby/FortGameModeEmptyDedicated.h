// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameMode.h"
#include "FortGameModeEmptyDedicated.generated.h"

class AFortGameSessionDedicated;

UCLASS(HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameModeEmptyDedicated : public AFortGameMode
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortGameSessionDedicated> FortGameSessionDedicated;

};

