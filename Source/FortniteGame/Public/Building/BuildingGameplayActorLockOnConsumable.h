// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActorConsumable.h"
#include "BuildingGameplayActorLockOnConsumable.generated.h"

class AFortPlayerPawn;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorLockOnConsumable : public ABuildingGameplayActorConsumable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalControllersInteractingPawnSet(AFortPlayerPawn* LocalPCPawn);

	UFUNCTION()
	void OnRep_InteractingPawn();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact")
	float SecondsBeforeDeathAfterPickup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact")
	float InteractRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact")
	float PawnInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact")
	float PawnDisableRotationSeconds;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_InteractingPawn, Category="BuildingGameplayActorLockOnConsumable")
	TObjectPtr<AFortPlayerPawn> InteractingPawn;

};

