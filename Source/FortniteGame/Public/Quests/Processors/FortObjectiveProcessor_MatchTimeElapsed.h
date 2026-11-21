// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_MatchTimeElapsed.generated.h"

class APlayerController;

USTRUCT(meta=(DisplayName="MatchTimeElapsed", Hidden))
struct FFortObjectiveFilter_MatchTimeElapsed : public FObjectiveFilter
{
	GENERATED_BODY()

};

UCLASS()
class FORTNITEGAME_API UFortObjectiveProcessor_MatchTimeElapsed : public UFortObjectiveProcessor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void UpdateMatchTimeElapsed();

	UPROPERTY(Transient)
	TSet<APlayerController*> RegisteredPlayerControllers;

	UPROPERTY(Transient)
	TSet<APlayerController*> PlayerControllersToUnRegister;

};

