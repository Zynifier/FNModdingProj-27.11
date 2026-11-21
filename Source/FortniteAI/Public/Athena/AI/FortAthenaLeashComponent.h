// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortAthenaLeashComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAthenaLeashComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FVector& GetLeashCenter() const;

	UFUNCTION(BlueprintPure)
	float GetLeashRadius() const;

	UFUNCTION(BlueprintPure)
	bool IsInsideLeash(const FVector& Location) const;

	UFUNCTION(BlueprintCallable)
	void SetLeashRadius(float NewRadius);

private:
	UPROPERTY(EditAnywhere, Category="Leash", meta=(AllowPrivateAccess="true"))
	FScalableFloat LeashRadius;

	UPROPERTY(Transient)
	FVector LeashCenter;

	UPROPERTY(Transient)
	float LeashRadiusSqr;

};

