// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_LoadCurrentSubgameProfiles.generated.h"

class AFortPlayerController;
class UFortAsyncAction_LoadCurrentSubgameProfiles;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortLoadCurrentSubgameProfilesCompleteDelegate);

UCLASS()
class UFortAsyncAction_LoadCurrentSubgameProfiles : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_LoadCurrentSubgameProfiles* LoadCurrentSubgameProfiles(AFortPlayerController* PlayerController);

	UPROPERTY(BlueprintAssignable)
	FFortLoadCurrentSubgameProfilesCompleteDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FFortLoadCurrentSubgameProfilesCompleteDelegate OnFailure;

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> PlayerController;

};

