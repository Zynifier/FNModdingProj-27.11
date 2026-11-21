// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortScoutDroneMovementComponent.generated.h"

UCLASS(BlueprintType)
class UFortScoutDroneMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector LocalInputState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortScoutDroneMovementComponent")
	FVector LastInputState;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortScoutDroneMovementComponent")
	FVector ReplicatedAcceleration;

private:
	UPROPERTY(EditDefaultsOnly, Category="Character Movement: Flying", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	FScalableFloat StrafeInputMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Character Movement: Flying", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	FScalableFloat BacktrackingInputMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Character Movement: Flying", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	FScalableFloat VerticalMovementInputMultiplier;

};

