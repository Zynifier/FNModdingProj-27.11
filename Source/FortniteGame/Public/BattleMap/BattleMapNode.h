// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleMapNode.generated.h"

class ABattleMapEdge;
class ABattleMapNode;
class UMaterialInterface;

UCLASS(MinimalAPI)
class ABattleMapNode : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TSubclassOf<ABattleMapEdge> EdgeClass;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TSubclassOf<ABattleMapNode> ChildrenNodeClass;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	bool bEnableAutomaticResize;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	bool bSupportSelection;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	bool bSupportScrubbing;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TArray<TObjectPtr<UMaterialInterface>> CustomMaterialsPerPlayerIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABattleMapEdge>> NextEdges;

	UPROPERTY(Transient)
	TMap<TObjectPtr<ABattleMapNode>, TObjectPtr<ABattleMapEdge>> ChildrenNodes;

};

