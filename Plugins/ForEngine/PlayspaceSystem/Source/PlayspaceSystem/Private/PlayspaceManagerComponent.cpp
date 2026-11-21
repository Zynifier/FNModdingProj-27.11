// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlayspaceManagerComponent.h"
#include "Net/UnrealNetwork.h"

UPlayspaceManagerComponent::UPlayspaceManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UPlayspaceManagerComponent::OnPlayerBeginOverlapGameplayVolume(APlayerState* PlayerState, AGameplayVolume* Volume)
{
}

void UPlayspaceManagerComponent::OnPlayerEndOverlapGameplayVolume(APlayerState* PlayerState, AGameplayVolume* Volume)
{
}

void UPlayspaceManagerComponent::OnRep_RootPlayspace()
{
}

bool UPlayspaceManagerComponent::ProcessOverlapEvents(float DeltaTime)
{
	return false;
}

void UPlayspaceManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceManagerComponent, RootPlayspace);
}
