// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Mobile/RadialBacchusButtonBase.h"

void URadialBacchusButtonBase::GameplayTagCallback(const FGameplayTag Tag, int32 NewCount)
{
}

FGameplayTag URadialBacchusButtonBase::GetListenedGameplayTag()
{
	return FGameplayTag();
}

float URadialBacchusButtonBase::GetRemainingDuration() const
{
	return float();
}

void URadialBacchusButtonBase::HandleUIGameplayCue(FName CueName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters)
{
}

bool URadialBacchusButtonBase::HasActiveCooldown() const
{
	return false;
}

void URadialBacchusButtonBase::OnPlayerPawnSet()
{
}

void URadialBacchusButtonBase::ReceiveRadialProgressEvent(FName EventName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters)
{
}

void URadialBacchusButtonBase::SetListenedGameplayTag(FGameplayTag InListenedTag)
{
}

void URadialBacchusButtonBase::StartUpdateCooldown()
{
}

void URadialBacchusButtonBase::StopUpdateCooldown()
{
}

void URadialBacchusButtonBase::UpdateCooldown()
{
}
