// Copyright Epic Games, Inc. All Rights Reserved.

#include "CreativeQuestComponent.h"
#include "Net/UnrealNetwork.h"

TArray<AController*> UCreativeQuestComponent::GetActiveSharedControllers(AController* Instigator) const
{
	return TArray<AController*>();
}

int32 UCreativeQuestComponent::GetCurrentAmount(const AController* ForPlayer) const
{
	return int32();
}

void UCreativeQuestComponent::HandlePlayerStatChanged(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, AFortPlayerController* PlayerController, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32 Count)
{
}

bool UCreativeQuestComponent::IsActiveFor(const AController* Player) const
{
	return false;
}

void UCreativeQuestComponent::OnMinigameEnded()
{
}

void UCreativeQuestComponent::OnMinigameStarted()
{
}

void UCreativeQuestComponent::OnMissionManagerCreated()
{
}

void UCreativeQuestComponent::OnRep_QuestActive()
{
}

void UCreativeQuestComponent::OnRep_QuestUpdate()
{
}

void UCreativeQuestComponent::RegisterQuest(AFortMinigame* Minigame)
{
}

void UCreativeQuestComponent::ResetQuestProgress(int32 InitialAmount)
{
}

void UCreativeQuestComponent::SetActiveFor(AController* Player, bool bNewActive)
{
}

void UCreativeQuestComponent::SetCurrentAmount(const AController* ForPlayer, int32 NewAmount)
{
}

void UCreativeQuestComponent::TriggerHUDUpdate(const bool bForceUpdate)
{
}

void UCreativeQuestComponent::UnregisterQuest()
{
}

void UCreativeQuestComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCreativeQuestComponent, StatToTrack);
	DOREPLIFETIME(UCreativeQuestComponent, SharingMode);
	DOREPLIFETIME(UCreativeQuestComponent, TargetTeam);
	DOREPLIFETIME(UCreativeQuestComponent, TargetClass);
	DOREPLIFETIME(UCreativeQuestComponent, AssignedToTeam);
	DOREPLIFETIME(UCreativeQuestComponent, TargetDeathCause);
	DOREPLIFETIME(UCreativeQuestComponent, bSelfEliminationsCount);
	DOREPLIFETIME(UCreativeQuestComponent, bHeadshotsOnly);
	DOREPLIFETIME(UCreativeQuestComponent, bPlayerEliminationsCount);
	DOREPLIFETIME(UCreativeQuestComponent, bNonPlayerEliminationsCount);
	DOREPLIFETIME(UCreativeQuestComponent, MinigameTargetAmount);
	DOREPLIFETIME(UCreativeQuestComponent, ShowQuestOnHUD);
	DOREPLIFETIME(UCreativeQuestComponent, ShowProgressMode);
	DOREPLIFETIME(UCreativeQuestComponent, bShowCompleteEffects);
	DOREPLIFETIME(UCreativeQuestComponent, QuestIconImage);
	DOREPLIFETIME(UCreativeQuestComponent, QuestColor);
	DOREPLIFETIME(UCreativeQuestComponent, QuestIndividualData);
	DOREPLIFETIME(UCreativeQuestComponent, QuestTeamProgress);
	DOREPLIFETIME(UCreativeQuestComponent, QuestAllProgress);
	DOREPLIFETIME(UCreativeQuestComponent, QuestInitialProgress);
}
