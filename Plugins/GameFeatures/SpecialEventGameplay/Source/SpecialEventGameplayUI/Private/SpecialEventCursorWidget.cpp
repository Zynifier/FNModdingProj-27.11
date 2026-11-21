// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventCursorWidget.h"

USpecialEventCursorWidget::USpecialEventCursorWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FGameplayTagContainer USpecialEventCursorWidget::GetCursorModeTags() const
{
	return FGameplayTagContainer();
}

void USpecialEventCursorWidget::OnCursorModeChanged(USpecialEventCursorPawnComponent* InCursorPawnComponent, const FGameplayTag& NewCursorModeTag, const FGameplayTag& OldCursorModeTag)
{
}

void USpecialEventCursorWidget::OnDesiredVisibilityChanged(USpecialEventCursorPawnComponent* InCursorPawnComponent, const FGameplayTag& CursorModeTag, const bool bShouldBeVisible)
{
}

void USpecialEventCursorWidget::OnViewportLocationChanged_Implementation(USpecialEventCursorPawnComponent* InCursorPawnComponent, const FVector2D& NormalizedLocation, const FVector2D& ViewportLocation)
{
}
