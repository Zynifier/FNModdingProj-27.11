// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLevelSaveComponent.h"
#include "ConcertRollbackComponent.generated.h"

UENUM()
enum class EPickupDeleteType : uint8
{
	DeleteAllTrackedPickups = 0,
	DeleteAllPickupsWithinBounds = 1,
};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UConcertRollbackComponent : public UFortLevelSaveComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="ConcertRollbackComponent")
	EPickupDeleteType PickupDeleteType;

};

