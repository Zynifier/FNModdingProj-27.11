// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortPickupComponent_ItemAttachedActor.generated.h"

class AActor;
class AFortPawn;
class AFortPickup;
class UFortWorldItemDefinition;

UCLASS(BlueprintType, Blueprintable)
class UFortPickupComponent_ItemAttachedActor : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static void AttachActorToPickup(AFortPickup* Pickup, AActor* ActorToAttach);

private:
	UFUNCTION()
	void OnAttachedActorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnPickupPickedUpByPlayer(AFortPickup* SelfActor, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* WorldItemDefinition, FVector PickupLocation);

	UPROPERTY()
	TObjectPtr<AActor> AttachedActor;

};

