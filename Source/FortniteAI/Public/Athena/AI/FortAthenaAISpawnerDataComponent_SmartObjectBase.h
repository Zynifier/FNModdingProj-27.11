// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_SmartObjectBase.generated.h"

class UFortAthenaAISmartObjectActivity;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_SmartObjectBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat Enabled;

	UPROPERTY(EditDefaultsOnly, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat ChooseClosestSmartObject;

	UPROPERTY(EditDefaultsOnly, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat UnreachableBanDuration;

	UPROPERTY(EditDefaultsOnly, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat SelectedSmartObjectExpirationDelay;

	UPROPERTY(EditDefaultsOnly, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat GlobalSmartObjectCooldownOnFinished;

	UPROPERTY(EditDefaultsOnly, Category="Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat GlobalSmartObjectCooldownOnInterrupted;

	UPROPERTY(VisibleAnywhere, Category="Activities List", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UFortAthenaAISmartObjectActivity>> SmartObjectActivitiesCombined;

	UPROPERTY(EditDefaultsOnly, Category="Activities List", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UFortAthenaAISmartObjectActivity>> SmartObjectActivitiesToAdd;

	UPROPERTY(EditDefaultsOnly, Category="Activities List", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UFortAthenaAISmartObjectActivity>> SmartObjectActivitiesToRemove;

};

