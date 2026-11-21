// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "BuildingProp_ClassSelector.generated.h"

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_ClassSelector : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ClassSelector")
	bool IsInEditMode() const;

};

