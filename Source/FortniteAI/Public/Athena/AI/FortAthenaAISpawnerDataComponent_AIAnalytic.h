// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_AnalyticBase.h"
#include "FortAthenaAISpawnerDataComponent_AIAnalytic.generated.h"

UCLASS()
class UFortAthenaAIRuntimeParameters_AIAnalytic : public UFortAthenaAIRuntimeParameters_Analytic
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FString AnalyticUniqueID;

	UPROPERTY(Transient)
	FString AIType;

	UPROPERTY(Transient)
	uint8 bShouldSendSpawnEvents : 1;

	UPROPERTY(Transient)
	uint8 bShouldRecordGrabbedPickups : 1;

	UPROPERTY(Transient)
	uint8 bShouldRecordDroppedPickups : 1;

	UPROPERTY(Transient)
	uint8 bShouldRecordDeathInstigator : 1;

	UPROPERTY(Transient)
	uint8 bShouldRecordRegularDowns : 1;

	UPROPERTY(Transient)
	uint8 bShouldRecordTetheredDowns : 1;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_AIAnalytic : public UFortAthenaAISpawnerDataComponent_AnalyticBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	FString AIType;

	UPROPERTY(EditAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldSendSpawnEvents;

	UPROPERTY(EditAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldRecordGrabbedPickups;

	UPROPERTY(EditAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldRecordDroppedPickups;

	UPROPERTY(EditAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldRecordDeathInstigator;

	UPROPERTY(EditAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldRecordRegularDowns;

	UPROPERTY(EditAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldRecordTetheredDowns;

};

