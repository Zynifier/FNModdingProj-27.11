// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "FortControllerComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent : public UControllerComponent, public IFortHolsterWeaponSourceInterface
{
	GENERATED_BODY()

public:
	FORTNITEGAME_API UFortControllerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

