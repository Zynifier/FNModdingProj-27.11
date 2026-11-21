// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "AthenaChallengeNpcQuestCounter.generated.h"

class UFortQuestItem;
class UFortQuestItemDefinition_Athena;
class UFortQuestObjectiveInfo;
class URichTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaChallengeNpcQuestCounter : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeNpcQuestCounter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION()
	void UpdateVisibility(const FGameplayTag& CurrentTabTag);

protected:
	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeNpcQuestCounter")
	FGameplayTagContainer ExcludedTabs;

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeNpcQuestCounter")
	FText Text_PartyTab;

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeNpcQuestCounter")
	FText Text_PersonalTab;

private:
	UFUNCTION()
	void HandleQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool bDisplayStatusUpdate, bool bDisplayAnnouncementUpdate);

	UFUNCTION()
	void HandleTransientQuestRemoved(const UFortQuestItem* QuestItem);

	UFUNCTION()
	void HandleTransientQuestStarted(const UFortQuestItem* QuestItem, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeNpcQuestCounter", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_HeaderDesc;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeNpcQuestCounter", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_MaxQuests;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeNpcQuestCounter", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_NumActiveQuests;

};

