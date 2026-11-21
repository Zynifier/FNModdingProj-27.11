// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "CowCatcherBarricadeBase.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ACowCatcherBarricadeBase : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void BeginCheckingForTouchingPawns();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlacementBlockedByPawnChanged(const bool bBlockedByPawn);

};

