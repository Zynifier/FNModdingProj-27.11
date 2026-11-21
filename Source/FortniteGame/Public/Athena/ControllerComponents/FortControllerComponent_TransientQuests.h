// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "Abilities/FortAbilitySystemComponentAbilityGivenListenerInterface.h"
#include "Components/FortControllerComponent.h"
#include "FortUrgentQuestData.h"
#include "FortControllerComponent_TransientQuests.generated.h"

class AFortPlayerStateAthena;
class IQuestInstanceInterface;
class UFortQuestItem;
class UFortQuestItemComponent_UrgentQuest;
class UFortQuestItemDefinition_Athena;
class UFortUrgentQuestItemDefinition;
class UTexture2D;
enum class EFortQuestState : uint8;
enum class EPlayerBountyThreatLevel : uint8;

UENUM(BlueprintType)
enum class EPlayerBountyThreatLevel : uint8
{
	Low = 0,
	Medium = 1,
	High = 2,
	MAX = 3,
};

UENUM()
enum class EQuestAnalyticStage : uint8
{
	Granted = 0,
	AutoCompleted = 1,
	Completed = 2,
	Failed = 3,
};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_TransientQuests : public UFortControllerComponent, public IFortAbilitySystemComponentAbilityGivenListenerInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerBountyThreatLevelEnded);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerBountyThreatLevelUpdated, EPlayerBountyThreatLevel, PlayerBountyThreatLevel);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDuelEventStarted);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUrgentQuestDescOverrideChanged, const FGameplayTag&, UrgentQuestTag, const FGameplayTag&, OverrideTag);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnUrgentQuestEnded, AFortPlayerStateAthena*, PlayerStateAthena, const FGameplayTag&, UrgentQuestTag, const EFortQuestState, QuestState);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUrgentQuestFailed, AFortPlayerStateAthena*, PlayerStateAthena, const FUrgentQuestData&, UrgentQuestData);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUrgentQuestStarted, const FUrgentQuestData&, UrgentQuestData, float, EventTimeRemaining);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUrgentQuestTimeExpired, const FUrgentQuestData&, UrgentQuestData);

public:
	UFUNCTION(BlueprintPure)
	bool CheckIfQuestIsBounty(const FGameplayTag& UrgentQuestTag) const;

	UFUNCTION(BlueprintCallable)
	void CleanupCompletedQuest(const UFortQuestItemDefinition_Athena* CompletedQuestDefAthena);

	UFUNCTION(Client, Reliable)
	void ClientHandleSharedQuestsForLeavingPlayer(const FUniqueNetIdRepl& LeavingPlayerId);

	UFUNCTION(Client, Reliable)
	void ClientRemoveUrgentQuestInstanceFromOwningManager(const FString& QuestID);

	UFUNCTION(BlueprintCallable)
	void EndQueueForPlayerDuelEvent(const FGameplayTag EventTag);

	UFUNCTION(BlueprintPure)
	int32 GetTrackedHunterBountyTargetDistance() const;

	UFUNCTION(BlueprintPure)
	int32 GetTrackedHunterBountyTargetPrice() const;

	UFUNCTION(BlueprintCallable)
	void GrantTransientQuest(const UFortQuestItemDefinition_Athena* QuestDefAthenaToGrant, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena);

	UFUNCTION(BlueprintCallable)
	void SetUrgentQuestDescriptionOverride(FGameplayTag UrgentQuestTag, FGameplayTag OverrideTag);

	UFUNCTION(BlueprintCallable)
	void StartQueueForPlayerDuelEvent(const FUrgentQuestData UrgentQuestData);

	UFUNCTION(BlueprintCallable)
	void StopPlayerBountyThreatLevelUpdates();

protected:
	UPROPERTY(BlueprintAssignable)
	FOnUrgentQuestTimeExpired OnUrgentQuestTimeExpired;

	UPROPERTY(BlueprintAssignable)
	FOnUrgentQuestFailed OnUrgentQuestFailed;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerDuelEventStarted OnPlayerDuelEventStarted;

