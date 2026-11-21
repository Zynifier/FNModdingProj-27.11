// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortTypes.h"
#include "FortGameplayAbility_ObserveDuels.generated.h"

class AActor;
class AController;
class AFortPlayerPawn;
class UPrimitiveComponent;
enum class EDuelState : uint8;

UCLASS()
class UFortGameplayAbility_ObserveDuels : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddDuel(AFortPlayerPawn* ChallengerPlayerPawn, AFortPlayerPawn* ChallengedNPC);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDuelChange(EDuelState NewDuelState, const FDuelOverlayData& ChangedDuelOverlayData);

private:
	UFUNCTION()
	void HandleDuelistDeath(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

};

