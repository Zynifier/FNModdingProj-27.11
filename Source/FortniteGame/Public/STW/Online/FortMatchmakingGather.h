// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortMatchmakingPolicy.h"
#include "FortMatchmakingGather.generated.h"

UCLASS()
class UFortMatchmakingGather : public UFortMatchmakingPolicy
{
	GENERATED_BODY()

private:
	UPROPERTY()
	float ChanceToJoinInProgress;

};

