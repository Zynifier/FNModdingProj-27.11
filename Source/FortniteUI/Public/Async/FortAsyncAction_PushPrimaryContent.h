// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_PushPrimaryContent.generated.h"

class APlayerController;
class UCommonActivatableWidget;
class UFortAsyncAction_PushPrimaryContent;
class UUserWidget;

UCLASS(meta=(NotBlueprintType="true"))
class UFortAsyncAction_PushPrimaryContent : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPrimaryContentPushed, UCommonActivatableWidget*, ActivatableWidget);

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_PushPrimaryContent* PushPrimaryContentClassAsync(const UUserWidget* ContextWidget, const TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_PushPrimaryContent* PushPrimaryContentClassAsyncForPlayer(const APlayerController* ContextPC, const TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_PushPrimaryContent* PushPrimaryContentSoftClassAsync(const UUserWidget* ContextWidget, const TSoftClassPtr<UCommonActivatableWidget> SoftWidgetClass);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_PushPrimaryContent* PushPrimaryContentSoftClassAsyncForPlayer(const APlayerController* ContextPC, const TSoftClassPtr<UCommonActivatableWidget> SoftWidgetClass);

	UPROPERTY(BlueprintAssignable)
	FOnPrimaryContentPushed OnPrimaryContentPushed;

};

