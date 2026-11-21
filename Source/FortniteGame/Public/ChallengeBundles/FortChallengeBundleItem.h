// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortChallengeBundleItem.generated.h"

class UFortChallengeBundleItemDefinition;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UFortQuestManager;

UCLASS(MinimalAPI, BlueprintType)
class UFortChallengeBundleItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	bool CanLevelUpBundle() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	void GetAchievedCount(int32& OutTotalAchievedCount, int32& OutTotalRequiredCount) const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle", meta=(DisplayName="Get Challenge Definition"))
	UFortChallengeBundleItemDefinition* GetChallengeDefinitionBP() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	float GetPercentageComplete() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	void GetQuests(const UFortQuestManager* QuestManager, TArray<UFortQuestItem*>& OwnedQuests, TArray<UFortQuestItemDefinition*>& UnownedQuests, bool bGetAllQuestsInChain = false, bool bIgnoreInvalidGrantedQuests = false) const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	bool IsComplete() const;

	UPROPERTY(BlueprintReadOnly, Category="FortChallengeBundleItem")
	int32 num_quests_completed;

	UPROPERTY(BlueprintReadOnly, Category="FortChallengeBundleItem")
	int32 num_progress_quests_completed;

private:
	UPROPERTY(BlueprintReadOnly, Category="FortChallengeBundleItem", meta=(AllowPrivateAccess="TRUE"))
	TArray<FString> GrantedQuestInstanceIds;

	UPROPERTY()
	int32 max_allowed_bundle_level;

	UPROPERTY(Transient)
	FString challenge_bundle_schedule_id;

};

