// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortVoteConfig.h"
#include "UI/FortUINotification.h"
#include "FortMissionVoteUINotification.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortMissionVoteUINotification : public UFortUINotification
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActionTaken();

	UPROPERTY(BlueprintReadOnly, Category="FortMissionVoteUINotification")
	EFortVoteType VoteType;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionVoteUINotification")
	bool bHasVoteEnded;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionVoteUINotification")
	int32 VoteResult;

};

