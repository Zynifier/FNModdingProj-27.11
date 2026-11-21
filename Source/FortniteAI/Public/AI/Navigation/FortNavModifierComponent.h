// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NavModifierComponent.h"
#include "FortNavModifierComponent.generated.h"

class ANavigationData;
class UPrimitiveComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Variable", "Tags", "Cooking", "Collision", "Activation"), meta=(BlueprintSpawnableComponent))
class UFortNavModifierComponent : public UNavModifierComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FORTNITEAI_API void SetComponentAffectingNavMesh(UPrimitiveComponent* InComponentAffectingNavMesh);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Navigation Data")
	float LowSpeedSquareThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Navigation Data")
	float LowSpeedSquareDistanceThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Navigation Data")
	float LowSpeedRotationThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Navigation Data")
	float LowSpeedScaleThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Navigation Data")
	uint8 bAutomaticNavBoundComputation : 1;

	UPROPERTY(EditDefaultsOnly, Category="Navigation Data", meta=(EditCondition="!bAutomaticNavBoundComputation"))
	uint8 bForceFailSafeExtent : 1;

	UPROPERTY(EditDefaultsOnly, Category="Navigation Data", meta=(EditCondition="!bAutomaticNavBoundComputation && bForceFailSafeExtent"))
	float ExtrapolationMultiplierForFailsafeExtent;

	UPROPERTY(EditAnywhere, Category="Navigation Data")
	TArray<TSubclassOf<ANavigationData>> DisableForNavmeshClasses;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> PrimCompAffectingNavMesh;

};

