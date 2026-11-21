// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMissionTimerComponent.h"
#include "Net/UnrealNetwork.h"

void UFortMissionTimerComponent::AddOrRemoveTime(float TimeToAdd)
{
}

void UFortMissionTimerComponent::ClearMissionTimer()
{
}

void UFortMissionTimerComponent::DummyTimer()
{
}

FMissionTimeDisplayData UFortMissionTimerComponent::GetCorrectTimeDisplayData() const
{
	return FMissionTimeDisplayData();
}

float UFortMissionTimerComponent::GetMissionTimerTimeElapsed() const
{
	return float();
}

float UFortMissionTimerComponent::GetMissionTimerTimeRemaining() const
{
	return float();
}

float UFortMissionTimerComponent::GetNormalizedTime() const
{
	return float();
}

FText UFortMissionTimerComponent::GetTimerLabelText() const
{
	return FText();
}

FText UFortMissionTimerComponent::GetTimeText() const
{
	return FText();
}

bool UFortMissionTimerComponent::IsMissionTimerPaused() const
{
	return false;
}

bool UFortMissionTimerComponent::IsMissionTimerSet() const
{
	return false;
}

bool UFortMissionTimerComponent::IsTimerVisible() const
{
	return false;
}

void UFortMissionTimerComponent::OnRep_TimerData()
{
}

void UFortMissionTimerComponent::OnRep_TimerVisibilityOverride()
{
}

void UFortMissionTimerComponent::PauseMissionTimer()
{
}

void UFortMissionTimerComponent::ResetMissionTimer()
{
}

void UFortMissionTimerComponent::SetMissionTimeElapsedTimer()
{
}

void UFortMissionTimerComponent::SetMissionTimer(const FString& FunctionName, float TimerLength, AActor* CallbackActor)
{
}

void UFortMissionTimerComponent::SetTimerDisplayFormat(bool bNewDisplayInTimeFormat)
{
}

void UFortMissionTimerComponent::SetTimerLabelText(FText NewLabelText)
{
}

void UFortMissionTimerComponent::SetTimerVisibilityOverrideSetting(ETimerOverrideSetting::Type NewVisibilitySetting)
{
}

void UFortMissionTimerComponent::SetTimerVisibilityOverrideToShowAtEnd(float ShowTime)
{
}

void UFortMissionTimerComponent::UnpauseMissionTimer()
{
}

void UFortMissionTimerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMissionTimerComponent, TimerData);
	DOREPLIFETIME(UFortMissionTimerComponent, TimerLabelText);
	DOREPLIFETIME(UFortMissionTimerComponent, bDisplayInTimeFormat);
	DOREPLIFETIME(UFortMissionTimerComponent, TimerVisibilityOverrideSetting);
	DOREPLIFETIME(UFortMissionTimerComponent, TimerVisibilityShowAtEndTime);
}
