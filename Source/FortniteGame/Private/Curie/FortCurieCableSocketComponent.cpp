// Copyright Epic Games, Inc. All Rights Reserved.

#include "Curie/FortCurieCableSocketComponent.h"

bool UFortCurieCableSocketComponent::Connect(FFortCurieCableSocketIdentifier SourceSocketIdentifier, AActor* DestinationActor, FFortCurieCableSocketIdentifier DestinationSocketIdentifier)
{
	return false;
}

bool UFortCurieCableSocketComponent::Disconnect(FFortCurieCableSocketIdentifier SourceSocketIdentifier)
{
	return false;
}

bool UFortCurieCableSocketComponent::GetCableSocketConnection(FFortCurieCableSocketIdentifier SourceSocketIdentifier, AActor*& ConnectedActor, FFortCurieCableSocketIdentifier& ConnectedSocketIdentifier) const
{
	return false;
}

void UFortCurieCableSocketComponent::GetCableSocketIdentifiers(TArray<FFortCurieCableSocketIdentifier>& SocketIdentifiers) const
{
}

FVector UFortCurieCableSocketComponent::GetCableSocketWorldLocation(const FFortCurieCableSocketIdentifier& SocketIdentifier) const
{
	return FVector();
}

FGameplayTagContainer UFortCurieCableSocketComponent::GetOngoingReceivedElementSignals(FFortCurieCableSocketIdentifier SourceSocketIdentifier) const
{
	return FGameplayTagContainer();
}

float UFortCurieCableSocketComponent::GetReceivedElementSignalMagnitude(FFortCurieCableSocketIdentifier SocketIdentifier, FGameplayTag ElementTag) const
{
	return float();
}

FGameplayTagContainer UFortCurieCableSocketComponent::GetReceivedElementSignals(FFortCurieCableSocketIdentifier SourceSocketIdentifier) const
{
	return FGameplayTagContainer();
}

bool UFortCurieCableSocketComponent::IsCableSocketConnected(FFortCurieCableSocketIdentifier SocketIdentifier) const
{
	return false;
}

bool UFortCurieCableSocketComponent::IsReceivedElementSignalActive(FFortCurieCableSocketIdentifier SocketIdentifier, FGameplayTag ElementTag) const
{
	return false;
}

void UFortCurieCableSocketComponent::SendSignal(FFortCurieCableSocketIdentifier SourceSocketIdentifier, FGameplayTag ElementTag, float Magnitude)
{
}
