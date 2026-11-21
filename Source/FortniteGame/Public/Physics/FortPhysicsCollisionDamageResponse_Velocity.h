// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Physics/FortPhysicsCollisionDamageResponse.h"
#include "Physics/FortPhysicsCollisionHandler.h"
#include "FortPhysicsCollisionDamageResponse_Velocity.generated.h"

USTRUCT()
struct FVelocityDamageHandlerData : public FCollisionResponseBaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VelocityDamageHandlerData")
	TArray<FScalableFloat> PureVelocityBuckets;

	UPROPERTY(EditAnywhere, Category="VelocityDamageHandlerData")
	TArray<FScalableFloat> DamageBuckets;

	UPROPERTY(EditAnywhere, Category="VelocityDamageHandlerData")
	bool bScaleLinearlyInOneBucket;

	UPROPERTY(EditAnywhere, Category="VelocityDamageHandlerData", meta=(EditCondition="bScaleLinearlyInOneBucket = false"))
	bool bEnableMassControl;

	UPROPERTY(EditAnywhere, Category="VelocityDamageHandlerData", meta=(EditCondition="bEnableMassControl"))
	TArray<FScalableFloat> MassBuckets;

	UPROPERTY(EditAnywhere, Category="VelocityDamageHandlerData", meta=(EditCondition="bEnableMassControl"))
	TArray<FScalableFloat> MassMultiplierBuckets;

};

UCLASS(meta=(TitleProperty="Velocity Damage Handler"))
class UFortPhysicsCollisionDamageResponse_Velocity : public UFortPhysicsCollisionDamageResponse
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Modifiers")
	TArray<FVelocityDamageHandlerData> ModifierData;

};

