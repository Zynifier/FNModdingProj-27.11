// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AI/Tasks/AITask_ExecuteAbility.h"
#include "FortAITask_ExecuteAbility.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;

UCLASS(MinimalAPI)
class UFortAITask_ExecuteAbility : public UAITask_ExecuteAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnInjectedHitResultDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

};

