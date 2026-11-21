// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPlayerControllerAthenaXPComponent.h"
#include "Net/UnrealNetwork.h"

void UFortPlayerControllerAthenaXPComponent::ClientInitForUEFN_Implementation(const FString& SeasonTemplate, const int32 PlayerCurrentLevel, const int32 PlayerCurrentXp)
{
}
bool UFortPlayerControllerAthenaXPComponent::ClientInitForUEFN_Validate(const FString& SeasonTemplate, const int32 PlayerCurrentLevel, const int32 PlayerCurrentXp)
{
	return true;
}

void UFortPlayerControllerAthenaXPComponent::ClientMedalsRecived_Implementation(const TArray<FAthenaAccolades>& Medals)
{
}
bool UFortPlayerControllerAthenaXPComponent::ClientMedalsRecived_Validate(const TArray<FAthenaAccolades>& Medals)
{
	return true;
}

void UFortPlayerControllerAthenaXPComponent::ClientQuestsUpdated_Implementation(const TArray<FFortQuestObjectiveCompletion>& PendingQuestChanges)
{
}
bool UFortPlayerControllerAthenaXPComponent::ClientQuestsUpdated_Validate(const TArray<FFortQuestObjectiveCompletion>& PendingQuestChanges)
{
	return true;
}

void UFortPlayerControllerAthenaXPComponent::HandleLateQuestUpdated(const TScriptInterface<IQuestInstanceInterface>& QuestInstance)
{
}

void UFortPlayerControllerAthenaXPComponent::InitRestedXp()
{
}

void UFortPlayerControllerAthenaXPComponent::OnInMatchProfileUpdate(int64 ProfileRevision)
{
}

void UFortPlayerControllerAthenaXPComponent::OnProfileUpdated()
{
}

void UFortPlayerControllerAthenaXPComponent::OnRep_bRegisteredWithQuestManager()
{
}

void UFortPlayerControllerAthenaXPComponent::OnRep_HasBRMatchReportCompletedProfileVer()
{
}

void UFortPlayerControllerAthenaXPComponent::OnRep_InMatchProfileVer()
{
}

void UFortPlayerControllerAthenaXPComponent::OnXPEvent(const FXPEventInfo& XPEvent)
{
}

void UFortPlayerControllerAthenaXPComponent::OnXpUpdated(int32 InCombatXp, int32 InSurvivalXp, int32 InBonusMedalXp, int32 InChallengeXp, int32 InMatchXp, int32 InTotalXp)
{
}

void UFortPlayerControllerAthenaXPComponent::ServerUpdateCurrentLevel_Implementation(int32 NewCurrentLevel)
{
}

void UFortPlayerControllerAthenaXPComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, EventArray);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, RestXp);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, bRegisteredWithQuestManager);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, TotalXpEarned);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, MedalBonusXp);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, SurvivalXp);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, CombatXp);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, MatchXp);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, ChallengeXp);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, HasBRMatchReportCompletedProfileVer);
	DOREPLIFETIME(UFortPlayerControllerAthenaXPComponent, InMatchProfileVer);
}
