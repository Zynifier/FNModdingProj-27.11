// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "FortEndZoneScoreAndAwards.h"
#include "FortSubGameTypes.h"
#include "FortRegisteredPlayerInfo.generated.h"

class AFortPlayerState;
class UAbilitySystemComponent;
class UFortCollectionBookManager;
class UFortCustomizationAssetLoader;
class UFortExpeditionManager;
class UFortHero;
class UFortLinkedAccountManager;
class UFortMcpProfileAthena;
class UFortMcpProfileCampaign;
class UFortMcpProfileCollections;
class UFortMcpProfileCommonCore;
class UFortMcpProfileCommonPublic;
class UFortMcpProfileCreative;
class UFortMcpProfileMetadata;
class UFortMcpProfileSubgame;
class UFortMcpProfileWorld;
class UFortMinigameManager;
class UFortQuestManager;
enum class ESubGame : uint8;

UENUM()
enum class ERegisteredPlayerUnregistrationStatus : uint8
{
	Registered = 0,
	// User is currently registered, no attempt at unregistration

	UnregistrationStarting = 1,
	// User is starting the unregistration process

	UnregistrationWaitingForInitialLock = 2,
	// User has not yet acquired the initial profile lock but has a request in flight, waiting for it to return before proceeding

	UnregistrationWaitingForScoreSave = 3,
	// User has requested score be saved before unregistration is complete and is waiting for it

	UnregistrationWaitingForFinalSave = 4,
	// User has requested a save before unregisteration is complete and is waiting for it

	UnregistrationWaitingForProfileUnlock = 5,
	// User has requested their profile lock be relinquished and is waiting for it to complete

	UnregistrationComplete = 6,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAbilitySystemActorChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestManagerCreated, const ESubGame, SubGame, UFortMcpProfileSubgame*, McpProfile);

UCLASS(MinimalAPI, BlueprintType)
class UFortRegisteredPlayerInfo : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AbilitySystem")
	UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UFUNCTION(BlueprintPure, Category="PlayerInfo")
	FString GetPlayerName() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerState* GetPlayerState() const;

	UPROPERTY(BlueprintAssignable, Category="PlayerInfo")
	FQuestManagerCreated OnQuestManagerCreatedDelegate;

	UPROPERTY(BlueprintAssignable, Category="PlayerInfo")
	FAbilitySystemActorChanged OnAbilitySystemActorChangedChangedDelegate;

private:
	UFUNCTION()
	void HandleDifferentHeroLoadoutActivated(const UFortMcpProfileCampaign* Profile);

	UPROPERTY()
	FUniqueNetIdRepl PlayerId;

	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	FUniqueNetIdRepl PartyLeaderId;

	UPROPERTY()
	FString Platform;

	UPROPERTY()
	uint8 TeamAssignment;

	UPROPERTY()
	int32 PlayerIndex;

	UPROPERTY()
	bool bIsInitialPlayer;

	UPROPERTY()
	bool bShouldLockProfile;

	UPROPERTY()
	bool bFailedToLockProfile;

	UPROPERTY()
	FGuid UnregistrationSaveGUID;

	UPROPERTY()
	ERegisteredPlayerUnregistrationStatus UnregistrationStatus;

	UPROPERTY()
	FTimerHandle UnregisterFailsafeTimerHandle;

	UPROPERTY()
	FTimerHandle PollForDedicatedServerReadyToShutdownTimerHandle;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileCommonPublic> CommonPublicProfile;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileCommonCore> CommonCoreProfile;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileCampaign> AccountProfile;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileWorld> WorldProfile;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileWorld> OutpostProfile;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileMetadata> MetadataProfile;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileCreative> CreativeModeProfile;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileCollections> CollectionsProfile;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileAthena> AthenaProfile;

	UPROPERTY(meta=(DeprecatedProperty))
	TObjectPtr<UFortQuestManager> QuestManagers[2];

	UPROPERTY()
	TObjectPtr<UFortQuestManager> QuestManager;

	UPROPERTY(Export, meta=(EditInline="true"))
	TMap<ESubGame, TObjectPtr<UFortMinigameManager>> MinigameManagers;

	UPROPERTY()
	TObjectPtr<UFortCollectionBookManager> CollectionBookManager;

	UPROPERTY()
	TObjectPtr<UFortExpeditionManager> ExpeditionManager;

	UPROPERTY()
	TObjectPtr<UFortLinkedAccountManager> LinkedAccountManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortHero> TempAthenaMenuHeroInstance;

	UPROPERTY(Transient)
	bool bAthenaMenuHeroDirty;

	UPROPERTY(Transient)
	TObjectPtr<UFortCustomizationAssetLoader> CustomizationAssetLoader;

	UPROPERTY(Transient)
	FEndZoneScoreAndAwards EndZoneScoreAndAwards;

};

