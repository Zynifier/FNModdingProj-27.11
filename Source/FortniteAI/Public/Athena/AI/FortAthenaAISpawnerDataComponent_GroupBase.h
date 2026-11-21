// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_GroupBase.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_GroupBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Group Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat EnableGroupComponent;

	UPROPERTY(EditDefaultsOnly, Category="Group Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanBeGroupLeader;

	UPROPERTY(EditDefaultsOnly, Category="Formation Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat EnableFormationComponent;

	UPROPERTY(EditDefaultsOnly, Category="Formation Parameters", meta=(AllowPrivateAccess="true"))
	TArray<FVector> FormationSlots;

	UPROPERTY(EditDefaultsOnly, Category="Formation Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceFromSlotToSprint;

};

