// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpawnMachineEnabledConfig.generated.h"

USTRUCT(BlueprintType)
struct FSpawnMachineEnabledConfig
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnMachineEnabledConfig")
	uint8 Team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnMachineEnabledConfig")
	uint8 Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnMachineEnabledConfig")
	bool bAllowAnyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnMachineEnabledConfig")
	bool bIsEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnMachineEnabledConfig")
	bool bInvertTeamSelection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnMachineEnabledConfig")
	bool bInvertClassSelection;

};

