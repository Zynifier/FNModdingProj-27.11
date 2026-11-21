// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortItemShopSubsystem.generated.h"

class UFortCommunityVotingManager;

UCLASS()
class UFortItemShopSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortCommunityVotingManager> VotingManager;

};

