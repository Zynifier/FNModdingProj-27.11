// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HUD/FortNotificationEntry.h"
#include "FortNotificationEntry_MiniChallenge.generated.h"

class UAthenaMiniChallengeEntry;
class UFortQuestItem;
class UXpEarnedSubNotification;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortNotificationEntry_MiniChallenge : public UFortNotificationEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void TryToUpdateXpCompWithQuestReward();

private:
	UPROPERTY()
	TWeakObjectPtr<UFortQuestItem> CompletedQuest;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_MiniChallenge", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaMiniChallengeEntry> MiniChallenge;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UXpEarnedSubNotification> XpSubNotification;

};

