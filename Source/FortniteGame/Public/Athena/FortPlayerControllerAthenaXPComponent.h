// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "UObject/PrimaryAssetId.h"
#include "ChallengeBundles/FortMedalsPunchCardItem.h"
#include "Components/FortControllerComponent.h"
#include "Online/AthenaLevelInfo.h"
#include "Quests/FortQuestObjectiveStatXPTable.h"
#include "Quests/FortQuestTypes.h"
#include "FortPlayerControllerAthenaXPComponent.generated.h"

class IQuestInstanceInterface;
class UAthenaSeasonItemDefinition;
class UFortAccoladeItemDefinition;
class UFortPlayerControllerAthenaXPComponent;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UTexture2D;

USTRUCT()
struct FXPEventEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText SimulatedXpEvent;

	UPROPERTY()
	FText SimulatedXpName;

	UPROPERTY()
	TObjectPtr<UFortQuestItemDefinition> QuestDef;

	UPROPERTY(NotReplicated)
	TObjectPtr<UFortAccoladeItemDefinition> AccoladeDef;

	UPROPERTY()
	FPrimaryAssetId Accolade;

	UPROPERTY()
	float Time;

	UPROPERTY(NotReplicated)
	int32 OldXPValue;

	UPROPERTY(NotReplicated)
	int32 OldLevel;

	UPROPERTY(NotReplicated)
	int32 NewXPValue;

	UPROPERTY(NotReplicated)
	int32 NewLevel;

	UPROPERTY()
	int32 EventXpValue;

	UPROPERTY()
	int32 TotalXpEarnedInMatch;

	UPROPERTY()
	int32 RemainingRestXP;

	UPROPERTY()
	TSoftObjectPtr<UTexture2D> AccoladeLargePreviewImageOverride;

	UPROPERTY()
	EFortSimulatedXPSize SimulatedXpSize;

};

USTRUCT()
struct FXPEventArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FXPEventEntry> Entries;

	UPROPERTY(NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerControllerAthenaXPComponent> ParentComp;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerControllerAthenaXPComponent : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable, WithValidation)
	void ClientMedalsRecived(const TArray<FAthenaAccolades>& Medals);

	UFUNCTION(Client, Reliable, WithValidation)
	void ClientQuestsUpdated(const TArray<FFortQuestObjectiveCompletion>& PendingQuestChanges);

	UFUNCTION()
	void HandleLateQuestUpdated(const TScriptInterface<IQuestInstanceInterface>& QuestInstance);

protected:
	UFUNCTION(Client, Reliable, WithValidation)
	void ClientInitForUEFN(const FString& SeasonTemplate, const int32 PlayerCurrentLevel, const int32 PlayerCurrentXp);

	UFUNCTION()
	void InitRestedXp();

	UFUNCTION()
	void OnInMatchProfileUpdate(int64 ProfileRevision);

	UFUNCTION()
	void OnProfileUpdated();

	UFUNCTION()
	void OnRep_bRegisteredWithQuestManager();

	UFUNCTION()
	void OnRep_HasBRMatchReportCompletedProfileVer();

	UFUNCTION()
	void OnRep_InMatchProfileVer();

	UFUNCTION()
	void OnXPEvent(const FXPEventInfo& XPEvent);

	UFUNCTION()
	void OnXpUpdated(int32 InCombatXp, int32 InSurvivalXp, int32 InBonusMedalXp, int32 InChallengeXp, int32 InMatchXp, int32 InTotalXp);

	UPROPERTY(Transient)
	TArray<FAthenaAccolades> PlayerAccolades;

	UPROPERTY(Transient)
	TArray<FCardSlotMedalData> LocalPunchCardMedals;

	UPROPERTY(Replicated)
	FXPEventArray EventArray;

	UPROPERTY()
	TArray<FXPEventEntry> WaitingQuestXp;

	UPROPERTY(Replicated)
	int32 RestXp;

	UPROPERTY(ReplicatedUsing=OnRep_bRegisteredWithQuestManager)
	bool bRegisteredWithQuestManager;

	UPROPERTY()
	FAthenaLevelInfo CachedLevelInfo;

	UPROPERTY()
	TObjectPtr<UAthenaSeasonItemDefinition> CachedSeasonDef;

	UPROPERTY()
	int32 CachedSeasonMatchXpBoost;

	UPROPERTY()
	int32 CurrentLevel;

	UPROPERTY()
	int32 PlayerXp;

	UPROPERTY(Replicated)
	int32 TotalXpEarned;

	UPROPERTY(Replicated)
	int32 MedalBonusXp;

	UPROPERTY(Replicated)
	int32 SurvivalXp;

	UPROPERTY(Replicated)
	int32 CombatXp;

	UPROPERTY(Replicated)
	int32 MatchXp;

	UPROPERTY(Replicated)
	int32 ChallengeXp;

	UPROPERTY(ReplicatedUsing=OnRep_HasBRMatchReportCompletedProfileVer)
	int64 HasBRMatchReportCompletedProfileVer;

	UPROPERTY(ReplicatedUsing=OnRep_InMatchProfileVer)
	int64 InMatchProfileVer;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAccoladeItemDefinition>> MedalsEarned;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UFortQuestItem>> QuestsUpdated;

private:
	UFUNCTION(Server, Unreliable)
	void ServerUpdateCurrentLevel(int32 NewCurrentLevel);

};

