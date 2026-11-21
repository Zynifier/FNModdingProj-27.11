// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_MiniMapInterfaceReady.generated.h"

class IFortMiniMapInterface;
class UFortAsyncAction_MiniMapInterfaceReady;
class UObject;

UCLASS(meta=(NotBlueprintType="true"))
class UFortAsyncAction_MiniMapInterfaceReady : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMiniMapInterfaceReady, TScriptInterface<IFortMiniMapInterface>, MiniMapInterface);

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_MiniMapInterfaceReady* MiniMapInterfaceReadyAsync(const UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable)
	FOnMiniMapInterfaceReady OnReady;

};

