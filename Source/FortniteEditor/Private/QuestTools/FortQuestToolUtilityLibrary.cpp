// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestTools/FortQuestToolUtilityLibrary.h"

bool UFortQuestToolUtilityLibrary::AddEmptyObjectiveWithGeneratedBackendName(UFortQuestItemDefinition* Quest, int32& OutNewObjectiveIndex, const bool bCreateTransaction)
{
	return false;
}

void UFortQuestToolUtilityLibrary::AddMapForQuestTagToLocation(const FName& InMapName, const FTopLevelAssetPath& RelativeTagToLocationDataTablePath)
{
}

bool UFortQuestToolUtilityLibrary::AddQuestEntryToBundle(UFortChallengeBundleItemDefinition* BundleDef, const FFortChallengeBundleQuestEntry& QuestEntry)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::AddQuestItemObjectiveFilter(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const FInstancedStruct ObjectiveFilter, const bool bCreateTransaction)
{
	return false;
}

void UFortQuestToolUtilityLibrary::AddQuestMarkerLocationDataRow(UDataTable* DataTable, const FName& RowName, const FFortQuestTagToLocationDataRow& NewRowStruct)
{
}

void UFortQuestToolUtilityLibrary::AddTagForQuestMapMarkerCollection(const FGameplayTag& InTagToAdd, const FName& InMapName)
{
}

void UFortQuestToolUtilityLibrary::AdvancedCopyPackagesToTargetPath(const TArray<FName>& PackageNamesToCopy, const FString& TargetPath)
{
}

bool UFortQuestToolUtilityLibrary::ClearBundleQuestEntries(UFortChallengeBundleItemDefinition* BundleDef)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::ConvertAssetPathToFilePath(const FString& InAssetPath, FString& OutPath, const FString& InExtension)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::ConvertFilePathToAssetPath(const FString& InPath, FString& OutPath)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::CopyFortReleaseVersion(UFortItemDefinition* ItemDefinition, const UFortItemDefinition* ItemDefinitionToCopyFrom)
{
	return false;
}

void UFortQuestToolUtilityLibrary::CopyQuestObjective(const FFortMcpQuestObjectiveInfo ObjectiveInfo)
{
}

void UFortQuestToolUtilityLibrary::CopyStringToClipboard(const FString& InString)
{
}

bool UFortQuestToolUtilityLibrary::DuplicateObjective(UFortQuestItemDefinition* Quest, const int32 SourceObjectiveIndex, int32& OutNewObjectiveIndex, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::DuplicateQuestItemObjectiveFilter(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 ObjectiveFilterIdx, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::ExportDataTableToCSV(const UDataTable* DataTable, const bool bShowFilePickerDialog, const FString& PathToWriteDataTable)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::GetAllTagsForQuestMapMarkers(const UFortQuestItemDefinition* InQuest, const int32 ObjectiveIdx, FGameplayTagContainer& OutTags)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::GetCopiedQuestObjective(FFortMcpQuestObjectiveInfo& ObjectiveInfo)
{
	return false;
}

FString UFortQuestToolUtilityLibrary::GetGameFeaturesDirAbsolutePath()
{
	return FString();
}

bool UFortQuestToolUtilityLibrary::GetInlineStat(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, FFortQuestObjectiveStat& InlineObjectiveStat)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::GetInlineStatArray(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, TArray<FFortQuestObjectiveStat>& InlineObjectiveStats)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::GetInlineStatCondition(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, FString& OutConditionString)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::GetInlineStatGameplayTagContainerByName(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, const FName TagContainerPropertyName, FGameplayTagContainer& OutTags)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::GetObjectiveDisplayInfo(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, FFortMcpQuestObjectiveDisplayInfo& OutObjectiveDisplayInfo)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::GetQuestGameplayTagContainerByName(const UFortQuestItemDefinition* Quest, const FName TagContainerPropertyName, FGameplayTagContainer& OutTags)
{
	return false;
}

void UFortQuestToolUtilityLibrary::GetQuestMapMarkerMapNames(TArray<FName>& OutMapNames)
{
}

bool UFortQuestToolUtilityLibrary::GetQuestObjectiveTagForQuestProp(const FFortMcpQuestObjectiveInfo& Objective, FGameplayTagContainer& OutContainerTag)
{
	return false;
}

void UFortQuestToolUtilityLibrary::GetTagToQuestMapMarkerTagNames(TArray<FName>& OutTagNames)
{
}

bool UFortQuestToolUtilityLibrary::InsertQuestEntryToBundle(UFortChallengeBundleItemDefinition* BundleDef, const FFortChallengeBundleQuestEntry& QuestEntry, const int32 InsertIndex)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::IsTagValidToUseAsQuestMarker(const FGameplayTag& TagToCheck)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::RemoveObjectiveFromQuest(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::RemoveQuestItemObjectiveFilter(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 ObjectiveFilterIdx, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::ReplaceEditorOnlyItemDefinitionInQuestHiddenRewards(UFortQuestItemDefinition* Quest, const int32 RewardIndex, const TSoftObjectPtr<UFortItemDefinition>& NewEditorOnlyItemDefinition)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::ReplaceTemplateIdInQuestHiddenRewards(UFortQuestItemDefinition* Quest, const int32 Index, const FName& NewTemplateId)
{
	return false;
}

void UFortQuestToolUtilityLibrary::ResetCopiedQuestObjective()
{
}

bool UFortQuestToolUtilityLibrary::SetFortReleaseVersionBySeason(UFortItemDefinition* ItemDefinition, const int32 SeasonNum)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::SetInlineStatArray(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const TArray<FFortQuestObjectiveStat>& NewInlineObjectiveStats, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::SetInlineStatCondition(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, const FString& NewConditionString, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::SetInlineStatGameplayTagContainerByName(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, const FName TagContainerPropertyName, const FGameplayTagContainer NewTags, const EFortGameplayTagContainerUpdateType UpdateType, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::SetObjectiveBackendName(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const FName NewBackendName, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::SetObjectiveCount(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 NewCount, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::SetObjectiveDisplayInfo(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const FFortMcpQuestObjectiveDisplayInfo& NewObjectiveDisplayInfo, const bool bCreateTransaction)
{
	return false;
}

bool UFortQuestToolUtilityLibrary::SetQuestGameplayTagContainerByName(UFortQuestItemDefinition* Quest, const FGameplayTagContainer NewTags, const FName TagContainerPropertyName, const EFortGameplayTagContainerUpdateType UpdateType, const bool bCreateTransaction)
{
	return false;
}

void UFortQuestToolUtilityLibrary::StartValidateCheckedOutContent(const TArray<FAssetData>& PackagesToSkip)
{
}

bool UFortQuestToolUtilityLibrary::TestInlineStatCondition(const FString& Condition)
{
	return false;
}
