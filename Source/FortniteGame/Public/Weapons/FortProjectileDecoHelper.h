// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Weapons/FortDecoHelper.h"
#include "FortProjectileDecoHelper.generated.h"

UCLASS()
class AFortProjectileDecoHelper : public AFortDecoHelper
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetInvalidThrowTrapPosition() const;

	UFUNCTION(BlueprintCallable)
	void OnProjectileThrown();

	UFUNCTION(BlueprintCallable)
	void SetGrenadeTrajectoryHitResult(const FHitResult& InHitResult);

	UFUNCTION(BlueprintCallable)
	void SetShowDecoPreview(bool bInShowDecoPreview);

protected:
	UFUNCTION(BlueprintCallable)
	void Tick(float DeltaSeconds);

};

