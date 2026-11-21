// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_QueueModalWidget.generated.h"

class APlayerController;
class UCommonActivatableWidget;
class UFortAsyncAction_QueueModalWidget;
class ULocalPlayer;
class UUserWidget;

UCLASS(meta=(NotBlueprintType="true"))
class UFortAsyncAction_QueueModalWidget : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnModalWidgetQueued, UCommonActivatableWidget*, ActivatableWidget);

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_QueueModalWidget* QueueModalWidgetClassAsync(const UUserWidget* ContextWidget, const TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_QueueModalWidget* QueueModalWidgetClassAsyncForLocalPlayer(const ULocalPlayer* LocalPlayer, const TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_QueueModalWidget* QueueModalWidgetClassAsyncForPlayer(const APlayerController* PlayerController, const TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_QueueModalWidget* QueueModalWidgetSoftClassAsync(const UUserWidget* ContextWidget, const TSoftClassPtr<UCommonActivatableWidget> SoftWidgetClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_QueueModalWidget* QueueModalWidgetSoftClassAsyncForLocalPlayer(const ULocalPlayer* LocalPlayer, const TSoftClassPtr<UCommonActivatableWidget> SoftWidgetClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_QueueModalWidget* QueueModalWidgetSoftClassAsyncForPlayer(const APlayerController* PlayerController, const TSoftClassPtr<UCommonActivatableWidget> SoftWidgetClass);

	UPROPERTY(BlueprintAssignable)
	FOnModalWidgetQueued OnModalWidgetQueued;

};

