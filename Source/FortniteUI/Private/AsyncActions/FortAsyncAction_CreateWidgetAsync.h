// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_CreateWidgetAsync.generated.h"

class APlayerController;
class UFortAsyncAction_CreateWidgetAsync;
class UObject;
class UUserWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreateWidgetAsyncDelegate, UUserWidget*, UserWidget);

UCLASS()
class UFortAsyncAction_CreateWidgetAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_CreateWidgetAsync* CreateWidgetAsync(UObject* WorldContextObject, TSoftClassPtr<UUserWidget> UserWidgetSoftClass, APlayerController* OwningPlayer, bool bSuspendInputUntilComplete = true);

	UPROPERTY(BlueprintAssignable)
	FCreateWidgetAsyncDelegate OnComplete;

};

