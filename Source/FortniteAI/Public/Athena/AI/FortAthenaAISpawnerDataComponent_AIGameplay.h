// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_GameplayBase.h"
#include "FortAthenaAISpawnerDataComponent_AIGameplay.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAISpawnerDataComponent_AIGameplay : public UFortAthenaAISpawnerDataComponent_GameplayBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Sound", meta=(AllowPrivateAccess="true"))
	float MoveSoundStimulusBroadcastInterval;

	UPROPERTY(EditAnywhere, Category="Sound", meta=(AllowPrivateAccess="true"))
	float MaxMoveSoundRange;

	UPROPERTY(EditAnywhere, Category="Sound", meta=(AllowPrivateAccess="true"))
	uint8 bGenerateSoundInAllMovementModes : 1;

	UPROPERTY(EditAnywhere, Category="PawnFeatures", meta=(AllowPrivateAccess="true"))
	FScalableFloat DefaultLifespanAfterDeath;

	UPROPERTY(EditAnywhere, Category="PawnFeatures", meta=(AllowPrivateAccess="true"))
	EFortAthenaAISpawnerDataComponentTriBool IsAlwaysGameplayRelevantOverride;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	TArray<FPickupTagConvertInfo> PickupTagConvertInfos;

};

