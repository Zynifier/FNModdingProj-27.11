// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/SoftObjectPath.h"
#include "FortItemQuantityPair.h"
#include "FortRarityEnum.h"
#include "Missions/MissionTypes.h"
#include "Quests/FortMcpQuestObjectiveInfo.h"
#include "Quests/FortQuestItemDefinitionEnums.h"
#include "Quests/FortQuestItemDefinitionTypes.h"
#include "SFortMakeDesignQuestAssetForm.generated.h"

class ABuildingActor;
class ABuildingDeco;
class UBlueprint;
class UFortMissionInfo;
class UFortMissionWeightedRewards;
class UFortNeverPersistItemDefinition;
class UFortQuestItemDefinition;
class UStaticMesh;
class UTexture2D;

UENUM()
enum class EDesignerQuestTypes : uint8
{
	Fetch = 0,
	GatherAndCollect = 1,
};

USTRUCT()
struct FFetchQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FetchQuestData")
	bool bCreateQuestProp;

	UPROPERTY(EditAnywhere, Category="FetchQuestData")
	TObjectPtr<UBlueprint> ExistingQuestPropBlueprint;

	UPROPERTY(EditAnywhere, Category="FetchQuestData")
	FName QuestPropBlueprintName;

	UPROPERTY(EditAnywhere, Category="FetchQuestData")
	int32 QuantityOfPropActorsToSpawn;

	UPROPERTY(EditAnywhere, Category="FetchQuestData")
	TObjectPtr<UStaticMesh> PropStaticMesh;

	UPROPERTY(EditAnywhere, Category="Conversations")
	bool bCreateQuestPropInitialConversation;

	UPROPERTY(EditAnywhere, Category="Conversations")
	int32 NumQuestPropConversationStages;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath TemplateFetchBlueprintPath;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath TemplateQuestPropPath;

};

USTRUCT()
struct FGatherAndCollectQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	bool bCreateDroppedQuestItem;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	TObjectPtr<UFortNeverPersistItemDefinition> ExistingDroppedQuestItem;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	FName DroppedItemName;

	UPROPERTY(EditAnywhere, Category="Item")
	TArray<TSubclassOf<ABuildingActor>> BuildingActorClassesValidForHarvestDrop;

	UPROPERTY(EditAnywhere, Category="Item")
	TArray<TSubclassOf<ABuildingDeco>> DecoActorClassesValidForHarvestDrop;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	float ItemDropChancePercent;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	int32 ItemMinDropQuantity;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	int32 ItemMaxDropQuantity;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	float MinDurationBetweenDrops;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	int32 MaxFailedDropsInARow;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	int32 NumConversationStages;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	TObjectPtr<UStaticMesh> DroppedItemStaticMesh;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	EFortRarity DroppedItemRarity;

	UPROPERTY(EditAnywhere, Category="GatherAndCollectQuestData")
	float MiniMapViewableDistance;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath TemplateGatherAndCollectBlueprintPath;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath DefaultSmallPreviewImagePath;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath MiniMapIconBrushPath;

};

USTRUCT()
struct FQuestItemDefinitionDesignerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Main")
	EDesignerQuestTypes QuestTypeToCreate;

	UPROPERTY(EditAnywhere, Category="Main")
	FName QuestBackEndName;

	UPROPERTY(EditAnywhere, Category="Main")
	FString CoreName;

	UPROPERTY(EditAnywhere, Category="Main")
	FFetchQuestData FetchQuestData;

	UPROPERTY(EditAnywhere, Category="Main")
	FGatherAndCollectQuestData GatherAndCollectData;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	TObjectPtr<UFortQuestItemDefinition> ExistingQuestItemDefinition;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	bool bCreateQuestItemDefinition;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	FName QuestItemDefinitionName;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	EFortQuestType QuestType;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	TArray<FFortItemQuantityPair> Rewards;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	TArray<FFortHiddenRewardQuantityPair> HiddenRewards;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	TArray<FFortMcpQuestRewardInfo> SelectableRewards;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	TArray<FFortMcpQuestObjectiveInfo> Objectives;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	FDataTableRowHandle Category;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	FText QuestItemDisplayName;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	FText QuestItemDescription;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	TSoftObjectPtr<UTexture2D> QuestItemSmallPreviewImage;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	TSoftObjectPtr<UTexture2D> QuestItemLargePreviewImage;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition")
	FText RewardDescription;

	UPROPERTY(EditAnywhere, Category="QuestItemDefinition", meta=(MultiLine="true"))
	FText CompletionText;

	UPROPERTY(EditAnywhere, Category="QuestBlueprint")
	TObjectPtr<UBlueprint> ExistingQuestBlueprint;

	UPROPERTY(EditAnywhere, Category="QuestBlueprint")
	bool bCreateQuestBlueprint;

	UPROPERTY(EditAnywhere, Category="QuestBlueprint")
	FName QuestBlueprintName;

	UPROPERTY(EditAnywhere, Category="MissionInfo")
	TObjectPtr<UFortMissionInfo> ExistingMissionInfo;

	UPROPERTY(EditAnywhere, Category="MissionInfo")
	bool bCreateMissionInfo;

	UPROPERTY(EditAnywhere, Category="MissionInfo")
	FName QuestMissionInfoName;

	UPROPERTY(EditAnywhere, Category="MissionInfo")
	TEnumAsByte<EFortMissionType::Type> MissionType;

	UPROPERTY(EditAnywhere, Category="MissionInfo")
	bool StartPlayingOnLoad;

	UPROPERTY(EditAnywhere, Category="MissionInfo")
	float ExpectedCompletionTime;

	UPROPERTY(EditAnywhere, Category="MissionInfo")
	TObjectPtr<UFortMissionWeightedRewards> WeightedRewards;

	UPROPERTY(EditAnywhere, Category="MissionInfo")
	FText MissionDescription;

	UPROPERTY(EditAnywhere, Category="Conversations")
	FName ConversationNamePrefix;

	UPROPERTY(EditAnywhere, Category="Conversations")
	bool bCreateIntroQuestConversation;

	UPROPERTY(EditAnywhere, Category="Conversations")
	bool bCreateRewardClaimQuestConversation;

	UPROPERTY(EditAnywhere, Category="Conversations")
	bool bCreateRewardSelectionQuestConversation;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath TemplateMissionInfoPath;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath TemplateConversationPath;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	bool bOpenAssetsForEdit;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	bool bNeverPersisted;

};

