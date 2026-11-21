// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortWeaponFxComponent.h"
#include "FortWeaponFxComponent_Beam.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortWeaponFxComponent_Beam : public UFortWeaponFxComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Effects")
	bool bAttachBeamToMuzzle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Effects")
	bool bUseBeamSmoothing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Effects")
	bool bSpawnImpactFXAtInterpedBeamEndpoints;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Effects")
	float ImpactFxPerSecond;

};

