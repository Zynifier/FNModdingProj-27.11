// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingAutoNav.h"
#include "BuildingDeco.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("CurieIdentification", "Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class ABuildingDeco : public ABuildingAutoNav
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	bool bCastShadow;

};

