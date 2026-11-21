// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortAthenaNPCLoopStateComponent.generated.h"

class AActor;
class AController;
class AFortPawn;
class UFortAthenaAIRuntimeParameters_AIBotLoopSettings;
class UPrimitiveComponent;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaNPCLoopStateComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void InitLoopState(AFortPawn* PawnOwner);

	UFUNCTION()
	void OnOwnerPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

private:
	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortAthenaNPCLoopStateComponent", meta=(AllowPrivateAccess="true"))
	uint8 bSpawnOutsideTheLoop : 1;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_AIBotLoopSettings> RuntimeLoopSettings;

};

