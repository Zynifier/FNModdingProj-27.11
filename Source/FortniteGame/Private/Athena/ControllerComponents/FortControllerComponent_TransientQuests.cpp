// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ControllerComponents/FortControllerComponent_TransientQuests.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_TransientQuests::AuthorityHandleParticipatingQuestAdded(const TScriptInterface<IQuestInstanceInterface>& QuestInstance)
{
}

void UFortControllerComponent_TransientQuests::AuthorityHandleParticipatingQuestRemoved(const TScriptInterface<IQuestInstanceInterface>& QuestInstance)
{
}

bool UFortControllerComponent_TransientQuests::CheckIfQuestIsBounty(const FGameplayTag& UrgentQuestTag) const
{
	return false;
}

void UFortControllerComponent_TransientQuests::CleanupCompletedQuest(const UFortQuestItemDefinition_Athena* CompletedQuestDefAthena)
{
}

void UFortControllerComponent_TransientQuests::ClientBroadcastOnPlayerBountyThreatLevelUpdated_Implementation(EPlayerBountyThreatLevel NewPlayerBountyThreatLevel)
{
}

void UFortControllerComponent_TransientQuests::ClientBroadcastOnUrgentQuestEnded_Implementation(const FGameplayTag& EventTag, const EFortQuestState QuestState)
{
}

void UFortControllerComponent_TransientQuests::ClientBroadcastOnUrgentQuestStarted_Implementation(const FUrgentQuestData& UrgentQuestData, float EventTimeRemaining)
{
}

void UFortControllerComponent_TransientQuests::ClientGrantTransientQuest_Implementation(const UFortQuestItemDefinition_Athena* QuestItemDefAthena, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena)
{
}

void UFortControllerComponent_TransientQuests::ClientHandleSharedQuestAutoCompleted_Implementation(const UFortQuestItemDefinition_Athena* QuestDefAthena)
{
}

void UFortControllerComponent_TransientQuests::ClientHandleSharedQuestGranted_Implementation(const FUniqueNetIdRepl PlayerId, const UFortQuestItemDefinition_Athena* QuestDefAthena, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena, const FString& Bucket, const TArray<FString>& Playlists, const FDateTime& Expiration, const TArray<int32>& AchievedCounts)
{
}

void UFortControllerComponent_TransientQuests::ClientHandleSharedQuestPinned_Implementation(const FUniqueNetIdRepl PlayerId, const UFortQuestItemDefinition_Athena* QuestDefAthena)
{
}

void UFortControllerComponent_TransientQuests::ClientHandleSharedQuestRemoved_Implementation(const FUniqueNetIdRepl PlayerId, const UFortQuestItemDefinition_Athena* QuestDefAthena)
{
}

void UFortControllerComponent_TransientQuests::ClientHandleSharedQuestsForLeavingPlayer_Implementation(const FUniqueNetIdRepl& LeavingPlayerId)
{
}

void UFortControllerComponent_TransientQuests::ClientHandleSharedQuestUpdated_Implementation(const FUniqueNetIdRepl PlayerId, const UFortQuestItemDefinition_Athena* QuestDefAthena, const FName& BackendName, int32 StatValue, int32 Delta)
{
}

void UFortControllerComponent_TransientQuests::ClientRemoveThreatLevelBind_Implementation()
{
}

void UFortControllerComponent_TransientQuests::ClientRemoveTransientQuest_Implementation(const UFortQuestItemDefinition_Athena* QuestItemDefAthena) const
{
}

void UFortControllerComponent_TransientQuests::ClientRemoveUrgentQuestInstanceFromOwningManager_Implementation(const FString& QuestID)
{
}

void UFortControllerComponent_TransientQuests::ClientSetBountyHunterNPCIcon_Implementation(const TSoftObjectPtr<UTexture2D>& NPCIcon)
{
}

void UFortControllerComponent_TransientQuests::ClientSetBountyTargetNPCIcon_Implementation(const TSoftObjectPtr<UTexture2D>& NPCIcon)
{
}

void UFortControllerComponent_TransientQuests::EndQueueForPlayerDuelEvent(const FGameplayTag EventTag)
{
}

int32 UFortControllerComponent_TransientQuests::GetTrackedHunterBountyTargetDistance() const
{
	return int32();
}

int32 UFortControllerComponent_TransientQuests::GetTrackedHunterBountyTargetPrice() const
{
	return int32();
}

void UFortControllerComponent_TransientQuests::GrantTransientQuest(const UFortQuestItemDefinition_Athena* QuestDefAthenaToGrant, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena)
{
}

void UFortControllerComponent_TransientQuests::OnPlayerProfileInitialized()
{
}

void UFortControllerComponent_TransientQuests::OnRep_TrackedHunterBountyTargetDistance()
{
}

void UFortControllerComponent_TransientQuests::OnUrgentTransientQuestCompleted(const UFortQuestItem* TransientQuestItem)
{
}

void UFortControllerComponent_TransientQuests::SetUrgentQuestDescriptionOverride(FGameplayTag UrgentQuestTag, FGameplayTag OverrideTag)
{
}

void UFortControllerComponent_TransientQuests::StartQueueForPlayerDuelEvent(const FUrgentQuestData UrgentQuestData)
{
}

void UFortControllerComponent_TransientQuests::StopPlayerBountyThreatLevelUpdates()
{
}

void UFortControllerComponent_TransientQuests::UrgentQuestItemComponentTimerExpired(const UFortQuestItemComponent_UrgentQuest* UrgentQuestItemComponent)
{
}

void UFortControllerComponent_TransientQuests::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_TransientQuests, TrackedHunterBountyTargetDistance);
}
