// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAITypes.h"
#include "Building/BuildingProp.h"
#include "BuildingPropWall.generated.h"

USTRUCT(BlueprintType)
struct FBuildingPropWallActorClassData : public FBuildingPropActorClassData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropWallActorClassData)
class ABuildingPropWall : public ABuildingProp
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	FBuildingActorNavArea AreaPatternOverride;

	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	TEnumAsByte<EBuildingWallArea::Type> AreaShapeType;

protected:
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	float AreaWidthOverride;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	uint8 bOverrideAreaWidth : 1;

};

