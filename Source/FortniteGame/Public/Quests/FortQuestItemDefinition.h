// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Athena/ChallengeGiftBoxData.h"
#include "FortItemQuantityPair.h"
#include "FortTypes.h"
#include "Items/FortAccountItemDefinition.h"
#include "Missions/FortMissionConfigDataParams.h"
#include "Quests/FortMcpQuestObjectiveInfo.h"
#include "Quests/FortQuestItemDefinitionEnums.h"
#include "Quests/FortQuestItemDefinitionTypes.h"
#include "Quests/FortQuestTypes.h"
#include "Quests/IQuestDefinitionInterface.h"
#include "Quests/QuestTypes.h"
#include "FortQuestItemDefinition.generated.h"

class UDataTable;
class UFortAbilitySet;
class UFortConversation;
class UFortItemDefinition;
class UFortPlaylist;
class UFortQuestDefinitionComponent;
class UFortQuestItemDefinition;
class USoundBase;
enum class EFortQuestRewardType : uint8;
enum class EFortQuestType : uint8;
enum class EQuestEditorGenerateBackendNameReason : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortQuestItemDefinition : public UFortAccountItemDefinition, public IQuestDefinitionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool AllowsPlayNowNavigation() const;

	UFUNCTION(BlueprintPure)
	bool AllowsTileMatching() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool CanPartyAssist() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool CanProgressInBRWarmup() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool CanShowTimer() const;

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, meta=(CallInEditor="true"))
	void CopyQuestNameToClipboard();
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, meta=(CallInEditor="true"))
	void CopyQuestTemplateIdToClipboard();
#endif

#if WITH_EDITOR
	UFUNCTION()
	TArray<FName> Editor_GetValidObjectives() const;
#endif

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool ExpandsStormShield() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool GetAthenaObjectiveMustBeCompletedInASingleMatch() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool GetAthenaUpdateObjectiveOncePerMatch() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	FDataTableRowHandle GetCategory() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	FFortRewardInfo GetChallengeChainRewardInfo(bool bGetAllQuestRewards) const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	const TSoftObjectPtr<USoundBase>& GetCharacterCompletionAudio() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	float GetCharacterCompletionAudioDelay() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	UFortConversation* GetClaimConversation() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	FText GetCompletionText() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	FString GetCompletionVideoUID() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition", meta=(DisplayName="GetHiddenRewardsFromAllSources"))
	TArray<FFortHiddenRewardQuantityPair> GetHiddenRewards_BP() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	UFortConversation* GetIntroConversation() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	int32 GetObjectiveNeededToComplete() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition", meta=(DisplayName="GetObjectives"))
	TArray<FFortMcpQuestObjectiveInfo> GetObjectives_BP() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	int32 GetPartialObjectiveCompletionCount() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	FDataTableRowHandle GetPrerequisiteObjective() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	FText GetQuestHeaderToastDisplayText() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	EFortQuestType GetQuestType() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	FText GetRewardDescription() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition", meta=(DisplayName="GetRewardInfo"))
	FFortRewardInfo GetRewardInfo_BP() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition", meta=(DisplayName="GetRewardsFromAllSources"))
	TArray<FFortItemQuantityPair> GetRewards_BP() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	EFortQuestRewardType GetRewardType() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition", meta=(DisplayName="GetSelectableRewardsFromAllSources"))
	TArray<FFortMcpQuestRewardInfo> GetSelectableRewards_BP() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	UFortConversation* GetSelectRewardsConversation() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool GetUpdateObjectiveOncePerMatch() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	float GetWeight() const;

	UFUNCTION(BlueprintPure)
	bool HasComponentForWorldProcessingUpdates() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool IsDeprecated() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	virtual bool IsFeatQuest() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool IsGlyphQuest() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool IsGroupChallenge() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool IsHidden() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool IsIncludedInCategories() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool IsPunchCardQuest() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool IsTutorialQuest() const;

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, meta=(CallInEditor="true"))
	void RegenerateCompletionPathsData();
