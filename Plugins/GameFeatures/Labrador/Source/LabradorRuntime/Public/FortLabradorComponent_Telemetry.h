// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AI/Components/FortAIComponent_Telemetry.h"
#include "FortLabradorComponent_Telemetry.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;

UENUM(BlueprintType)
enum class ELabradorDespawnReason : uint8
{
	DeathByPlayer = 0,
	DeathByBot = 1,
	DeathByAIPawn = 2,
	DeathByStorm = 3,
	Teleport = 4,
	Unknown = 5,
};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortLabradorComponent_Telemetry : public UFortAIComponent_Telemetry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Labrador - Telemetry")
	void OnTeleport();

	UFUNCTION(BlueprintCallable, Category="Labrador - Telemetry")
	void OnWakeUp(AActor* GoalActor);

private:
	UFUNCTION()
	void OnDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(Transient)
	bool bWasAwake;

	UPROPERTY(Transient)
	FString InstigatorAwakeNetIDString;

	UPROPERTY(Transient)
	ELabradorDespawnReason DespawnReason;

	UPROPERTY(Transient)
	float DamageReceivedFromPlayers;

};

