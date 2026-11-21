// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_Visibility.h"
#include "FortMobileButtonBehaviorComponent_ScoutDronePickupItems.generated.h"

class UFortControllerComponent_Interaction;

UCLASS()
class UFortMobileButtonBehaviorComponent_ScoutDronePickupItems : public UFortMobileButtonBehaviorComponent_Visibility
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortMobileButtonBehaviorComponent_ScoutDronePickupItems")
	FGameplayTagContainer HoldingItemsTags;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortControllerComponent_Interaction> InteractionComponent;

};