#endif

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool ShouldAutoLaunch() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool ShouldDisplayOverallQuestInformation() const;

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool ShouldDisplayStartingToast() const;

protected:
#if WITH_EDITOR
	UFUNCTION(Category="Debugging", meta=(CallInEditor="true", DisplayPriority="1"))
	virtual void DebugGrantQuest() const;
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	bool GenerateUniqueBackendNameForAllEmptyObjectives();
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	bool GenerateUniqueBackendNameForObjective(const int32 ObjectiveIndex, const EQuestEditorGenerateBackendNameReason Reason);
#endif

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="FortQuestItemDefinition")
	EFortQuestType QuestType;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition", meta=(InlineEditConditionToggle))
	uint8 bOverrideBundleVisibilityData : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition", meta=(EditCondition="bOverrideBundleVisibilityData"))
	FQuestVisibilityData QuestVisiblityData;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bShouldDisplayOverallQuestInformation : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bReportProgressAsAllObjectivesComplete : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bShouldDisplayStartingToast : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bAthenaUpdateObjectiveOncePerMatch : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bAthenaGrantRarityToken : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bShouldAutoClaim : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bShouldGetFullMatchProgress : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bAthenaMustCompleteInSingleMatch : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bUpdateObjectiveOncePerMatch : 1;

	UPROPERTY(EditAnywhere, Category="Display")
	uint8 bExpandsStormShield : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bHidden : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bSuppressQuestGrantedEvent : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bIncludedInCategories : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bAutoLaunch : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bDeprecated : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bDisableBackendConditionEvaluation : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestItemDefinition")
	uint8 bAllowTileMatching : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestItemDefinition")
	uint8 bAllowPlayNowNavigation : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestItemDefinition")
	uint8 bAllowMissionAlertMatchesBypassingTileRequirements : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bTutorialQuest : 1;

	UPROPERTY(EditAnywhere, Category="Display")
	uint8 bCanShowTimer : 1;

	UPROPERTY(EditAnywhere, Category="Display")
	uint8 bHideStageDescription : 1;

	UPROPERTY(EditAnywhere, Category="Display", meta=(EditCondition="!bHideStageDescription"))
	uint8 bShowMaxStageInDescription : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	uint8 bHideIncompleteObjectiveLocations : 1;

	UPROPERTY(EditAnywhere, Category="QuestPack")
	uint8 bZeroWeightOverride : 1;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	TSoftObjectPtr<USoundBase> CharacterCompletionAudio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestItemDefinition")
	FString CompletionVideoUID;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition", meta=(DisplayAfter="CharacterCompletionAudio", ForceUnits="Seconds"))
	float CharacterCompletionAudioDelay;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	int32 ObjectiveCompletionCount;

	UPROPERTY(EditAnywhere, Category="QuestRewards")
	TArray<FFortItemQuantityPair> Rewards;

	UPROPERTY(EditAnywhere, EditFixedSize, Category="QuestRewards")
	TArray<FQuestCompletionResult> CompletionPathResults;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="QuestRewards")
	TArray<TSoftObjectPtr<UFortItemDefinition>> ItemsToHideFromGiftBox;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="QuestRewards", meta=(InlineEditConditionToggle))
	bool bShouldUseGiftBox;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="QuestRewards", meta=(EditCondition="bShouldUseGiftBox"))
	FChallengeGiftBoxData GiftBoxToUse;
