// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortGameplayMessageComponentBase.h"
#include "Net/UnrealNetwork.h"

FGameplayTagContainer UFortGameplayMessageComponentBase::GetChannelId() const
{
	return FGameplayTagContainer();
}

FText UFortGameplayMessageComponentBase::GetDisabledReason() const
{
	return FText();
}

int32 UFortGameplayMessageComponentBase::GetMessageChannelIndex() const
{
	return int32();
}

FText UFortGameplayMessageComponentBase::GetMessageDescription() const
{
	return FText();
}

FText UFortGameplayMessageComponentBase::GetMessageName() const
{
	return FText();
}

bool UFortGameplayMessageComponentBase::IsChannelIdSet() const
{
	return false;
}

bool UFortGameplayMessageComponentBase::IsEnabled() const
{
	return false;
}

void UFortGameplayMessageComponentBase::OnRep_ChannelIds()
{
}

void UFortGameplayMessageComponentBase::SetChannelId(const FGameplayTagContainer& NewChannelIds)
{
}

void UFortGameplayMessageComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameplayMessageComponentBase, ChannelIds);
}
