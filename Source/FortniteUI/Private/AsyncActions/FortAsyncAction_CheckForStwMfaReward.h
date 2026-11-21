// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_CheckForStwMfaReward.generated.h"

class AFortPlayerController;
class UFortAsyncAction_CheckForStwMfaReward;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortCheckForStwMfaRewardCompleteDelegate);

UCLASS()
class UFortAsyncAction_CheckForStwMfaReward : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_CheckForStwMfaReward* CheckForStwMfaReward(AFortPlayerController* PlayerController);

	UPROPERTY(BlueprintAssignable)
	FFortCheckForStwMfaRewardCompleteDelegate OnCompleted;

	UPROPERTY(BlueprintAssignable)
	FFortCheckForStwMfaRewardCompleteDelegate OnFailed;

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> PlayerController;

};

