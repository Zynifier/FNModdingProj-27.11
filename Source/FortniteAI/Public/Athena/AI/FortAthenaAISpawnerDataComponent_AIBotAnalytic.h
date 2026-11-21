// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_AnalyticBase.h"
#include "FortAthenaAISpawnerDataComponent_AIBotAnalytic.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_AIBotAnalytic : public UFortAthenaAISpawnerDataComponent_AnalyticBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Common", meta=(AllowPrivateAccess="true"))
	uint8 bUseDescriptorTagSuffix : 1;

	UPROPERTY(EditAnywhere, Category="Analytics", meta=(AllowPrivateAccess="true", EditCondition="!bUseDescriptorTagSuffix"))
	FString BotIDSuffix;

	UPROPERTY(EditAnywhere, Category="Analytics", meta=(AllowPrivateAccess="true"))
	TArray<FScalableFloat> IdleDetectionBucketsCutoffs;

	UPROPERTY(EditAnywhere, Category="Analytics", meta=(AllowPrivateAccess="true"))
	TArray<FScalableFloat> DamageDistanceBuckets;

};