private:
	UFUNCTION()
	void AuthorityHandleParticipatingQuestAdded(const TScriptInterface<IQuestInstanceInterface>& QuestInstance);

	UFUNCTION()
	void AuthorityHandleParticipatingQuestRemoved(const TScriptInterface<IQuestInstanceInterface>& QuestInstance);

	UFUNCTION(Client, Reliable)
	void ClientBroadcastOnPlayerBountyThreatLevelUpdated(EPlayerBountyThreatLevel NewPlayerBountyThreatLevel);

	UFUNCTION(Client, Reliable)
	void ClientBroadcastOnUrgentQuestEnded(const FGameplayTag& EventTag, const EFortQuestState QuestState);

	UFUNCTION(Client, Reliable)
	void ClientBroadcastOnUrgentQuestStarted(const FUrgentQuestData& UrgentQuestData, float EventTimeRemaining);

	UFUNCTION(Client, Reliable)
	void ClientGrantTransientQuest(const UFortQuestItemDefinition_Athena* QuestItemDefAthena, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena);

	UFUNCTION(Client, Reliable)
	void ClientHandleSharedQuestAutoCompleted(const UFortQuestItemDefinition_Athena* QuestDefAthena);

	UFUNCTION(Client, Reliable)
	void ClientHandleSharedQuestGranted(const FUniqueNetIdRepl PlayerId, const UFortQuestItemDefinition_Athena* QuestDefAthena, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena, const FString& Bucket, const TArray<FString>& Playlists, const FDateTime& Expiration, const TArray<int32>& AchievedCounts);

	UFUNCTION(Client, Reliable)
	void ClientHandleSharedQuestPinned(const FUniqueNetIdRepl PlayerId, const UFortQuestItemDefinition_Athena* QuestDefAthena);

	UFUNCTION(Client, Reliable)
	void ClientHandleSharedQuestRemoved(const FUniqueNetIdRepl PlayerId, const UFortQuestItemDefinition_Athena* QuestDefAthena);

	UFUNCTION(Client, Reliable)
	void ClientHandleSharedQuestUpdated(const FUniqueNetIdRepl PlayerId, const UFortQuestItemDefinition_Athena* QuestDefAthena, const FName& BackendName, int32 StatValue, int32 Delta);

	UFUNCTION(Client, Reliable)
	void ClientRemoveThreatLevelBind();

	UFUNCTION(Client, Reliable)
	void ClientRemoveTransientQuest(const UFortQuestItemDefinition_Athena* QuestItemDefAthena) const;

	UFUNCTION(Client, Reliable)
	void ClientSetBountyHunterNPCIcon(const TSoftObjectPtr<UTexture2D>& NPCIcon);

	UFUNCTION(Client, Reliable)
	void ClientSetBountyTargetNPCIcon(const TSoftObjectPtr<UTexture2D>& NPCIcon);

	UFUNCTION()
	void OnPlayerProfileInitialized();

	UFUNCTION()
	void OnRep_TrackedHunterBountyTargetDistance();

	UFUNCTION()
	void OnUrgentTransientQuestCompleted(const UFortQuestItem* TransientQuestItem);

	UFUNCTION()
	void UrgentQuestItemComponentTimerExpired(const UFortQuestItemComponent_UrgentQuest* UrgentQuestItemComponent);

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> TrackedHunterBountyTarget;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TrackedHunterBountyTargetDistance)
	int32 TrackedHunterBountyTargetDistance;

	UPROPERTY(Transient)
	int32 TrackedHunterBountyTargetPrice;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> TrackedProtectorBountyTarget;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> TrackedPrimaryHunter;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerStateAthena>> TrackedBountyHunters;

	UPROPERTY(Transient)
	TObjectPtr<UFortUrgentQuestItemDefinition> ProtectorQuestToGrant;

	UPROPERTY(Transient)
	TObjectPtr<UFortUrgentQuestItemDefinition> TargetQuestToGrant;

	UPROPERTY(Transient)
	TArray<FUrgentQuestData> ActiveUrgentQuests;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnUrgentQuestStarted OnUrgentQuestStarted;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnUrgentQuestDescOverrideChanged OnUrgentQuestDescOverrideChanged;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnUrgentQuestEnded OnUrgentQuestEnded;

	UPROPERTY(Transient)
	TMap<FGameplayAbilitySpecHandle, TObjectPtr<UFortQuestItemDefinition_Athena>> AbilityHandleQuestDefinitions;

};

