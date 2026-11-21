// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingAutoNav.h"
#include "BuildingCorner.generated.h"

class ABuildingSMActor;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class ABuildingCorner : public ABuildingAutoNav
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<ABuildingSMActor> PrimaryWall;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingSMActor> SecondaryWall;

};

