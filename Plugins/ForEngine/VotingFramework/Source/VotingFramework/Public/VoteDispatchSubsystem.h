// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "VotingFrameworkTypes.h"
#include "VoteDispatchSubsystem.generated.h"

UCLASS()
class UVoteDispatchSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FVoteSelectionResults> VotingResults;

};

