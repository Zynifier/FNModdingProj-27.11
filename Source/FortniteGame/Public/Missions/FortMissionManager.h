// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "FortEventName.h"
#include "Missions/EarnedBadgeEntry.h"
#include "FortMissionManager.generated.h"

class AActor;
class AFortAIPawn;
class AFortBluGloManager;
class AFortMission;
class UFortMissionEventDelegateHolder;
class UFortMissionInfoIndicator;
class UGameplayEffect;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMissionsUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowSecondaryMissionHeadersChanged);

USTRUCT()
struct FFortMissionEventReceiverByGameplayTagQuery
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagQuery TagQueryEventDiscriminator;

	UPROPERTY()
	TObjectPtr<UFortMissionEventDelegateHolder> DelegateHolder;

};

USTRUCT()
struct FFortMissionUIActorHandle
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> AttachedActor;

	UPROPERTY()
	FVector AttachmentOffset;

	UPROPERTY()
	float MaxVisibleDistance;

	UPROPERTY()
	FGuid MissionGuid;

	UPROPERTY(Transient, NotReplicated)
	TWeakObjectPtr<UFortMissionInfoIndicator> MissionUIIndicator;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class AFortMissionManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject"))
	static bool GetSpawnLocationActorsMatchingEntryItemQuery(UObject* WorldContextObject, const FGameplayTagQuery& TagQuery, TArray<AActor*>& SpawnLocationActors);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject"))
	static bool GetSpawnLocationActorsThatHaveAddedTagsMatchingQuery(UObject* WorldContextObject, const FGameplayTagQuery& TagQuery, TArray<AActor*>& SpawnLocationActors);

	UFUNCTION()
	virtual void OnRep_CurrentUIFocusedMission();

	UFUNCTION(BlueprintPure, Category="HUD")
	bool ShouldShowSecondaryMissionHeaders() const;

	UPROPERTY()
	TArray<FFortMissionEventName> MissionEventNames;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay Effects")
	TSoftClassPtr<UGameplayEffect> PrimaryMissionGE;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnShowSecondaryMissionHeadersChanged OnShouldShowSecondaryMissionHeadersChanged;

	UPROPERTY(Transient)
	bool bDisplaySecondaryMissionHeaders;

protected:
	UFUNCTION()
	virtual void MissionsUpdated();

	UFUNCTION()
	virtual void OnRep_AllMissionEnemyClasses();

	UFUNCTION()
	void OnRep_EarnedBadgesArray();

	UFUNCTION()
	virtual void OnRep_MissionUIActors();

	UPROPERTY(Replicated)
	TObjectPtr<AFortBluGloManager> BluGloManager;

	UPROPERTY()
	TArray<TObjectPtr<AFortMission>> Missions;

	UPROPERTY(ReplicatedUsing=OnRep_AllMissionEnemyClasses)
	TArray<TSubclassOf<AFortAIPawn>> AllMissionEnemyClasses;

	UPROPERTY(Transient)
	TArray<FFortMissionEventReceiverByGameplayTagQuery> ContainerSearchedMissionReceivers;

	UPROPERTY(Transient)
	TArray<FFortMissionEventReceiverByGameplayTagQuery> HarvestedMissionReceivers;

	UPROPERTY(ReplicatedUsing=OnRep_MissionUIActors)
	TArray<FFortMissionUIActorHandle> MissionUIActors;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentUIFocusedMission)
	TObjectPtr<AFortMission> CurrentUIFocusedMission;

	UPROPERTY(Replicated)
	TObjectPtr<AFortMission> MissionClosestToPar;

	UPROPERTY(BlueprintAssignable, Category="Mission")
	FOnMissionsUpdated OnMissionsUpdated;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_EarnedBadgesArray)
	FEarnedBadgeEntryArray EarnedBadgesArray;

};

