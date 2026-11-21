// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleMapEdge.generated.h"

class ABattleMapNode;
class UMaterialInterface;

UCLASS()
class ABattleMapEdge : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandeResizedBattleNode(float NewScaling, const ABattleMapNode* Node);

	UFUNCTION()
	void OnNextNextSet(const ABattleMapNode* NextNextNode);

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TArray<TObjectPtr<UMaterialInterface>> CustomMaterialsPerPlayerIndex;

};

