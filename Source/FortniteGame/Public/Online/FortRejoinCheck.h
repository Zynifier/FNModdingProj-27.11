// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RejoinCheck.h"
#include "FortRejoinCheck.generated.h"

UENUM()
enum class EJoinServerState : uint8
{
	Inactive = 0,
	Rejoin = 1,
	Tutorial = 2,
	Abandon = 3,
};

UCLASS(MinimalAPI)
class UFortRejoinCheck : public URejoinCheck
{
	GENERATED_BODY()

private:
	UPROPERTY()
	bool bAbandonAfterCheck;

	UPROPERTY()
	bool bAttemptingAbandon;

	UPROPERTY()
	EJoinServerState CurrentJoinState;

};

