// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HUD/FortNotificationEntry.h"
#include "FortNotificationEntry_PunchCard.generated.h"

class UAthenaChallengePunchCard;
class UFortQuestItem;
class UXpEarnedSubNotification;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortNotificationEntry_PunchCard : public UFortNotificationEntry
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TWeakObjectPtr<UFortQuestItem> CompletedQuest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengePunchCard> PunchCard;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UXpEarnedSubNotification> XpSubNotification;

};

