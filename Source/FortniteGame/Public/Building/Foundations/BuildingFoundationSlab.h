// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingFoundation.h"
#include "BuildingFoundationSlab.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class ABuildingFoundationSlab : public ABuildingFoundation
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="BuildingFoundationSlab")
	FText CreatorName;

};