#endif

	UPROPERTY(EditAnywhere, Category="QuestRewards", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.FortQuestRewardTableRow"))
	TObjectPtr<UDataTable> RewardsTable;

	UPROPERTY(EditAnywhere, Category="QuestRewards", meta=(RowType="/Script/FortniteGame.FortQuestRewardTableRow"))
	TArray<FDataTableRowHandle> IndividualRewardTableRows;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	FString QuestPool;

	UPROPERTY(EditAnywhere, Category="QuestRewards")
	TArray<FFortHiddenRewardQuantityPair> HiddenRewards;

	UPROPERTY(EditAnywhere, Category="QuestRewards")
	TArray<FString> FeatureRewards;

	UPROPERTY(EditAnywhere, Category="QuestRewards")
	TArray<FFortMcpQuestRewardInfo> SelectableRewards;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition", meta=(TitleProperty="BackendName"))
	TArray<FFortMcpQuestObjectiveInfo> Objectives;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	FGameplayTagContainer Prerequisites;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortQuestItemDefinition")
	TSoftObjectPtr<UFortQuestItemDefinition> PrerequisiteQuest;
#endif

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	FDataTableRowHandle PrerequisiteObjective;

	UPROPERTY(EditAnywhere, Category="QuestPack", meta=(EditCondition="!bZeroWeightOverride"))
	float Weight;

	UPROPERTY(EditAnywhere, Category="QuestPack", meta=(EditCondition="!bZeroWeightOverride", RowType="/Script/FortniteGame.FortQuestWeightTableRow"))
	FDataTableRowHandle WeightOverride;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> QuestsToComplete;

	UPROPERTY(EditAnywhere, Category="Display", meta=(DisplayName="Quest Category", RowType="/Script/FortniteGame.FortCategoryTableRow"))
	FDataTableRowHandle Category;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestItemDefinition")
	TSoftObjectPtr<UFortConversation> IntroConversation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestItemDefinition")
	TSoftObjectPtr<UFortConversation> SelectRewardsConversation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestItemDefinition")
	TSoftObjectPtr<UFortConversation> ClaimConversation;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefinition")
	FText RewardDescription;

	UPROPERTY(EditAnywhere, Category="Display", meta=(MultiLine="true"))
	FText CompletionText;

	UPROPERTY(EditAnywhere, Category="Display", meta=(EditCondition="bCanShowQuestHeaderToastText"))
	FText QuestHeaderToastDisplayText;

	UPROPERTY(EditAnywhere, Category="Mission")
	TArray<FFortQuestMissionCreationContext> MissionCreationContexts;

	UPROPERTY(EditDefaultsOnly, Category="Mission")
	FFortMissionConfigDataParams MissionConfigMetadata;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	uint32 ClaimPriority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestItemDefinition")
	int32 SortPriority;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TSoftObjectPtr<UFortAbilitySet> QuestAbilitySet;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	bool bCanShowInPostMatch;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	bool bHideQuestProgressNotification;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	bool bHideQuestRewardNotification;

	UPROPERTY(EditDefaultsOnly, Category="Display", meta=(InlineEditConditionToggle))
	bool bOverrideDiscoveryPlaylist;

	UPROPERTY(EditDefaultsOnly, Category="Modular Quests", meta=(DisplayAfter="QuestDefinitionComponents"))
	bool bAllowSimultaneousQuestInstances;

	UPROPERTY(EditAnywhere, Category="Display", meta=(InlineEditConditionToggle))
	bool bCanShowQuestHeaderToastText;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UFortPlaylist> DiscoveryPlaylistOverride;

	UPROPERTY(EditDefaultsOnly, Category="Display", meta=(EditCondition="bOverrideDiscoveryPlaylist"))
	FString IslandCode;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Modular Quests")
	TArray<TObjectPtr<UFortQuestDefinitionComponent>> QuestDefinitionComponents;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="QuestTool")
	FString QuestToolTemplate;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, DuplicateTransient, Category="QuestTool")
	int32 QuestToolNextObjectiveId;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<FFortMcpQuestObjectiveInfo> BackupObjectivesForPostEditChangeLogic;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="ExperimentalQuests")
	bool bAllowCustomCompletionPath;
#endif

	UPROPERTY(EditAnywhere, Category="ExperimentalQuests", meta=(EditCondition="bAllowCustomCompletionPath"))
	TArray<FQuestCompletionPath> CompletionPaths;

};

