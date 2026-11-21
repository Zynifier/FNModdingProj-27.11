// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingTrapFloor.h"
#include "BuildingTrapFloor_Hoverboard_Curve.generated.h"

class UGameplayEffect;
class USceneComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingTrapFloor_Hoverboard_Curve : public ABuildingTrapFloor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="BuildingTrapFloor_Hoverboard_Curve", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> Target;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingTrapFloor_Hoverboard_Curve")
	TObjectPtr<UGameplayEffect> TriggeredEffect;

};

