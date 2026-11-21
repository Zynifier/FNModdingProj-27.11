// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingTrapFloor.h"
#include "BuildingTrapFloor_Hoverboard.generated.h"

class UArrowComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingTrapFloor_Hoverboard : public ABuildingTrapFloor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="BuildingTrapFloor_Hoverboard", meta=(EditInline="true"))
	TObjectPtr<UArrowComponent> DirectionArrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingTrapFloor_Hoverboard")
	float PushAmount;

};

