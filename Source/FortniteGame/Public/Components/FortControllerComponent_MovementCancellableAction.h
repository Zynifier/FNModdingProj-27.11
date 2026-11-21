// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_MovementCancellableAction.generated.h"

class UGameplayAbility;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_MovementCancellableAction : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortControllerComponent_MovementCancellableAction")
	TObjectPtr<UGameplayAbility> CurrentAbility;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortControllerComponent_MovementCancellableAction")
	TMap<FGameplayTag, FScalableFloat> LeashDistance;

};

