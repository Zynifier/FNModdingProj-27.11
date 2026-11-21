// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator_AI.h"
#include "FortAthenaMutator_AI_SignificanceBasedUpdate.generated.h"

class UFortMovementComp_Character;

USTRUCT(BlueprintType)
struct FAIPawnSignificanceBasedMovementUpdateBucket
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AIPawnSignificanceBasedMovementUpdateBucket")
	FScalableFloat MinDistanceFromPlayer;

	UPROPERTY(EditDefaultsOnly, Category="AIPawnSignificanceBasedMovementUpdateBucket")
	FScalableFloat MaxDistanceFromPlayer;

	UPROPERTY(EditDefaultsOnly, Category="AIPawnSignificanceBasedMovementUpdateBucket")
	FScalableFloat FramesPerUpdate;

};

USTRUCT()
struct FAIPawnSignificanceBasedMovementUpdateBucketGroup
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMovementComp_Character>> MovementComponentsInGroup;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_AI_SignificanceBasedUpdate : public AFortAthenaMutator_AI
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Significance Based Movement Updates")
	FScalableFloat bShouldUseSignificanceBasedMovementUpdatesOnClient;

	UPROPERTY(EditDefaultsOnly, Category="Significance Based Movement Updates")
	FScalableFloat bShouldUseSignificanceBasedMovementUpdatesOnServer;

	UPROPERTY(EditDefaultsOnly, Category="Significance Based Movement Updates")
	TArray<FAIPawnSignificanceBasedMovementUpdateBucket> SignificanceBasedMovementUpdateBuckets;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMovementComp_Character>> SignificanceBasedMovementUpdateManagedComponents;

};

