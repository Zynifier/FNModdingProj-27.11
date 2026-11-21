// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortEventName.h"
#include "AsyncAction_WaitForScriptedActions.generated.h"

class AFortScriptedActionManager;
class UAsyncAction_WaitForScriptedActions;
class UObject;

UCLASS()
class UAsyncAction_WaitForScriptedActions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinishedDelegate);

public:
	UFUNCTION(BlueprintCallable, Category="Global UI Context", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UAsyncAction_WaitForScriptedActions* WaitForAllScriptedActions(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Global UI Context", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UAsyncAction_WaitForScriptedActions* WaitForMultipleScriptedActions(UObject* WorldContextObject, TArray<FFortClientEventName> EventTypes);

	UFUNCTION(BlueprintCallable, Category="Global UI Context", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UAsyncAction_WaitForScriptedActions* WaitForScriptedAction(UObject* WorldContextObject, FFortClientEventName EventType);

	UPROPERTY(BlueprintAssignable)
	FOnFinishedDelegate Finished;

private:
	UPROPERTY()
	TWeakObjectPtr<AFortScriptedActionManager> WeakActionManager;

};

