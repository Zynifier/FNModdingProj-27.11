// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PlayerStateComponent.h"
#include "FortPlayerStateComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerStateComponent : public UPlayerStateComponent
{
	GENERATED_BODY()

public:
	FORTNITEGAME_API UFortPlayerStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

