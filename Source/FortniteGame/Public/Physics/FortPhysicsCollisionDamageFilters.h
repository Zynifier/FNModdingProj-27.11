// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Physics/FortPhysicsCollisionDamageResponse.h"
#include "FortPhysicsCollisionDamageFilters.generated.h"

UCLASS()
class UFortCollisionDamageFilter_Immunity : public UFortPhysicsCollisionDamageFilter
{
	GENERATED_BODY()

};

UCLASS()
class UFortCollisionDamageFilter_PhysicsObjectIgnoredActorsForDamage : public UFortPhysicsCollisionDamageFilter
{
	GENERATED_BODY()

};

UCLASS()
class UFortCollisionDamageFilter_VehicleFloors : public UFortPhysicsCollisionDamageFilter
{
	GENERATED_BODY()

};

UCLASS()
class UFortPhysicsCollisionDamageFilter_TeamDamage : public UFortPhysicsCollisionDamageFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortPhysicsCollisionDamageFilter_TeamDamage")
	bool bAllowTeamDamageToPlayers;

};

