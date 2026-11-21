// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_ThrowTrajectory.generated.h"

class AFortPlayerPawn;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEGAME_API UFortGameplayAbility_ThrowTrajectory : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FVector GetGrenadeOffsetFromMovementMode(AFortPlayerPawn* PlayerPawn) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parent Defaults|Location And Rotation")
	FVector GrenadeTargetingOriginOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parent Defaults|Location And Rotation")
	FVector GrenadeTargetingOriginOffsetCrouched;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parent Defaults|Location And Rotation")
	FVector GrenadeTargetingOriginOffsetSliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parent Defaults|Location And Rotation")
	FVector GrenadeTargetingOriginOffsetWater;

};

