// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Timespan.h"
#include "Athena/Challenges/AthenaChallengeListEntry.h"
#include "Quests/LockedQuestData.h"
#include "AthenaChallengeListEntry_LockedQuest.generated.h"

class UAthenaChallengeDateTimeRichTextBlock;
class UAthenaChallengeRewards;
class UCommonTextBlock;
class URichTextBlock;
enum class ELockedWidgetUnlockType : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_LockedQuest : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	const FTimespan& GetStartingUnlockTime() const;

	UFUNCTION(BlueprintPure)
	FTimespan GetTimeSinceEventStart() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitDisplayText(const ELockedWidgetUnlockType& InUnlockType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRewardsPopulated(const bool bHasRewards);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_LockedQuest", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeDateTimeRichTextBlock> DateTimeRichText_TimeUntilQuestUnlocks;

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaChallengeListEntry_LockedQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichTextBlock_ChallengesUntilUnlocked;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaChallengeListEntry_LockedQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichTextBlock_TimeUntilUnlocked;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaChallengeListEntry_LockedQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeRewards> UserWidget_Rewards;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaChallengeListEntry_LockedQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SourceObject;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaChallengeListEntry_LockedQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RepresentedObject;

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeListEntry_LockedQuest")
	FText TimeUntilQuestUnlockCompletionText;

	UPROPERTY(BlueprintReadOnly, Category="Display", meta=(AllowPrivateAccess))
	FLockedQuestRuntimeData LockedQuestData;

};

