// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortMissionGenerationManager.generated.h"

UENUM()
enum class EFortCheatMissionGenType : uint8
{
	NewGeneration = 0,
	OldGeneration = 1,
	Max_None = 2,
};

UCLASS()
class AFortMissionGenerationManager : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	EFortCheatMissionGenType CheatMissionGenType;

};

