// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingSMActor.h"
#include "BuildingAutoNav.generated.h"

UCLASS(Abstract, MinimalAPI, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class ABuildingAutoNav : public ABuildingSMActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Navigation")
	uint8 bAutoAssignNavProperties : 1;

};

