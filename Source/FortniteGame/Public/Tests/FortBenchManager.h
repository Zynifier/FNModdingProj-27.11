// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortBenchManager.generated.h"

class UWorld;

UCLASS()
class UFortBenchManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void StopFortBench(UWorld* InWorld);

};

