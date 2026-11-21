// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "QuestInteractableComponent.generated.h"

class AActor;
class AFortGameStateAthena;
class AFortPlayerController;
class AQuestVisual;
class UFortPlaylist;
class UFortQuestItemDefinition;
class UFortQuestManager;
class UFortQuestObjectiveInfo;

UCLASS(BlueprintType, HideCategories=("Trigger", "Sockets", "Tags", "AssetUserData", "Collision", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UQuestInteractableComponent : public USceneComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FQuestVisualDynamicMulticastDelegate, AQuestVisual*, QuestVisual);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleDynamicMulticastDelegate);

public:
	UFUNCTION(BlueprintCallable)
	UFortQuestManager* GetQuestManagerForActor(AActor* InActor);

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FSimpleDynamicMulticastDelegate SetupForServer;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FSimpleDynamicMulticastDelegate Unavailable;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FQuestVisualDynamicMulticastDelegate ClientQuestVisualCreated;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FSimpleDynamicMulticastDelegate ClientQuestEnabled;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FSimpleDynamicMulticastDelegate ClientQuestDisabled;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FSimpleDynamicMulticastDelegate ClientQuestObjectiveComplete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
	FString CalendarEnableEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
	FGameplayTagContainer BlockedPlaylistTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
	TObjectPtr<UFortQuestItemDefinition> QuestItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest", meta=(GetOptions="Editor_GetValidObjectives"))
	FName ObjectiveBackendName;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest Developer")
	bool Developer_ForceActive;
#endif

protected:
	UFUNCTION()
	void OnCalendarUpdated();

	UFUNCTION()
	void OnDisplayDynamicQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool bDisplayStatusUpdate, bool bDisplayAnnouncementUpdate);

	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnRep_Ready();

private:
	UFUNCTION()
	TArray<FName> Editor_GetValidObjectives() const;

	UPROPERTY()
	FTimerHandle DelayUntilCurrentQuestsReady;

	UPROPERTY(ReplicatedUsing=OnRep_Ready)
	bool bReady;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerController>> LocalPlayersOnTheQuest;

	UPROPERTY(EditAnywhere, Category="Quest Visuals")
	TSoftClassPtr<AQuestVisual> QuestVisualClass;

	UPROPERTY(EditAnywhere, Category="Behavior")
	bool bDestroyActorWhenUnavailable;

};

