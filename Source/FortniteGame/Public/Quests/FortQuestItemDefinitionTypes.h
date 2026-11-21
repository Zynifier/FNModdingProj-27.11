// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortItemQuantityPair.h"
#include "Quests/FortQuestItemDefinitionEnums.h"
#include "FortQuestItemDefinitionTypes.generated.h"

class UFortConversation;
class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FFeatSeriesObjectiveStep
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FeatSeriesObjectiveStep")
	int32 Count;

};

USTRUCT(BlueprintType)
struct FFortCategoryTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCategoryTableRow")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCategoryTableRow")
	int32 SortPriority;

};

USTRUCT(BlueprintType)
struct FFortMcpQuestObjectiveDisplayInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	int32 DisplayStage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	int32 DisplayMaxStage;

};

USTRUCT(BlueprintType)
struct FFortMcpQuestRewardInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMcpQuestRewardInfo")
	TArray<FFortItemQuantityPair> Rewards;

};

USTRUCT(BlueprintType)
struct FFortObjectiveConversation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveConversation")
	TSoftObjectPtr<UFortConversation> ConversationRef;

	UPROPERTY(EditAnywhere, Category="FortObjectiveConversation")
	uint8 MaxPlays;

};

USTRUCT(BlueprintType)
struct FFortObjectiveConversationTriggerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveConversationTriggerInfo")
	EObjectiveConversationTriggerType TriggerType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveConversationTriggerInfo")
	uint16 StatTarget;

	UPROPERTY(EditAnywhere, Category="FortObjectiveConversationTriggerInfo")
	TArray<FFortObjectiveConversation> ConversationList;

};

USTRUCT(BlueprintType)
struct FFortQuestRewardTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestRewardTableRow")
	FString QuestTemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestRewardTableRow")
	FName TemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestRewardTableRow")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestRewardTableRow")
	bool Hidden;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestRewardTableRow")
	bool Feature;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestRewardTableRow")
	bool Selectable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestRewardTableRow")
	bool Exportable;

};

USTRUCT(BlueprintType)
struct FFortQuestRewardTableCacheData : public FFortQuestRewardTableRow
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortQuestRewardTableCacheData")
	TSoftObjectPtr<UFortItemDefinition> ItemPtr;

};

USTRUCT(BlueprintType)
struct FFortQuestWeightTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestWeightTableRow")
	float Weight;

};

