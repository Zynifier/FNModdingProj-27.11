// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlaysetLevelStreamComponent.h"
#include "Net/UnrealNetwork.h"

void UPlaysetLevelStreamComponent::ClearPlayset()
{
}

const UFortPlaysetItemDefinition* UPlaysetLevelStreamComponent::GetCurrentPlayset() const
{
	return nullptr;
}

bool UPlaysetLevelStreamComponent::IsLoading() const
{
	return false;
}

void UPlaysetLevelStreamComponent::OnFinishedLoading()
{
}

void UPlaysetLevelStreamComponent::OnFinishedUnloading()
{
}

void UPlaysetLevelStreamComponent::OnRep_ClientPlaysetData()
{
}

void UPlaysetLevelStreamComponent::SetPlayset(const UFortPlaysetItemDefinition* NewPlayset)
{
}

void UPlaysetLevelStreamComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlaysetLevelStreamComponent, CurrentPlayset);
	DOREPLIFETIME(UPlaysetLevelStreamComponent, ClientPlaysetData);
}
