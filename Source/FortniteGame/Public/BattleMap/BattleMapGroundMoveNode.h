// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BattleMap/BattleMapNode.h"
#include "BattleMapGroundMoveNode.generated.h"

UCLASS()
class ABattleMapGroundMoveNode : public ABattleMapNode
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnAllNodesSpawned();

};

