// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Physics/FortPhysicsCollisionHandler.h"
#include "FortPhysicsCollisionDamageResponse.generated.h"

class UFortPhysicsCollisionDamageFilter;

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class UFortPhysicsCollisionDamageFilter : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortPhysicsCollisionDamageFilter")
	bool bFilterDamageBothWays;

};

UCLASS(Abstract)
class UFortPhysicsCollisionDamageResponse : public UFortPhysicsCollisionResponse
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Export, Category="FortPhysicsCollisionDamageResponse", meta=(DisplayPriority="2", EditInline="true"))
	TArray<TObjectPtr<UFortPhysicsCollisionDamageFilter>> CollisionDamageFilters;

};

