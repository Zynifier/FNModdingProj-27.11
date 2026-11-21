// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_AIFormation.generated.h"

class AActor;
class AController;
class AFortPawn;
class UPrimitiveComponent;

USTRUCT()
struct FFortAthenaAIFormationSlotRuntime
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector LocalLocation;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> UserPawn;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class FORTNITEAI_API UFortPawnComponent_AIFormation : public UFortPawnComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnUserDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(EditDefaultsOnly, Category="Formation Component")
	TArray<FVector> Slots;

	UPROPERTY(EditDefaultsOnly, Category="Formation Component", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float MaxDistanceFromSlotToSprint;

	UPROPERTY(Transient)
	TArray<FFortAthenaAIFormationSlotRuntime> RuntimeSlots;

	UPROPERTY(Transient)
	float MaxDistanceFromSlotToSprintSqr;

};

