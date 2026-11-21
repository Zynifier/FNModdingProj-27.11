// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Building/BuildingGameplayActorQuest.h"
#include "BuildingGameplayActorPropQuest.generated.h"

class AActor;
class AFortPlayerController;
class AFortPlayerPawnAthena;
class UConsolidatedQuestComponent;
class UFortQuestIconComponent;

USTRUCT(BlueprintType)
struct FFortOverlapData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortOverlapData")
	FGameplayTagContainer RequiredPlayerTags;

	UPROPERTY(BlueprintReadWrite, Category="FortOverlapData")
	FGameplayTagContainer ProhibitedPlayerTags;

	UPROPERTY(BlueprintReadWrite, Category="FortOverlapData")
	bool bReHideIfConditionsChange;

	UPROPERTY(BlueprintReadWrite, Category="FortOverlapData")
	bool bCompleteFromDiscovery;

	UPROPERTY(BlueprintReadWrite, Category="FortOverlapData")
	bool bTestVisualsNoQuestRequired;

	UPROPERTY(BlueprintReadWrite, Category="FortOverlapData")
	bool bOnVisualTestingCooldown;

};

UCLASS(MinimalAPI, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorPropQuest : public ABuildingGameplayActorQuest
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ActivateComponents();

	UFUNCTION(BlueprintImplementableEvent)
	void CompleteFromDiscovery();

	UFUNCTION(BlueprintImplementableEvent)
	void FxTestOverride(AFortPlayerController* FortPC);

	UFUNCTION(BlueprintPure)
	FGameplayTagContainer GetQuestTargetTags() const;

	UFUNCTION(BlueprintCallable)
	void HandleComponentOverlap_DisoveryRadius(AActor* OtherActor, FFortOverlapData OverlapData);

	UFUNCTION(BlueprintImplementableEvent)
	void HideMesh(const bool bIsInSplitScreen);

	UFUNCTION(BlueprintCallable)
	bool PlayerTagsCheck(const AFortPlayerController* FortPC, const FGameplayTagContainer RequiredPlayerTags, const FGameplayTagContainer ProhibitedPlayerTags);

	UFUNCTION(BlueprintCallable)
	void QuestLog(const FString StringToLog);

	UFUNCTION(BlueprintImplementableEvent)
	void ReHideActor(AFortPlayerController* FortPC);

	UFUNCTION(BlueprintCallable)
	void SendInteractionMessage(AActor* Author, const FGameplayTagContainer& SubjectTags);

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Conversation")
	bool bEnableConversationComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Conversation", meta=(DisplayAfter="bEnableConversationComponent", EditCondition="bEnableConversationComponent"))
	FGameplayTag ConversationEntryTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="BuildingGameplayActorPropQuest", meta=(EditInline="true"))
	TObjectPtr<UConsolidatedQuestComponent> ConsolidatedQuestComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="BuildingGameplayActorPropQuest", meta=(EditInline="true"))
	TObjectPtr<UFortQuestIconComponent> QuestIconComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingGameplayActorPropQuest")
	TObjectPtr<AFortPlayerController> FortPlayerController_TempRef;

	UPROPERTY(BlueprintReadWrite, Category="BuildingGameplayActorPropQuest")
	TMap<TObjectPtr<AFortPlayerController>, bool> FortPlayerControllerToCanInteract;

	UPROPERTY(BlueprintReadWrite, Category="BuildingGameplayActorPropQuest")
	TArray<TObjectPtr<AFortPlayerPawnAthena>> OverlapWatchedActors;

private:
	UFUNCTION()
	void OverlapTagsRecheck(FFortOverlapData OverlapData);

};

