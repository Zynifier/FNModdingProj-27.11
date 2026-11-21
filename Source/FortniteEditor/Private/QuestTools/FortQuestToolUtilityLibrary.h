// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/TopLevelAssetPath.h"
#include "ChallengeBundles/FortChallengeBundleItemDefinition.h"
#include "Quests/FortMcpQuestObjectiveInfo.h"
#include "Quests/FortQuestIndicatorData.h"
#include "Quests/FortQuestItemDefinitionTypes.h"
#include "Quests/FortQuestObjectiveStatTable.h"
#include "FortQuestToolUtilityLibrary.generated.h"

class UDataTable;
class UFortChallengeBundleItemDefinition;
class UFortItemDefinition;
class UFortQuestItemDefinition;
enum class EFortGameplayTagContainerUpdateType : uint8;

UENUM()
enum class EFortGameplayTagContainerUpdateType : uint8
{
	/** Replace all tags with tags from new container */
	Set = 0,
	/** Append any tags from the new container */
	Append = 1,
	/** Remove any matching tags */
	Remove = 2,
};

UCLASS()
class UFortQuestToolUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool AddEmptyObjectiveWithGeneratedBackendName(UFortQuestItemDefinition* Quest, int32& OutNewObjectiveIndex, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static void AddMapForQuestTagToLocation(const FName& InMapName, const FTopLevelAssetPath& RelativeTagToLocationDataTablePath);

	UFUNCTION(BlueprintCallable)
	static bool AddQuestEntryToBundle(UFortChallengeBundleItemDefinition* BundleDef, const FFortChallengeBundleQuestEntry& QuestEntry);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static bool AddQuestItemObjectiveFilter(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const FInstancedStruct ObjectiveFilter, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static void AddQuestMarkerLocationDataRow(UDataTable* DataTable, const FName& RowName, const FFortQuestTagToLocationDataRow& NewRowStruct);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static void AddTagForQuestMapMarkerCollection(const FGameplayTag& InTagToAdd, const FName& InMapName);

	UFUNCTION(BlueprintCallable)
	static void AdvancedCopyPackagesToTargetPath(const TArray<FName>& PackageNamesToCopy, const FString& TargetPath);

	UFUNCTION(BlueprintCallable)
	static bool ClearBundleQuestEntries(UFortChallengeBundleItemDefinition* BundleDef);

	UFUNCTION(BlueprintCallable)
	static bool ConvertAssetPathToFilePath(const FString& InAssetPath, FString& OutPath, const FString& InExtension = TEXT(""));

	UFUNCTION(BlueprintCallable)
	static bool ConvertFilePathToAssetPath(const FString& InPath, FString& OutPath);

	UFUNCTION(BlueprintCallable)
	static bool CopyFortReleaseVersion(UFortItemDefinition* ItemDefinition, const UFortItemDefinition* ItemDefinitionToCopyFrom);

	UFUNCTION(BlueprintCallable)
	static void CopyQuestObjective(const FFortMcpQuestObjectiveInfo ObjectiveInfo);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static void CopyStringToClipboard(const FString& InString);

	UFUNCTION(BlueprintCallable)
	static bool DuplicateObjective(UFortQuestItemDefinition* Quest, const int32 SourceObjectiveIndex, int32& OutNewObjectiveIndex, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static bool DuplicateQuestItemObjectiveFilter(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 ObjectiveFilterIdx, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable)
	static bool ExportDataTableToCSV(const UDataTable* DataTable, const bool bShowFilePickerDialog, const FString& PathToWriteDataTable);

	UFUNCTION(BlueprintCallable)
	static bool GetAllTagsForQuestMapMarkers(const UFortQuestItemDefinition* InQuest, const int32 ObjectiveIdx, FGameplayTagContainer& OutTags);

	UFUNCTION(BlueprintCallable)
	static bool GetCopiedQuestObjective(FFortMcpQuestObjectiveInfo& ObjectiveInfo);

	UFUNCTION(BlueprintPure, Category="Utilities|Paths", meta=(BlueprintThreadSafe))
	static FString GetGameFeaturesDirAbsolutePath();

	UFUNCTION(BlueprintCallable)
	static bool GetInlineStat(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, FFortQuestObjectiveStat& InlineObjectiveStat);

	UFUNCTION(BlueprintCallable)
	static bool GetInlineStatArray(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, TArray<FFortQuestObjectiveStat>& InlineObjectiveStats);

	UFUNCTION(BlueprintCallable)
	static bool GetInlineStatCondition(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, FString& OutConditionString);

	UFUNCTION(BlueprintCallable)
	static bool GetInlineStatGameplayTagContainerByName(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, const FName TagContainerPropertyName, FGameplayTagContainer& OutTags);

	UFUNCTION(BlueprintCallable)
	static bool GetObjectiveDisplayInfo(const UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, FFortMcpQuestObjectiveDisplayInfo& OutObjectiveDisplayInfo);

	UFUNCTION(BlueprintCallable)
	static bool GetQuestGameplayTagContainerByName(const UFortQuestItemDefinition* Quest, const FName TagContainerPropertyName, FGameplayTagContainer& OutTags);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static void GetQuestMapMarkerMapNames(TArray<FName>& OutMapNames);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static bool GetQuestObjectiveTagForQuestProp(const FFortMcpQuestObjectiveInfo& Objective, FGameplayTagContainer& OutContainerTag);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static void GetTagToQuestMapMarkerTagNames(TArray<FName>& OutTagNames);

	UFUNCTION(BlueprintCallable)
	static bool InsertQuestEntryToBundle(UFortChallengeBundleItemDefinition* BundleDef, const FFortChallengeBundleQuestEntry& QuestEntry, const int32 InsertIndex);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static bool IsTagValidToUseAsQuestMarker(const FGameplayTag& TagToCheck);

	UFUNCTION(BlueprintCallable)
	static bool RemoveObjectiveFromQuest(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable, Category="Quest Tool")
	static bool RemoveQuestItemObjectiveFilter(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 ObjectiveFilterIdx, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable)
	static bool ReplaceEditorOnlyItemDefinitionInQuestHiddenRewards(UFortQuestItemDefinition* Quest, const int32 RewardIndex, const TSoftObjectPtr<UFortItemDefinition>& NewEditorOnlyItemDefinition);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetRewardItemInQuestHiddenRewards"))
	static bool ReplaceTemplateIdInQuestHiddenRewards(UFortQuestItemDefinition* Quest, const int32 Index, const FName& NewTemplateId);

	UFUNCTION(BlueprintCallable)
	static void ResetCopiedQuestObjective();

	UFUNCTION(BlueprintCallable)
	static bool SetFortReleaseVersionBySeason(UFortItemDefinition* ItemDefinition, const int32 SeasonNum);

	UFUNCTION(BlueprintCallable)
	static bool SetInlineStatArray(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const TArray<FFortQuestObjectiveStat>& NewInlineObjectiveStats, const bool bCreateTransaction = true);

	UFUNCTION(BlueprintCallable)
	static bool SetInlineStatCondition(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, const FString& NewConditionString, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable)
	static bool SetInlineStatGameplayTagContainerByName(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 InlineStatIdx, const FName TagContainerPropertyName, const FGameplayTagContainer NewTags, const EFortGameplayTagContainerUpdateType UpdateType, const bool bCreateTransaction = true);

	UFUNCTION(BlueprintCallable)
	static bool SetObjectiveBackendName(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const FName NewBackendName, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable)
	static bool SetObjectiveCount(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const int32 NewCount, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable)
	static bool SetObjectiveDisplayInfo(UFortQuestItemDefinition* Quest, const int32 ObjectiveIdx, const FFortMcpQuestObjectiveDisplayInfo& NewObjectiveDisplayInfo, const bool bCreateTransaction);

	UFUNCTION(BlueprintCallable)
	static bool SetQuestGameplayTagContainerByName(UFortQuestItemDefinition* Quest, const FGameplayTagContainer NewTags, const FName TagContainerPropertyName, const EFortGameplayTagContainerUpdateType UpdateType, const bool bCreateTransaction = true);

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="PackagesToSkip"))
	static void StartValidateCheckedOutContent(const TArray<FAssetData>& PackagesToSkip);

	UFUNCTION(BlueprintCallable)
	static bool TestInlineStatCondition(const FString& Condition);

};

