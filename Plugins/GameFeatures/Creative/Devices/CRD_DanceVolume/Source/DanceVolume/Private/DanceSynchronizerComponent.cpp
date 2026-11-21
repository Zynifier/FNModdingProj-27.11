// Copyright Epic Games, Inc. All Rights Reserved.

#include "DanceSynchronizerComponent.h"
#include "Net/UnrealNetwork.h"

float UDanceSynchronizerComponent::CalculateDanceMontagePlayRate(const float CurrentTempo, const UAnimMontage* Montage, const FDanceBeatInfo& DanceBeatInfo)
{
	return float();
}

AFortPlayerPawn* UDanceSynchronizerComponent::GetOwnerFortPlayerPawn()
{
	return nullptr;
}

USkeletalMeshComponent* UDanceSynchronizerComponent::GetOwnerSkeletalMeshComponent()
{
	return nullptr;
}

bool UDanceSynchronizerComponent::IsTempoSyncEnabled()
{
	return false;
}

void UDanceSynchronizerComponent::OnRep_SyncMode()
{
}

void UDanceSynchronizerComponent::SetBeatSyncMode(EDanceBeatSyncMode NewMode)
{
}

void UDanceSynchronizerComponent::SetDanceBeatInfo(const FDanceBeatInfo& NewDanceBeatInfo)
{
}

void UDanceSynchronizerComponent::SetTempo(float NewTempo)
{
}

void UDanceSynchronizerComponent::StopOwnerEmoteAudio()
{
}

void UDanceSynchronizerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UDanceSynchronizerComponent, BeatInfo);
	DOREPLIFETIME(UDanceSynchronizerComponent, SyncMode);
	DOREPLIFETIME(UDanceSynchronizerComponent, Tempo);
}
