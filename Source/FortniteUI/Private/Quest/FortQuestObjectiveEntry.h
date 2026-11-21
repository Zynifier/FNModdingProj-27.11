// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ChallengeBundles/FortChallengeSetStyle.h"
#include "FortQuestObjectiveEntry.generated.h"

class UFortItemDefinition;
class UFortQuestObjectiveEntry;
class UFortQuestObjectiveInfo;
class UTexture2D;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FObjectiveFinishedDisplaying, UFortQuestObjectiveEntry*, QuestObjective);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestObjectiveEntry : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void HideRewardVisuals();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void ObjectiveInfoSet(const UFortQuestObjectiveInfo* ObjectiveInfo, bool IsAnnouncement, bool bQuestCompleted);

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void SetRewardVisuals(const UFortItemDefinition* RewardDef, const FText& SourceText, const FText& TypeText);

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void StartDisplayingObjective();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void UpdateChallengeBundleObjectiveVisuals(const FFortChallengeSetStyle& DisplayStyle, const FText& ChallengeBundleName);

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void UpdateCharmObjectiveVisuals(const FFortChallengeSetStyle& DisplayStyle, const FText& CharmName, const TSoftObjectPtr<UTexture2D>& CharmIcon);

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void UpdateDefaultObjectiveVisuals();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void UpdateLevelUpObjectiveVisuals();

	UPROPERTY(BlueprintCallable)
	FObjectiveFinishedDisplaying OnFinishedDisplaying;

protected:
	UPROPERTY()
	TObjectPtr<UFortQuestObjectiveInfo> MyObjectiveInfo;

};

