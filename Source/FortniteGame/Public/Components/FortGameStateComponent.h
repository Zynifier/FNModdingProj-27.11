// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "FortGameStateComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent : public UGameStateComponent
{
	GENERATED_BODY()

public:
	FORTNITEGAME_API UFortGameStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

