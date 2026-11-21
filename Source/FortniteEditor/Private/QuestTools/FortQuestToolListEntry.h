// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "Quests/FortMcpQuestObjectiveInfo.h"
#include "FortQuestToolListEntry.generated.h"

UCLASS(Abstract, NotBlueprintable, meta=(DisableNativeTick))
class UFortQuestToolListViewBase : public UQuestEditorSubWidget, public IUserListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RefreshListView();

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestToolListEntry_NewObjective : public UFortQuestToolListViewBase
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestToolListEntry_Objective : public UFortQuestToolListViewBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnQuestObjectiveSet(const FFortMcpQuestObjectiveInfo& McpQuestObjectiveInfo, const int32 ObjectiveIndex);

};

