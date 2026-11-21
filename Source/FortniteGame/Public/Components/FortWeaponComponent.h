// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "FortWeaponComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortWeaponComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	FORTNITEGAME_API UFortWeaponComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

