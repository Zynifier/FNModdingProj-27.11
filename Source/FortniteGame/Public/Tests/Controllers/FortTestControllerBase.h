// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GauntletTestController.h"
#include "FortTestControllerBase.generated.h"

USTRUCT()
struct FSmokeTestResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TestStep;

	UPROPERTY()
	FString TestSummary;

	UPROPERTY()
	bool bWasExecuted;

	UPROPERTY()
	bool bPassed;

	UPROPERTY()
	FString ResultMessage;

};

UCLASS()
class UFortTestControllerBase : public UGauntletTestController
{
	GENERATED_BODY()

public:
	UFortTestControllerBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

