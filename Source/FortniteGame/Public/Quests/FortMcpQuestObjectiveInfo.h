// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "FortInventoryFilterEnum.h"
#include "Quests/FortQuestItemDefinitionEnums.h"
#include "Quests/FortQuestItemDefinitionTypes.h"
#include "Quests/FortQuestObjectiveStatTable.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortMcpQuestObjectiveInfo.generated.h"

class AFortScriptedAction;
class UFortItemDefinition;
class UTexture2D;

USTRUCT(BlueprintType)
struct FFortMcpQuestObjectiveInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMcpQuestObjectiveInfo")
	FName BackendName;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo", meta=(BaseStruct="/Script/FortniteGame.ObjectiveFilter", ExcludeBaseStruct))
	TArray<FInstancedStruct> ObjectiveFilters;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	TArray<FFortQuestObjectiveStat> InlineObjectiveStats;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	FGameplayTagContainer ProximityQuestTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMcpQuestObjectiveInfo")
	EFortQuestObjectiveItemEvent ItemEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMcpQuestObjectiveInfo")
	uint8 bHidden : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMcpQuestObjectiveInfo")
	uint8 bRequirePrimaryMissionCompletion : 1;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	uint8 bCanProgressInZone : 1;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	uint8 bDisplayDynamicAnnouncementUpdate : 1;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	EObjectiveStatusUpdateType DynamicStatusUpdateType;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	EFortInventoryFilter LinkVaultTab;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	EFortFrontendInventoryFilter LinkToItemManagement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftObjectPtr<UFortItemDefinition> ItemReference;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	FString ItemTemplateIdOverride;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	FName LinkSquadID;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	int32 LinkSquadIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMcpQuestObjectiveInfo", meta=(DisplayName="Objective Description", MultiLine="true"))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HUD", meta=(MultiLine="false"))
	FText HudShortDescription;

	UPROPERTY(EditAnywhere, Category="HUD")
	TSoftObjectPtr<UTexture2D> HudIcon;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	TArray<FFortObjectiveConversationTriggerInfo> ObjectiveConversations;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	FFortMcpQuestObjectiveDisplayInfo ObjectiveDisplayInfo;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo")
	int32 Stage;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo", meta=(DisplayAfter="DynamicStatusUpdateType"))
	int32 DynamicStatusUpdatePercentInterval;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo", meta=(DisplayAfter="DynamicStatusUpdatePercentInterval", ForceUnits="Seconds"))
	float DynamicUpdateCompletionDelay;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo", meta=(AssetBundles="MenuCampaign"))
	TSoftClassPtr<AFortScriptedAction> ScriptedAction;

	UPROPERTY(EditAnywhere, Category="FortMcpQuestObjectiveInfo", meta=(AssetBundles="Menu"))
	TSoftClassPtr<AFortScriptedAction> FrontendScriptedAction;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMcpQuestObjectiveInfo", meta=(RowType="/Script/FortniteGame.FortQuestObjectiveStatTableRow"))
	FDataTableRowHandle ObjectiveStatHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMcpQuestObjectiveInfo", meta=(RowType="/Script/FortniteGame.FortQuestObjectiveStatTableRow"))
	TArray<FDataTableRowHandle> AlternativeStatHandles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMcpQuestObjectiveInfo")
	int32 Count;

};

