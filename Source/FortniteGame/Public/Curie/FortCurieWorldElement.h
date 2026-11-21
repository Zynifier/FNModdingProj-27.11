// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "FortCurieWorldElement.generated.h"

class UFortCurieElementContainerParamsGenerator;

UCLASS(HideCategories=("CurieIdentification", "Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortCurieWorldElement : public ABuildingGameplayActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Curie")
	TObjectPtr<UFortCurieElementContainerParamsGenerator> ElementContainerParamsGenerator;

};

