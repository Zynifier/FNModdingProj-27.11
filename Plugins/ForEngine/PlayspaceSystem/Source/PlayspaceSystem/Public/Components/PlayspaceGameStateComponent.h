// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "PlayspaceGameStateComponent.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class PLAYSPACESYSTEM_API UPlayspaceGameStateComponent : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UPlayspaceGameStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

