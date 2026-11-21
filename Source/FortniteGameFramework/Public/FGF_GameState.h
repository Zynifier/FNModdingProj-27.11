// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "GameplayEventRouterOwnerInterface.h"
#include "FGF_GameState.generated.h"

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFGF_GameState : public AGameState, public IGameplayEventRouterOwnerInterface
{
	GENERATED_BODY()

};

