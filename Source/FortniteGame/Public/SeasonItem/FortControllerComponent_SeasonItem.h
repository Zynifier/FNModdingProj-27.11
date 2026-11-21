// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortControllerComponent_SeasonItem.generated.h"

enum class EAthenaSeasonMapIconState : uint8;

UCLASS(HideCategories=("Trigger"))
class UFortControllerComponent_SeasonItem : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION(Client, Reliable)
	void ClientSetAthenaSeasonItemMapIconState(const FGameplayTag& ItemTag, const EAthenaSeasonMapIconState IconState);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetAthenaSeasonItemMapIconState(const FGameplayTag& ItemTag, const EAthenaSeasonMapIconState IconState);

};

