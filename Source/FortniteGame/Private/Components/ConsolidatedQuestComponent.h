// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"
#include "ConsolidatedQuestComponent.generated.h"

class AFortGameStateAthena;
class AFortPlayerController;
class UFortPlaylist;
class UFortQuestItemDefinition;

UENUM(BlueprintType)
enum class EQuestUpdateType : uint8
{
	ObjectiveCompleted = 0,
	QuestCompleted = 1,
	ObjectiveUpdated = 2,
	QuestUpdated = 3,
	QuestAndObjectiveUpdate = 4,
};

UENUM(BlueprintType)
enum class EQuestVisibilityResponse : uint8
{
	Hide = 0,
	// On Quest Completed or Objective Completed hide the child comps

	Show = 1,
	// On Quest Completed or Objective Completed show the child comps

	Custom = 2,
};

USTRUCT()
struct FPlayerBindTracking
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerController> PlayerController;

};

UCLASS(BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UConsolidatedQuestComponent : public USceneComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FQuestComponentCustomUpdatedOjective, AFortPlayerController*, PlayerController, int32, AchievedCount, int32, RequiredCount);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestComponentCustomVisualsPassed, AFortPlayerController*, PlayerController, bool, bFullyInitalized);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestComponentStageChaged, const AFortPlayerController*, PlayerController, int32, UpdatedQuestStage);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSimpleQuestComponentDelegate, AFortPlayerController*, PlayerController);

public:
	UFUNCTION(BlueprintPure)
	UFortQuestItemDefinition* GetQuestItemDefinition() const;

	UFUNCTION(BlueprintCallable)
	void SetObjectiveBackendName(const FName& InObjectiveBackendName);

	UFUNCTION(BlueprintCallable)
	void SetQuestItemDefinition(UFortQuestItemDefinition* InQuestItemDefinition);

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FSimpleQuestComponentDelegate OnQuestNotReady;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FSimpleQuestComponentDelegate OnQuestReady;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FSimpleQuestComponentDelegate OnServerQuestReady;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FSimpleQuestComponentDelegate OnQuestComponentSuccessEvent;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FSimpleQuestComponentDelegate OnCustomSetVisualsToFailed;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FQuestComponentStageChaged OnQuestStageChanged;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FQuestComponentCustomVisualsPassed OnCustomSetVisualsToPassed;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FQuestComponentCustomUpdatedOjective OnCustomUpdateObjective;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FSimpleQuestComponentDelegate OnUpdateQuest;

protected:
	UFUNCTION(BlueprintCallable)
	bool IsInteractable(AFortPlayerController* InteractingController);

	UFUNCTION(BlueprintCallable)
	void UpdateCompletedForPlayer(AFortPlayerController* InPlayerController, bool bCompleted);

	UPROPERTY(EditAnywhere, Category="Quest")
	TObjectPtr<UFortQuestItemDefinition> QuestItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest", meta=(GetOptions="Editor_GetValidObjectives"))
	FName ObjectiveBackendName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	FString CalendarEnableEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	FGameplayTagContainer BlockedPlaylistTags;

	UPROPERTY(EditAnywhere, Category="Quest")
	EQuestVisibilityResponse ComponentResponse;

	UPROPERTY(EditAnywhere, Category="Quest")
	EQuestUpdateType UpdateType;

	UPROPERTY(EditAnywhere, Category="Quest")
	bool bIsInteractable;

private:
	UFUNCTION()
	TArray<FName> Editor_GetValidObjectives() const;

	UFUNCTION()
	void OnCalendarUpdated();

	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

};

