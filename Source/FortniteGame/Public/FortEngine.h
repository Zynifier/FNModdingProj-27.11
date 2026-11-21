// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameEngine.h"
#include "FortEngine.generated.h"

UCLASS(MinimalAPI)
class UFortEngine : public UGameEngine
{
	GENERATED_BODY()

private:
	UFUNCTION(Exec)
	void StartFortBench(const FString& ReplayName);

	UPROPERTY(Config)
	TArray<FString> PreCSVProfileExecCommands;

	UPROPERTY(Config)
	TArray<FString> PostCSVProfileExecCommands;

};

