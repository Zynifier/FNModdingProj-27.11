// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Physics/FortPhysicsCollisionDamageResponse.h"
#include "Physics/FortPhysicsCollisionHandler.h"
#include "FortPhysicsCollisionDamageResponse_DeltaVelocity.generated.h"

USTRUCT()
struct FDeltaVelocityDamageHandlerData : public FCollisionResponseBaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DeltaVelocityDamageHandlerData")
	TArray<FScalableFloat> DeltaVelocityBuckets;

	UPROPERTY(EditAnywhere, Category="DeltaVelocityDamageHandlerData")
	TArray<FScalableFloat> DamageBuckets;

	UPROPERTY(EditAnywhere, Category="DeltaVelocityDamageHandlerData")
	bool bEnableMassControl;

	UPROPERTY(EditAnywhere, Category="DeltaVelocityDamageHandlerData", meta=(EditCondition="bEnableMassControl"))
	TArray<FScalableFloat> MassBuckets;

	UPROPERTY(EditAnywhere, Category="DeltaVelocityDamageHandlerData", meta=(EditCondition="bEnableMassControl"))
	TArray<FScalableFloat> MassMultiplierBuckets;

	UPROPERTY(EditAnywhere, Category="DeltaVelocityDamageHandlerData")
	FScalableFloat MinSourceInitialVelocity;

};

UCLASS(meta=(TitleProperty="Default Damage Handler"))
class UFortPhysicsCollisionDamageResponse_DeltaVelocity : public UFortPhysicsCollisionDamageResponse
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Modifiers", meta=(DisplayPriority="2"))
	TArray<FDeltaVelocityDamageHandlerData> ModifierData;

};

