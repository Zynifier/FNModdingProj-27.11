// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortClientEvent.h"
#include "FortClientEventInterface.h"
#include "FortEventName.h"
#include "FortScriptedAction.h"
#include "FortScriptedActionManager.generated.h"

class AFortScriptedAction;
class UObject;

USTRUCT()
struct FFortAvailableScriptedAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortScriptedActionParams Params;

	UPROPERTY()
	TObjectPtr<AFortScriptedAction> ActionDefaults;

};

UCLASS(MinimalAPI)
class AFortScriptedActionManager : public AActor, public IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ClientEvent", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	void HandleClientEvent_Undefined(UObject* EventSource, UObject* EventFocus, const FFortClientEvent& ClientEvent);

protected:
	UPROPERTY()
	TArray<TObjectPtr<AFortScriptedAction>> ActiveScriptedActions;

	UPROPERTY()
	TArray<FFortAvailableScriptedAction> AvailableScriptedActions;

	UPROPERTY()
	TArray<FFortAvailableScriptedAction> PendingAvailableScriptedActions;

	UPROPERTY()
	TArray<FFortClientEventName> PendingClientEvents;

	UPROPERTY()
	bool bIsProcessingClientEvent;

};

