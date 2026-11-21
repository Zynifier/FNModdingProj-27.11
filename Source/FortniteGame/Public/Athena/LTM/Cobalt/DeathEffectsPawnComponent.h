// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnComponent.h"
#include "DeathEffectsPawnComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UDeathEffectsPawnComponent : public UPawnComponent
{
	GENERATED_BODY()

public:
	UDeathEffectsPawnComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void ClientPlayWinnerDeathEffects();

};

