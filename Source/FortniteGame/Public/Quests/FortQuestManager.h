// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Quests/FortQuestTypes.h"
#include "FortQuestManager.generated.h"

class AFortPlayerController;
class APawn;
class UFortMcpProfileSubgame;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UFortQuestManagerComponent;
class UFortQuestObjectiveInfo;
class UObject;
enum class EFortQuestObjectiveStatEvent : uint8;

UCLASS(Config=Game, MinimalAPI, BlueprintType)
class UFortQuestManager : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDisplayDynamicQuestUpdate, const UFortQuestObjectiveInfo*, QuestObjective, bool, bDisplayStatusUpdate, bool, bDisplayAnnouncementUpdate);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestsCompleted, const TArray<UFortQuestItem*>&, Quests);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestsGranted, const TArray<UFortQuestItem*>&, Quests);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleDynamicMulticastDelegate);

public:
	UFUNCTION(BlueprintPure, Category="Quest")
	bool CanProgressQuestInCurrentZone(const UFortQuestItemDefinition* QuestItemDefinition) const;

	UFUNCTION(BlueprintCallable, Category="Quests")
	void ForceTriggerQuestsUpdated();

	UFUNCTION(BlueprintCallable, Category="Quests")
	void GetCompletedQuests(TArray<UFortQuestItem*>& OutCompletedQuests);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Quests")
	void GetCurrentQuests(TArray<UFortQuestItem*>& OutCurrentQuests) const;

	UFUNCTION(BlueprintCallable, Category="Quest")
	int32 GetNumCompletedObjectives(const UFortQuestItemDefinition* Definition);

	UFUNCTION(BlueprintPure, Category="Quests")
	int32 GetObjectiveCompletionCount(const UFortQuestItemDefinition* Definition, FName BackendName) const;

	UFUNCTION(BlueprintPure, meta=(DeterminesOutputType="QuestManagerComponentClass"))
	UFortQuestManagerComponent* GetQuestManagerComponent(TSubclassOf<UFortQuestManagerComponent> QuestManagerComponentClass) const;

	UFUNCTION(BlueprintPure, Category="Quests")
	UFortQuestItem* GetQuestWithDefinition(const UFortQuestItemDefinition* Definition) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Quests")
	void GetSourceAndContextTags(FGameplayTagContainer& OutSourceTags, FGameplayTagContainer& OutContextTags) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasCompletedObjective(const UFortQuestItemDefinition* Definition, FDataTableRowHandle ObjectiveStatHandle) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasCompletedObjectiveWithName(const UFortQuestItemDefinition* Definition, FName BackendName) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasCompletedQuest(const UFortQuestItemDefinition* Definition) const;

	UFUNCTION()
	void InitializeQuestAbilities(APawn* PlayerPawn);

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsObjectiveInProgress(const UFortQuestItemDefinition* Definition, FDataTableRowHandle ObjectiveStatHandle) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsObjectiveWithNameInProgress(const UFortQuestItemDefinition* Definition, FName BackendName) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsQuestInProgress(const UFortQuestItemDefinition* Definition) const;

	UFUNCTION(BlueprintPure, Category="Quests")
	bool IsQuestObjectiveActive(FName ObjectiveName) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Quest", meta=(CPP_Default_AdditionalSourceTags="()", CPP_Default_TargetTags="()"))
	void SendComplexCustomStatEvent(UObject* TargetObject, FGameplayTagContainer AdditionalSourceTags, FGameplayTagContainer TargetTags, int32 Count = 1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Quest")
	void SendCustomStatEvent(FDataTableRowHandle ObjectiveStat, int32 Count);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Quest")
	void SendCustomStatEventDirect(FName ObjectiveBackendName, UFortQuestItem* QuestItem, int32 Count);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Quest")
	void SendCustomStatEventWithTags(EFortQuestObjectiveStatEvent Type, FGameplayTagContainer AdditionalSourceTags, FGameplayTagContainer TargetTags, int32 Count = 1);

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnQuestsGranted OnQuestsGranted;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FSimpleDynamicMulticastDelegate OnQuestsUpdated;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnQuestsCompleted OnQuestsCompleted;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnDisplayDynamicQuestUpdate OnDisplayDynamicQuestUpdate;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestItem>> QuestsToAddToUpdates;

private:
	UFUNCTION(BlueprintPure, meta=(DisplayName="GetPlayerController"))
	AFortPlayerController* GetPlayerControllerBP() const;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestManagerComponent>> Components;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortMcpProfileSubgame> BoundProfile;

	UPROPERTY(BlueprintReadOnly, Category="Quests", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortQuestItem>> CurrentQuests;

	UPROPERTY()
	TArray<FFortQuestObjectiveCompletion> PendingChanges;

	UPROPERTY(Transient)
	TArray<FFortAbilitySetHandle> EquippedQuestAbilities;

	UPROPERTY(Transient)
	EAthenaRebootEligiblityStatus RebootEligiblityStatus;

	UPROPERTY(Config)
	float DamageTakenEventFlushDelaySeconds;

	UPROPERTY(Config)
	float DamageEventFlushDelaySeconds;

	UPROPERTY(Config)
	float HitEventDelaySeconds;

	UPROPERTY(Config)
	float BuildingEventFlushDelaySeconds;

	UPROPERTY(Config)
	bool bDoQuestStateLogging;

	UPROPERTY(Config)
	bool bBlockQuestCompletion;

	UPROPERTY(Config)
	float XpEventFlushDelaySeconds;

	UPROPERTY(Config)
	TArray<FString> BackendObjectiveNamesToBlock;

	UPROPERTY(Config)
	TArray<FString> QuestTemplatesToBlock;

};

