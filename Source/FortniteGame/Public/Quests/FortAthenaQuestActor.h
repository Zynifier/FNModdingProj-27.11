// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortAthenaQuestActor.generated.h"

class AFortGameStateAthena;
class AFortPlayerController;
class UFortPlaylist;
class UFortQuestIconComponent;
class UFortQuestObjectiveInfo;

USTRUCT()
struct FPlayerObjectiveTracking
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerController> PlayerController;

	UPROPERTY(Transient)
	TObjectPtr<UFortQuestObjectiveInfo> CurrentObjectiveToTrack;

};

UCLASS(BlueprintType, Blueprintable)
class AFortAthenaQuestActor : public AActor
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestObjectiveUpdated, const AFortPlayerController*, PlayerController, const bool, bQuestCompleted);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSimpleQuestComponentDelegate, AFortPlayerController*, PlayerController);

public:
	UPROPERTY(BlueprintAssignable, Category="Quest")
	FSimpleQuestComponentDelegate OnObjectiveDormantDelegate;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FSimpleQuestComponentDelegate OnObjectiveActiveDelegate;

	UPROPERTY(BlueprintAssignable, Category="Quest")
	FQuestObjectiveUpdated OnObjectiveUpdatedDelegate;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Quest")
	void OnObjectiveActive(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintImplementableEvent, Category="Quest")
	void OnObjectiveDormant(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintImplementableEvent, Category="Quest")
	void OnObjectiveUpdated(AFortPlayerController* PlayerController, const bool bQuestCompleted);

	UFUNCTION(BlueprintCallable)
	void QuestLog(const FString StringToLog);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortAthenaQuestActor", meta=(EditInline="true"))
	TObjectPtr<UFortQuestIconComponent> QuestIconComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaQuestActor")
	FGameplayTag ProximityQuestTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	FString CalendarEnableEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	FGameplayTagContainer BlockedPlaylistTags;

private:
	UFUNCTION()
	void OnCalendarUpdated();

	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(Transient)
	TArray<FPlayerObjectiveTracking> PlayerObjectiveTracking;

};

