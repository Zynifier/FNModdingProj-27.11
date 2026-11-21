// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortQuestItemDefinition.h"

bool UFortQuestItemDefinition::AllowsPlayNowNavigation() const
{
	return false;
}

bool UFortQuestItemDefinition::AllowsTileMatching() const
{
	return false;
}

bool UFortQuestItemDefinition::CanPartyAssist() const
{
	return false;
}

bool UFortQuestItemDefinition::CanProgressInBRWarmup() const
{
	return false;
}

bool UFortQuestItemDefinition::CanShowTimer() const
{
	return false;
}

#if WITH_EDITOR
void UFortQuestItemDefinition::CopyQuestNameToClipboard()
{
}
#endif

#if WITH_EDITOR
void UFortQuestItemDefinition::CopyQuestTemplateIdToClipboard()
{
}
#endif

#if WITH_EDITOR
void UFortQuestItemDefinition::DebugGrantQuest() const
{
}
#endif

#if WITH_EDITOR
TArray<FName> UFortQuestItemDefinition::Editor_GetValidObjectives() const
{
	return TArray<FName>();
}
#endif

bool UFortQuestItemDefinition::ExpandsStormShield() const
{
	return false;
}

#if WITH_EDITOR
bool UFortQuestItemDefinition::GenerateUniqueBackendNameForAllEmptyObjectives()
{
	return false;
}
#endif

#if WITH_EDITOR
bool UFortQuestItemDefinition::GenerateUniqueBackendNameForObjective(const int32 ObjectiveIndex, const EQuestEditorGenerateBackendNameReason Reason)
{
	return false;
}
#endif

bool UFortQuestItemDefinition::GetAthenaObjectiveMustBeCompletedInASingleMatch() const
{
	return false;
}

bool UFortQuestItemDefinition::GetAthenaUpdateObjectiveOncePerMatch() const
{
	return false;
}

FDataTableRowHandle UFortQuestItemDefinition::GetCategory() const
{
	return FDataTableRowHandle();
}

FFortRewardInfo UFortQuestItemDefinition::GetChallengeChainRewardInfo(bool bGetAllQuestRewards) const
{
	return FFortRewardInfo();
}

const TSoftObjectPtr<USoundBase>& UFortQuestItemDefinition::GetCharacterCompletionAudio() const
{
	static TSoftObjectPtr<USoundBase> Dummy;
	return Dummy;
}

float UFortQuestItemDefinition::GetCharacterCompletionAudioDelay() const
{
	return float();
}

UFortConversation* UFortQuestItemDefinition::GetClaimConversation() const
{
	return nullptr;
}

FText UFortQuestItemDefinition::GetCompletionText() const
{
	return FText();
}

FString UFortQuestItemDefinition::GetCompletionVideoUID() const
{
	return FString();
}

TArray<FFortHiddenRewardQuantityPair> UFortQuestItemDefinition::GetHiddenRewards_BP() const
{
	return TArray<FFortHiddenRewardQuantityPair>();
}

UFortConversation* UFortQuestItemDefinition::GetIntroConversation() const
{
	return nullptr;
}

int32 UFortQuestItemDefinition::GetObjectiveNeededToComplete() const
{
	return int32();
}

TArray<FFortMcpQuestObjectiveInfo> UFortQuestItemDefinition::GetObjectives_BP() const
{
	return TArray<FFortMcpQuestObjectiveInfo>();
}

int32 UFortQuestItemDefinition::GetPartialObjectiveCompletionCount() const
{
	return int32();
}

FDataTableRowHandle UFortQuestItemDefinition::GetPrerequisiteObjective() const
{
	return FDataTableRowHandle();
}

FText UFortQuestItemDefinition::GetQuestHeaderToastDisplayText() const
{
	return FText();
}

EFortQuestType UFortQuestItemDefinition::GetQuestType() const
{
	return EFortQuestType();
}

FText UFortQuestItemDefinition::GetRewardDescription() const
{
	return FText();
}

FFortRewardInfo UFortQuestItemDefinition::GetRewardInfo_BP() const
{
	return FFortRewardInfo();
}

TArray<FFortItemQuantityPair> UFortQuestItemDefinition::GetRewards_BP() const
{
	return TArray<FFortItemQuantityPair>();
}

EFortQuestRewardType UFortQuestItemDefinition::GetRewardType() const
{
	return EFortQuestRewardType();
}

TArray<FFortMcpQuestRewardInfo> UFortQuestItemDefinition::GetSelectableRewards_BP() const
{
	return TArray<FFortMcpQuestRewardInfo>();
}

UFortConversation* UFortQuestItemDefinition::GetSelectRewardsConversation() const
{
	return nullptr;
}

bool UFortQuestItemDefinition::GetUpdateObjectiveOncePerMatch() const
{
	return false;
}

float UFortQuestItemDefinition::GetWeight() const
{
	return float();
}

bool UFortQuestItemDefinition::HasComponentForWorldProcessingUpdates() const
{
	return false;
}

bool UFortQuestItemDefinition::IsDeprecated() const
{
	return false;
}

bool UFortQuestItemDefinition::IsFeatQuest() const
{
	return false;
}

bool UFortQuestItemDefinition::IsGlyphQuest() const
{
	return false;
}

bool UFortQuestItemDefinition::IsGroupChallenge() const
{
	return false;
}

bool UFortQuestItemDefinition::IsHidden() const
{
	return false;
}

bool UFortQuestItemDefinition::IsIncludedInCategories() const
{
	return false;
}

bool UFortQuestItemDefinition::IsPunchCardQuest() const
{
	return false;
}

bool UFortQuestItemDefinition::IsTutorialQuest() const
{
	return false;
}

#if WITH_EDITOR
void UFortQuestItemDefinition::RegenerateCompletionPathsData()
{
}
#endif

bool UFortQuestItemDefinition::ShouldAutoLaunch() const
{
	return false;
}

bool UFortQuestItemDefinition::ShouldDisplayOverallQuestInformation() const
{
	return false;
}

bool UFortQuestItemDefinition::ShouldDisplayStartingToast() const
{
	return false;
}
