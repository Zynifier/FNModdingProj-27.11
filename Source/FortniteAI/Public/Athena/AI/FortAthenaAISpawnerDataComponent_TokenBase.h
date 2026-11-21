// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_TokenBase.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_TokenBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Token Provider Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat EnableTokenProviderComponent;

	UPROPERTY(EditDefaultsOnly, Category="Token Provider Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat TokenMaxCount;

	UPROPERTY(EditDefaultsOnly, Category="Token Consumer Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat EnableTokenConsumerComponent;

	UPROPERTY(EditDefaultsOnly, Category="Token Consumer Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat TokenHoldMinDuration;

	UPROPERTY(EditDefaultsOnly, Category="Token Consumer Parameters", meta=(AllowPrivateAccess="true"))
	FScalableFloat TokenHoldMaxDuration;

};

