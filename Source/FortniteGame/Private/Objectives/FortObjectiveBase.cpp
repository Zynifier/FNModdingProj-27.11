// Copyright Epic Games, Inc. All Rights Reserved.

#include "Objectives/FortObjectiveBase.h"
#include "Net/UnrealNetwork.h"

void AFortObjectiveBase::AttemptMissionSave(const FString& OptionalSaveName)
{
}

void AFortObjectiveBase::ClearObjectiveTimer()
{
}

void AFortObjectiveBase::EnableTick(bool bEnabled)
{
}

AFortMission* AFortObjectiveBase::GetMission() const
{
	return nullptr;
}

FGuid AFortObjectiveBase::GetMissionGuid() const
{
	return FGuid();
}

FText AFortObjectiveBase::GetObjectiveDisplayString() const
{
	return FText();
}

float AFortObjectiveBase::GetObjectiveTimerTimeRemaining() const
{
	return float();
}

void AFortObjectiveBase::GetRewardItemsByTag(const FGameplayTag RewardTag, TArray<UFortWorldItemDefinition*>& OutRewardItems)
{
}

UFortMissionTimerComponent* AFortObjectiveBase::GetTimerComponent() const
{
	return nullptr;
}

void AFortObjectiveBase::GrantRewardsByTag(const FGameplayTag RewardTag, EFortRewardType::Type RewardType)
{
}

bool AFortObjectiveBase::IsObjectiveTimerPaused() const
{
	return false;
}

bool AFortObjectiveBase::IsRelevantToASpecificTeam() const
{
	return false;
}

bool AFortObjectiveBase::IsRelevantToTeam(uint8 Team) const
{
	return false;
}

void AFortObjectiveBase::OnRep_bIsObjectiveVisible()
{
}

void AFortObjectiveBase::OnRep_ObjectiveStatus()
{
}

void AFortObjectiveBase::OnRep_ObjectiveVisibilityOverride()
{
}

void AFortObjectiveBase::PauseObjectiveTimer()
{
}

void AFortObjectiveBase::SetObjectiveTimer(const FString& FunctionName, float TimerLength, bool bStartPaused)
{
}

void AFortObjectiveBase::SetUiVisibility(bool bInIsObjectiveVisible)
{
}

void AFortObjectiveBase::SetUIVisibilityOverride(EFortMissionVisibilityOverride InVisibilityOverride)
{
}

bool AFortObjectiveBase::StartPlayingObjective()
{
	return false;
}

void AFortObjectiveBase::StopObjective(EFortObjectiveStatus Status, const FString& Description, UFortBadgeItemDefinition* ExtraBadgeToGrant)
{
}

void AFortObjectiveBase::UnpauseObjectiveTimer()
{
}

void AFortObjectiveBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortObjectiveBase, ObjectiveHandle);
	DOREPLIFETIME(AFortObjectiveBase, bIsObjectiveVisible);
	DOREPLIFETIME(AFortObjectiveBase, VisibilityOverride);
	DOREPLIFETIME(AFortObjectiveBase, bIsProgressBarHidden);
	DOREPLIFETIME(AFortObjectiveBase, ObjectiveAudiblity);
	DOREPLIFETIME(AFortObjectiveBase, ObjectiveStatus);
}
