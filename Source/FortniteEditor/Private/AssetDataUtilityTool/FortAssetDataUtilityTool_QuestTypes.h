// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "UObject/PrimaryAssetId.h"
#include "AssetDataUtilityTool/FortAssetDataUtilityTool.h"
#include "Quests/FortQuestItemDefinitionEnums.h"
#include "Quests/FortQuestItemDefinition_AthenaEnums.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortAssetDataUtilityTool_QuestTypes.generated.h"

class UFortItemDefinition;
class UFortQuestDefinitionComponent;

UENUM()
enum class EAssetFilterType : uint8
{
	SearchByDefinition = 0,
	SearchByPrimaryAssetID = 1,
	QuestItems = 2,
};

UENUM()
enum class ERewardFilterType : uint8
{
	AllRewards = 0,
	VisibleRewards = 1,
	HiddenRewards = 2,
};

USTRUCT()
struct FQuestNameArray
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, meta=(DisplayName="Generate Quest Completion Paths"))
class UFortAssetDataUtilityToolAction_GenerateQuestCompletionPaths : public UFortAssetDataUtilityToolAction
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, meta=(DisplayName="Log Gate Abilities"))
class UFortAssetDataUtilityToolAction_LogGateAbilities : public UFortAssetDataUtilityToolAction
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, meta=(DisplayName="Detailed Quest Log Output"))
class UFortAssetDataUtilityToolAction_LogQuestReports : public UFortAssetDataUtilityToolAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolAction_LogQuestReports")
	bool bIncludeEmptyCategories;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolAction_LogQuestReports")
	bool bIncludeTagDetailsForQuests;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolAction_LogQuestReports")
	bool bIncludeVerbTagReport;

};

UCLASS(BlueprintType, meta=(DisplayName="Quest Definition Components"))
class UFortAssetDataUtilityToolFilter_HasMatchingQuestDefComponents : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_HasMatchingQuestDefComponents")
	TArray<TSoftClassPtr<UFortQuestDefinitionComponent>> QuestDefinitionComponents;

};

UCLASS(BlueprintType, meta=(DisplayName="Qs2 Quests"))
class UFortAssetDataUtilityToolFilter_IsUsingObjectiveFilters : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, meta=(DisplayName="Qs2 Quests by Objective Filter"))
class UFortAssetDataUtilityToolFilter_ObjectiveFilterTypeQs2 : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_ObjectiveFilterTypeQs2", meta=(BaseStruct="/Script/FortniteGame.ObjectiveFilter", ExcludeBaseStruct, ShowTreeView))
	TArray<FInstancedStruct> ObjectiveFilterTypes;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_ObjectiveFilterTypeQs2")
	bool bExactTypeMatchesOnly;

};

UCLASS(BlueprintType, meta=(DisplayName="Quest Completion Path Count"))
class UFortAssetDataUtilityToolFilter_QuestCompletionPathCount : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_QuestCompletionPathCount")
	FInt32Range CompletionPathCountRange;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_QuestCompletionPathCount")
	EAssetDataUtilityToolFilterResult NotQuestDefinitionBehavior;

};

UCLASS(BlueprintType, meta=(DisplayName="Quests With Specific Rewards Filter"))
class UFortAssetDataUtilityToolFilter_QuestHasRewards : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_QuestHasRewards")
	EAssetFilterType AssetFilterType;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_QuestHasRewards")
	ERewardFilterType RewardFilterType;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_QuestHasRewards", meta=(EditCondition="AssetFilterType == EAssetFilterType::SearchByDefinition"))
	TArray<TSoftClassPtr<UFortItemDefinition>> QuestRewardDefinitions;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_QuestHasRewards", meta=(EditCondition="AssetFilterType == EAssetFilterType::SearchByPrimaryAssetID && RewardFilterType == ERewardFilterType::VisibleRewards"))
	TArray<FPrimaryAssetId> QuestRewardPrimaryAssetIds;

};

UCLASS(meta=(DisplayName="Quests With Manual TemplateId in HiddenRewards"))
class UFortAssetDataUtilityToolFilter_QuestHiddenRewardsHasManualTemplateId : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, meta=(DisplayName="Quests by Subtypes"))
class UFortAssetDataUtilityToolFilter_QuestSubType : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_QuestSubType")
	TArray<EFortQuestSubtype> QuestSubTypes;

};

UCLASS(BlueprintType, meta=(DisplayName="Quests by Type"))
class UFortAssetDataUtilityToolFilter_QuestType : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_QuestType")
	TArray<EFortQuestType> QuestTypes;

};

UCLASS(BlueprintType, meta=(DisplayName="Quests using Gate GA's"))
class UFortAssetDataUtilityToolFilter_UsesGameplayAbilityGates : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, meta=(DisplayName="Qs1 Quests by Verb"))
class UFortAssetDataUtilityToolFilter_VerbTypeQs1 : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_VerbTypeQs1")
	TArray<EFortQuestObjectiveStatEvent> VerbsToFilterFor;

};

