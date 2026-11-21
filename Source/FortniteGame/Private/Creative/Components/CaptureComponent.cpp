// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/CaptureComponent.h"
#include "Net/UnrealNetwork.h"

void UCaptureComponent::ForceCaptureProgress(float NewCaptureProgress)
{
}

ECaptureState UCaptureComponent::GetCaptureState() const
{
	return ECaptureState();
}

uint8 UCaptureComponent::GetCaptureStateOwner() const
{
	return uint8();
}

void UCaptureComponent::OnRep_CaptureProgress()
{
}

void UCaptureComponent::OnRep_CaptureState(ECaptureState OldCaptureState)
{
}

void UCaptureComponent::OnRep_OwningTeam(const uint8 PreviousOwningTeam)
{
}

void UCaptureComponent::OnRep_SmoothProgressState()
{
}

void UCaptureComponent::SetCaptureSpeedBoost(float NewCaptureSpeedBoost)
{
}

void UCaptureComponent::SetCaptureSpeedBoostEmoting(float NewCaptureSpeedBoostEmoting)
{
}

void UCaptureComponent::SetCaptureState(ECaptureState NewCaptureState, uint8 TriggerTeamIndex)
{
}

void UCaptureComponent::SetCaptureTime(float NewCaptureTime)
{
}

void UCaptureComponent::SetNeutralizingTime(int32 NewNeutralizingSpeed)
{
}

void UCaptureComponent::SetProgressDecaySpeed(float NewProgressDecaySpeed)
{
}

void UCaptureComponent::UpdateCaptureSpeed(int32 NumOfPlayers, int32 NumOfEmotingPlayers)
{
}

void UCaptureComponent::UpdateProgressReverseSpeed(int32 NumOfPlayers, int32 NumOfEmotingPlayers)
{
}

void UCaptureComponent::UpdateSmoothProgressStateByCaptureState()
{
}

void UCaptureComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCaptureComponent, StateOwner);
	DOREPLIFETIME(UCaptureComponent, OwningTeam);
	DOREPLIFETIME(UCaptureComponent, CaptureState);
	DOREPLIFETIME(UCaptureComponent, CaptureProgress);
	DOREPLIFETIME(UCaptureComponent, SmoothProgressState);
}
