// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaCurieStatusWidget.h"

bool UAthenaCurieStatusWidget::HasState(FGameplayTag CurieState) const
{
	return false;
}

void UAthenaCurieStatusWidget::OnCurieStateAttachedToSpectator(UObject* InOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag& ElementIdentifier)
{
}

void UAthenaCurieStatusWidget::OnCurieStateDetachedFromSpectator(UObject* InOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag& ElementIdentifier)
{
}

void UAthenaCurieStatusWidget::OnHandleSpectatingChanged(AFortPlayerStateZone* NewSpectatingTarget)
{
}

void UAthenaCurieStatusWidget::OnPlayerStatePawnChanged()
{
}

void UAthenaCurieStatusWidget::SetPlayerState(AFortPlayerStateAthena* PlayerState)
{
}
