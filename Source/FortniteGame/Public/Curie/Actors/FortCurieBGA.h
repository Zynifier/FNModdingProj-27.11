// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "FortCurieBGA.generated.h"

class UFortCurieComponent;

UCLASS(MinimalAPI, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortCurieBGA : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Export, Category="Curie", meta=(EditInline="true"))
	TObjectPtr<UFortCurieComponent> CurieComponent;

};

