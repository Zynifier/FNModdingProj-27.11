// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Quests/FortQuestTypes.h"
#include "FortNavigationVisibilityComponent.generated.h"

class AActor;
class AFortPlayerController;
class UFortAccountItemDefinition;
class UFortGameStateComponent_EventLevel;
class UFortQuestItemDefinition;

UENUM(BlueprintType)
enum class EVisibilityResponse : uint8
{
	Hide = 0,
	// if it fails will show the item and turn on collision by setting bEnableCollision = true

	Show = 1,
	// if it fails will hide the item and turn off collision by setting bEnableCollision = false

	Custom = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleVisibilityResponseDelegate);

USTRUCT()
struct FCalendarRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CalendarRequirement")
	FName CalendarEventName;

	UPROPERTY(EditAnywhere, Category="CalendarRequirement")
	bool bActive;

	UPROPERTY(EditAnywhere, Category="CalendarRequirement")
	int32 DaysFromEeventStart;

};

USTRUCT()
struct FItemRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemRequirement")
	TObjectPtr<UFortAccountItemDefinition> ItemDef;

	UPROPERTY(EditAnywhere, Category="ItemRequirement")
	bool bMustOwnItem;

};

USTRUCT()
struct FObjectiveRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveRequirement", meta=(GetOptions="Editor_GetValidObjectives"))
	FName ObjectiveBackendName;

	UPROPERTY(EditAnywhere, Category="ObjectiveRequirement")
	bool bCompleted;

};

USTRUCT()
struct FProfileStatRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ProfileStatRequirement", meta=(GetOptions="Editor_GetValidProfileStats"))
	FString ProfileStat;

};

USTRUCT()
struct FQuestRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestRequirement")
	TObjectPtr<UFortQuestItemDefinition> QuestDef;

	UPROPERTY(EditAnywhere, Category="QuestRequirement")
	EFortQuestState DesiredState;

	UPROPERTY(EditAnywhere, Category="QuestRequirement")
	TArray<FObjectiveRequirement> Objectives;

};

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UFortNavigationVisibilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> WeakActor;

protected:
	UFUNCTION()
	void HandleActiveCameraChanged(FGameplayTag CameraTag);

	UFUNCTION()
	void HandlePlayerChanged(AFortPlayerController* NewRoomOwner);

	UPROPERTY(BlueprintAssignable)
	FSimpleVisibilityResponseDelegate HandleCustomPassed;

	UPROPERTY(BlueprintAssignable)
	FSimpleVisibilityResponseDelegate HandleCustomFailed;

private:
	UFUNCTION()
	TArray<FName> Editor_GetValidObjectives() const;

	UFUNCTION()
	TArray<FString> Editor_GetValidProfileStats() const;

	UFUNCTION(BlueprintCallable)
	void MakeActorHidden();

	UFUNCTION(BlueprintCallable)
	void MakeActorVisable();

	UPROPERTY(Transient)
	bool bPassedRules;

	UPROPERTY(Transient)
	int64 LastProfileRevision;

	UPROPERTY(BlueprintReadWrite, Category="FortNavigationVisibilityComponent", meta=(AllowPrivateAccess="TRUE"))
	bool bEnableCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortNavigationVisibilityComponent", meta=(AllowPrivateAccess="TRUE"))
	bool bCustomSkipCollision;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerController> RoomOwner;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortGameStateComponent_EventLevel> GSC_StreamingLevelOwner;

	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	FGameplayTagContainer ValidActiveCameraTags;

	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	FGameplayTagContainer ExcludedActiveCameraTags;

	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	TArray<FQuestRequirement> Quests;

	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	TArray<FItemRequirement> Items;

	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	TArray<FCalendarRequirement> CalendarEvents;

	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	TArray<FProfileStatRequirement> ProfileStats;

	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	FString DebugTrackingName;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	bool DebugVisibleInPIE;
#endif

	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	bool bShouldLogFails;

	UPROPERTY(Transient)
	bool debugVisibilityLastKnownState;

	UPROPERTY(EditAnywhere, Category="FortNavigationVisibilityComponent")
	EVisibilityResponse ActorResponse;

};

