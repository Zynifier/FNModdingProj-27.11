// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Challenges/AthenaChallengeListEntry.h"
#include "AthenaChallengeListEntryWidgets.generated.h"

class UFortQuestItem;
class UFortQuestItemDefinition_Athena;
class URichTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_AllQuestsComplete : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_Custom : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_Custom", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<URichTextBlock> RichTextBlock_DisplayText;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_PartyUp : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleTransientQuestRemoved(const UFortQuestItem* QuestItem);

	UFUNCTION()
	void HandleTransientQuestStarted(const UFortQuestItem* QuestItem, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena);

};

