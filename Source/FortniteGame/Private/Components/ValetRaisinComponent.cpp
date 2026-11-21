// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/ValetRaisinComponent.h"
#include "Net/UnrealNetwork.h"

void UValetRaisinComponent::ClientPickOption()
{
}

UFortItemDefinition* UValetRaisinComponent::GetSource() const
{
	return nullptr;
}

void UValetRaisinComponent::OnRep_Source()
{
}

void UValetRaisinComponent::ServerSelectOption_Implementation(AFortPlayerController* PlayerChoosing, const UFortItemDefinition* MusicSource)
{
}
bool UValetRaisinComponent::ServerSelectOption_Validate(AFortPlayerController* PlayerChoosing, const UFortItemDefinition* MusicSource)
{
	return true;
}

void UValetRaisinComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UValetRaisinComponent, ReplicatedSource);
}
