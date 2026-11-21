// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "FortBRLogicRemovalComponent.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortBRLogicRemovalComponent : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortBRLogicRemovalComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

