// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UObject/NoExportTypes.h"
#include "UIKit/ContextMenu/UIKitContextMenuActionInfo.h"
#include "UIKitContextMenu.generated.h"

class UUIKitContextMenuActionContext;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UUIKitContextMenu : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetInteractionContext(UUIKitContextMenuActionContext* InContext);

private:
	UPROPERTY(Transient)
	TObjectPtr<UUIKitContextMenuActionContext> ActionContext;

};

UCLASS(BlueprintType)
class UUIKitContextMenuActionContext : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddInteraction(const FUIKitContextMenuActionInfo& InActionInfo, const FOnContextMenuInteractionDelegate& InInteractionDelegate);

};

