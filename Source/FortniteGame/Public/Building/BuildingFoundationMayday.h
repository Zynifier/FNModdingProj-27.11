// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingFoundation.h"
#include "BuildingFoundationMayday.generated.h"

class UBuildingGroup;

UCLASS(HideCategories=("FoundationType", "Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class ABuildingFoundationMayday : public ABuildingFoundation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingFoundationMayday")
	TObjectPtr<UBuildingGroup> StrangeLandsBuildingGroup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingFoundationMayday")
	TObjectPtr<UBuildingGroup> ForceStrangeLandsBuildingGroup;

};

