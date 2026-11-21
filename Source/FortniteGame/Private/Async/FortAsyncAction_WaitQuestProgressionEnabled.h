// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_WaitQuestProgressionEnabled.generated.h"

class UFortAsyncAction_WaitQuestProgressionEnabled;
class UObject;

UCLASS()
class UFortAsyncAction_WaitQuestProgressionEnabled : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FQuestProgressionEnabledDelegate);

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_WaitQuestProgressionEnabled* WaitQuestProgressionEnabled(UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable)
	FQuestProgressionEnabledDelegate OnQuestProgressionEnabled;

};

