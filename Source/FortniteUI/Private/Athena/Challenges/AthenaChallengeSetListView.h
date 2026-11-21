// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Challenges/AthenaChallengeListView.h"
#include "AthenaChallengeSetListView.generated.h"

class UAthenaChallengeListEntry_CompletionReward;
class UAthenaChallengeListEntry_Header;
class UAthenaChallengeListEntry_StoreOffer;

USTRUCT()
struct FAthenaChallengeListVisualOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaChallengeListVisualOptions")
	bool bHideHeaders;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListVisualOptions")
	bool bHideCompletionRewards;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListVisualOptions")
	bool bHideQuestRewards;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListVisualOptions")
	bool bUseCompactActionInfo;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListVisualOptions")
	bool bHideLockedQuests;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListVisualOptions")
	bool bHideCompletedQuests;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListVisualOptions")
	bool bShowOnlyCurentBundleLevelChallenges;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListVisualOptions")
	bool bSortCompletedToEnd;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeListVisualOptions")
	int32 PreviewBundleLevel;

};

UCLASS()
class UAthenaChallengeSetListView : public UAthenaChallengeListViewBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AthenaChallengeSetListView")
	FAthenaChallengeListVisualOptions ListVisualOptions;

	UPROPERTY(VisibleAnywhere, Category="AthenaChallengeSetListView")
	bool bHideHeaders;

	UPROPERTY(VisibleAnywhere, Category="AthenaChallengeSetListView")
	bool bHideCompletionRewards;

	UPROPERTY(VisibleAnywhere, Category="AthenaChallengeSetListView")
	bool bHideQuestRewards;

	UPROPERTY(VisibleAnywhere, Category="AthenaChallengeSetListView")
	bool bUseCompactActionInfo;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeSetListView")
	bool bAllowFocus;

private:
	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UAthenaChallengeListEntry_Header> SectionHeaderEntryClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UAthenaChallengeListEntry_CompletionReward> CompletionRewardEntryClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UAthenaChallengeListEntry_StoreOffer> SpecialOfferEntryClass;

};

