// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "ShielderCollisionHelperComponent.generated.h"

class ABuildingGameplayActor;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UShielderCollisionHelperComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UShielderCollisionHelperComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Category="ShielderCollisionHelperComponent")
	TObjectPtr<ABuildingGameplayActor> ShielderBGA;

	UPROPERTY(EditDefaultsOnly, Category="ShielderCollisionHelperComponent")
	FVector StaticOffset;

	UPROPERTY(EditDefaultsOnly, Category="ShielderCollisionHelperComponent")
	FVector AimOffset;

	UPROPERTY(EditDefaultsOnly, Category="ShielderCollisionHelperComponent")
	FVector AimOffset2D;

	UPROPERTY(EditDefaultsOnly, Category="ShielderCollisionHelperComponent")
	float PitchMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="ShielderCollisionHelperComponent")
	float PitchMin;

	UPROPERTY(EditDefaultsOnly, Category="ShielderCollisionHelperComponent")
	float PitchMax;

	UPROPERTY(EditDefaultsOnly, Category="ShielderCollisionHelperComponent")
	FScalableFloat ShouldUpdateShielderSkelMesh;

};

