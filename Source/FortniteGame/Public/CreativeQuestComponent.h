// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortDeathCauseEnum.h"
#include "CreativeQuestComponent.generated.h"

class AController;
class AFortMinigame;
class AFortPlayerController;
class AFortPlayerState;
class UObject;
class UTexture2D;
enum class EFortQuestObjectiveStatEvent : uint8;

UENUM(BlueprintType)
enum class ECreativeQuestSharing : uint8
{
	Individual = 0,
	Team = 1,
	All = 2,
	MAX = 3,
};

UENUM(BlueprintType)
enum class ECreativeQuestStat : uint8
{
	None = 0 UMETA(DisplayName="Events"),
	Eliminations = 1,
	Eliminated = 2,
	Score = 3,
	ChestOpened = 4,
	LlamaOpened = 5,
	PlayerRevived = 6,
	PlayerInterrogated = 7,
	RaceCheckpointActivated = 8,
	FishFished = 9,
	WeaponFished = 10,
	PropDestroyed = 11,
	ShieldPotionConsumed = 12,
	DistanceTraveledOnFoot = 13,
	DistanceTraveledInVehicle = 14,
	DistanceTraveledInAir = 15,
	DistanceTraveled = 16,
	RoundCompleted = 17,
	RoundWon = 18,
	GameCompleted = 19,
	GameWon = 20,
	PlayTimeElapsed = 21,
	MAX = 22,
};

UENUM(BlueprintType)
enum class EShowOnHudMode : uint8
{
	/** Tracker won't be displayed on screen */
	No = 0,
	/** Tracker will only be displayed at the top left of the screen and show the description */
	Detailed = 1,
	/** Tracker will only be displayed at the top right of the screen along a maximum of 2 other trackers */
	List = 2,
	/** Tracker will display both the detailed view and in the list */
	Both = 3,
	MAX = 4,
};

UENUM(BlueprintType)
enum class EShowProgressMode : uint8
{
	Total = 0,
	Remaining = 1,
	Off = 2,
	MAX = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FQuestOnConditionsMetDelegate, UCreativeQuestComponent, OnConditionsMetDelegate, AController*, ConditionInstigator, int32, IncrementAmount);

USTRUCT()
struct FCreativeQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerState> PlayerState;

	UPROPERTY()
	int32 Progress;

	UPROPERTY()
	bool bActive;

};

USTRUCT()
struct FCreativeQuestPlayerDistanceTraveledInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerState> PlayerState;

	UPROPERTY(Transient)
	FVector LastLocation;

	UPROPERTY(Transient)
	float Distance;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UCreativeQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	TArray<AController*> GetActiveSharedControllers(AController* Instigator) const;

	UFUNCTION(BlueprintPure)
	int32 GetCurrentAmount(const AController* ForPlayer) const;

	UFUNCTION(BlueprintPure)
	bool IsActiveFor(const AController* Player) const;

	UFUNCTION(BlueprintCallable)
	void OnMinigameEnded();

	UFUNCTION(BlueprintCallable)
	void OnMinigameStarted();

	UFUNCTION(BlueprintCallable)
	void RegisterQuest(AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable)
	void ResetQuestProgress(int32 InitialAmount);

	UFUNCTION(BlueprintCallable)
	void SetActiveFor(AController* Player, bool bNewActive);

	UFUNCTION(BlueprintCallable)
	void SetCurrentAmount(const AController* ForPlayer, int32 NewAmount);

	UFUNCTION(BlueprintCallable)
	void TriggerHUDUpdate(const bool bForceUpdate = false);

	UFUNCTION(BlueprintCallable)
	void UnregisterQuest();

	UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly)
	FQuestOnConditionsMetDelegate OnConditionsMetDelegate;

private:
	UFUNCTION()
	void HandlePlayerStatChanged(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, AFortPlayerController* PlayerController, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32 Count);

	UFUNCTION()
	void OnMissionManagerCreated();

	UFUNCTION()
	void OnRep_QuestActive();

	UFUNCTION(BlueprintCallable)
	void OnRep_QuestUpdate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	ECreativeQuestStat StatToTrack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	ECreativeQuestSharing SharingMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	int32 TargetTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	int32 TargetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	int32 AssignedToTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	EDeathCause TargetDeathCause;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	bool bSelfEliminationsCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	bool bHeadshotsOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	bool bPlayerEliminationsCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	bool bNonPlayerEliminationsCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	FString QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	FString ObjectiveText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_QuestUpdate, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	int32 MinigameTargetAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_QuestUpdate, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	EShowOnHudMode ShowQuestOnHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	EShowProgressMode ShowProgressMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	bool bShowCompleteEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	TSoftObjectPtr<UTexture2D> QuestIconImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="CreativeQuestComponent", meta=(AllowPrivateAccess="TRUE"))
	FLinearColor QuestColor;

	UPROPERTY(ReplicatedUsing=OnRep_QuestActive)
	TArray<FCreativeQuestData> QuestIndividualData;

	UPROPERTY(ReplicatedUsing=OnRep_QuestUpdate)
	TArray<int32> QuestTeamProgress;

	UPROPERTY(ReplicatedUsing=OnRep_QuestUpdate)
	int32 QuestAllProgress;

	UPROPERTY(Replicated)
	int32 QuestInitialProgress;

	UPROPERTY(EditDefaultsOnly, Category="CreativeQuestComponent")
	float DistanceTraveledUpdateRate;

	UPROPERTY(EditDefaultsOnly, Category="CreativeQuestComponent")
	float DistancePerPoint;

	UPROPERTY()
	TObjectPtr<AFortMinigame> MyMinigame;

	UPROPERTY(Transient)
	TArray<FCreativeQuestPlayerDistanceTraveledInfo> PlayerDistanceTraveledInfos;

};

