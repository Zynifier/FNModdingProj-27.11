// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnComponent.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "FortPawnComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPawnComponent : public UPawnComponent, public IFortHolsterWeaponSourceInterface
{
	GENERATED_BODY()

public:
	FORTNITEGAME_API UFortPawnComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

