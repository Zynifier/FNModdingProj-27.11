// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_TimeOfDayManagerReady.generated.h"

class IFortTimeOfDayManagerInterface;
class UFortAsyncAction_TimeOfDayManagerReady;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTimeOfDayManagerReadyAsyncDelegate, TScriptInterface<IFortTimeOfDayManagerInterface>, TimeOfDayManager);

UCLASS()
class UFortAsyncAction_TimeOfDayManagerReady : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_TimeOfDayManagerReady* GetTimeOfDayManagerReady(UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable)
	FTimeOfDayManagerReadyAsyncDelegate OnReady;

};

