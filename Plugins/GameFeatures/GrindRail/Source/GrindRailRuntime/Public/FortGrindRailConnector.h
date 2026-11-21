// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "FortGrindRailConnector.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortGrindRailConnector : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintReadOnly, Category="FortGrindRailConnector")
	bool bConstructedFromDragging;
#endif

};

