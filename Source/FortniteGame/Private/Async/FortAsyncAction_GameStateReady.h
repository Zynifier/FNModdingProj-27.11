// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_GameStateReady.generated.h"

class AGameStateBase;
class UFortAsyncAction_GameStateReady;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameStateReadyAsyncDelegate, AGameStateBase*, GameState);

UCLASS()
class UFortAsyncAction_GameStateReady : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_GameStateReady* GameStateReadyAsync(UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable)
	FGameStateReadyAsyncDelegate OnReady;

};

