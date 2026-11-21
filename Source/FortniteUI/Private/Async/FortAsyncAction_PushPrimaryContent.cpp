// Copyright Epic Games, Inc. All Rights Reserved.

#include "Async/FortAsyncAction_PushPrimaryContent.h"

UFortAsyncAction_PushPrimaryContent* UFortAsyncAction_PushPrimaryContent::PushPrimaryContentClassAsync(const UUserWidget* ContextWidget, const TSubclassOf<UCommonActivatableWidget> WidgetClass)
{
	return nullptr;
}

UFortAsyncAction_PushPrimaryContent* UFortAsyncAction_PushPrimaryContent::PushPrimaryContentClassAsyncForPlayer(const APlayerController* ContextPC, const TSubclassOf<UCommonActivatableWidget> WidgetClass)
{
	return nullptr;
}

UFortAsyncAction_PushPrimaryContent* UFortAsyncAction_PushPrimaryContent::PushPrimaryContentSoftClassAsync(const UUserWidget* ContextWidget, const TSoftClassPtr<UCommonActivatableWidget> SoftWidgetClass)
{
	return nullptr;
}

UFortAsyncAction_PushPrimaryContent* UFortAsyncAction_PushPrimaryContent::PushPrimaryContentSoftClassAsyncForPlayer(const APlayerController* ContextPC, const TSoftClassPtr<UCommonActivatableWidget> SoftWidgetClass)
{
	return nullptr;
}
