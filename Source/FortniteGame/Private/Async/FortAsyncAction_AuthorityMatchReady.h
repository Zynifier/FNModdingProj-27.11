// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_AuthorityMatchReady.generated.h"

class UFortAsyncAction_AuthorityMatchReady;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAuthorityMatchReadyAsyncDelegate);

UCLASS()
class UFortAsyncAction_AuthorityMatchReady : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_AuthorityMatchReady* MatchReadyAsync(UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On Ready (Authority Only!)"))
	FAuthorityMatchReadyAsyncDelegate OnReady;

};

