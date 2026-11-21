// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Building/BuildingSMActor.h"
#include "FortAthenaSupplyDropBalloon.generated.h"

class AActor;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class AFortAthenaSupplyDropBalloon : public ABuildingSMActor, public IFortMarkableActorInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Marking")
	AActor* GetAttachedActorToMark() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Marking")
	uint8 bMarkAttachedActor : 1;

};

