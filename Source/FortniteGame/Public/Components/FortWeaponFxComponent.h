// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Math/MathFwd.h"
#include "FortWeaponFxComponent.generated.h"

class AFortWeapon;
class UFXSystemComponent;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortWeaponFxComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortWeaponFxComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION()
	virtual void OnBeamFired(AFortWeapon* Weapon, bool bUsePersistentBeam, UFXSystemComponent* PSC, const FVector& BeamOrigin, const FVector& HitLocation);

};

