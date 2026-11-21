// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Physics/FortPhysicsCollisionDamageResponse.h"
#include "Physics/FortPhysicsCollisionHandler.h"
#include "FortPhysicsCollisionDamageResponse_MassDeltaVelocity.generated.h"

class UCurveFloat;

USTRUCT()
struct FMassDeltaVelocityDamageHandlerData : public FCollisionResponseBaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MassDeltaVelocityDamageHandlerData")
	FScalableFloat VelocityDeltaForMaxDamage;

	UPROPERTY(EditAnywhere, Category="MassDeltaVelocityDamageHandlerData")
	FScalableFloat MinRelativeVelocityToDamage;

	UPROPERTY(EditAnywhere, Category="MassDeltaVelocityDamageHandlerData")
	TObjectPtr<UCurveFloat> MassDamageCurve;

	UPROPERTY(EditAnywhere, Category="MassDeltaVelocityDamageHandlerData")
	bool bVehicleImminentDestruction;

};

UCLASS(meta=(TitleProperty="Default Damage Handler"))
class UFortPhysicsCollisionDamageResponse_MassDeltaVelocity : public UFortPhysicsCollisionDamageResponse
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Modifiers")
	TArray<FMassDeltaVelocityDamageHandlerData> ModifierData;

};

