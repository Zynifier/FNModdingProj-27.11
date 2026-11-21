// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortWeaponFxComponent.h"
#include "FortWeaponFxComponent_ChargeAimLocation.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortWeaponFxComponent_ChargeAimLocation : public UFortWeaponFxComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	void GetCachedDamageStartAndAim(FVector& OutDamageStartLocation, FVector& OutAimDirection) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetReplicatedAimOffset(FVector AimOffset);

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	float AimSmoothingSpeed;

private:
	UPROPERTY(Replicated)
	FVector ReplicatedAimOffset;

};

