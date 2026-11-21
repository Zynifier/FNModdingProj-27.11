// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortGender.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_Wax.generated.h"

class AActor;
class AFortAthenaMutator_Wax;
class AFortAthena_WaxToken;
class AFortGameModePickup_Wax;
class AFortPlayerPawnAthena;
class AFortPlayerStateAthena;
class UAudioComponent;
class UCustomCharacterPart;
class UFortQuestItemDefinition;
class UFortWorldItemDefinition;
class UGameplayEffect;
class USoundBase;
enum class EWaxState : uint8;

UENUM()
enum class EWaxMinimapDrawMode : uint8
{
	NoDrawing = 0,
	DrawCloseAndMoveOrShoot = 1,
	DrawMoveOrShoot = 2,
	DrawAlways = 3,
};

UENUM(BlueprintType)
enum class EWaxState : uint8
{
	None = 0,
	SomewhatVisible = 1,
	ModeratelyVisible = 2,
	VeryVisible = 3,
	Undeniable = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWaxEventSignature_NoParams);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWaxEventSignature, AFortPlayerStateAthena*, WaxSubject, int32, WaxAmount);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaxTokenFlashSignature, const TArray<int32>&, PendingFlashes);

USTRUCT(BlueprintType)
struct FWaxNoStormZone
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="No Go Zone")
	FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="No Go Zone")
	FScalableFloat Radius;

};

USTRUCT(BlueprintType)
struct FWaxPartOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data")
	TArray<TObjectPtr<UCustomCharacterPart>> PartsToSwapIn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data")
	TArray<TObjectPtr<UCustomCharacterPart>> DefaultParts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data", meta=(Categories="Cosmetics.MetaTags.Theme"))
	FGameplayTag CosmeticSwapTag;

};

USTRUCT()
struct FWaxPlayerDataEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY()
	bool bPermanentlyWaxed;

	UPROPERTY(NotReplicated)
	bool bPlayerWasLeader;

	UPROPERTY()
	int32 TokenBasedPlacement;

	UPROPERTY()
	int32 CurrentTokens;

	UPROPERTY(NotReplicated)
	int32 PreviousTokens;

	UPROPERTY()
	int32 CurrentTeamTokens;

	UPROPERTY(NotReplicated)
	int32 PreviousTeamTokens;

	UPROPERTY()
	int32 CurrentKills;

	UPROPERTY(NotReplicated)
	int32 PreviousKills;

	UPROPERTY()
	int32 CurrentLives;

	UPROPERTY()
	FVector PreviousVictimLocation;

};

USTRUCT()
struct FWaxPlayerDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_Wax> OwningMutator;

	UPROPERTY()
	TArray<FWaxPlayerDataEntry> Entries;

};

USTRUCT()
struct FWaxRespawnLogicData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WaxRespawnLogicData")
	FFortRespawnLogicData BaseRespawnData;

	UPROPERTY(EditDefaultsOnly, Category="WaxRespawnLogicData")
	FScalableFloat TryPlaceByTeammates;

	UPROPERTY(EditDefaultsOnly, Category="WaxRespawnLogicData")
	FScalableFloat AlsoPlaceBehindTeammates;

	UPROPERTY(EditDefaultsOnly, Category="WaxRespawnLogicData")
	FScalableFloat MaxDistanceFromTeammates;

	UPROPERTY(EditDefaultsOnly, Category="WaxRespawnLogicData")
	FScalableFloat MinDistanceFromTeammates;

	UPROPERTY(EditDefaultsOnly, Category="WaxRespawnLogicData")
	FScalableFloat TryPlaceAwayFromLeaders;

	UPROPERTY(EditDefaultsOnly, Category="WaxRespawnLogicData")
	FScalableFloat OnlyCountLeadersAboveWaxState;

	UPROPERTY(EditDefaultsOnly, Category="WaxRespawnLogicData")
	FScalableFloat UseDirectionFromTeam;

	UPROPERTY(EditDefaultsOnly, Category="WaxRespawnLogicData")
	FScalableFloat SpawnBehindTeammateBias;

};

USTRUCT(BlueprintType)
struct FWaxVisibilityModifiers
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WaxVisibilityModifiers")
	FScalableFloat UI_VisibilityMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WaxVisibilityModifiers")
	FSlateBrush CompassIndicator;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WaxVisibilityModifiers")
	FSlateBrush MinimapIndicator;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WaxVisibilityModifiers")
	TArray<TSubclassOf<UGameplayEffect>> TemporarilyGrantedEffects;

	UPROPERTY(EditDefaultsOnly, Category="WaxVisibilityModifiers")
	TArray<TSubclassOf<UGameplayEffect>> PermanentlyGrantedEffects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WaxVisibilityModifiers")
	FScalableFloat DistanceConsideredCloseForUI;

};

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Wax : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EWaxState GetCurrentWaxState(const AFortPlayerStateAthena* Player) const;

	UFUNCTION(BlueprintPure)
	int32 GetPlayerLives(const AFortPlayerStateAthena* Player) const;

	UFUNCTION(BlueprintPure)
	int32 GetPlayerPlacement(const AFortPlayerStateAthena* Player) const;

	UFUNCTION(BlueprintPure)
	int32 GetPlayerTeamPlacement(const AFortPlayerStateAthena* Player) const;

	UFUNCTION(BlueprintPure)
	int32 GetPlayerTeamScore(const AFortPlayerStateAthena* Player) const;

	UFUNCTION(BlueprintPure)
	int32 GetTokensForPlayer(const AFortPlayerStateAthena* Player) const;

	UFUNCTION(BlueprintPure)
	int32 GetTokensToWinBP() const;

	UFUNCTION(BlueprintPure)
	void GetWaxUI_Info(float& MyPercent, float& Enemy1Pct, float& Enemy2Pct, float& Enemy3Pct, int32& MyRank) const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerInPodium(const AFortPlayerStateAthena* Player) const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerMovingOrShooting(const AFortPlayerStateAthena* Player) const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerTeamLeader(const AFortPlayerStateAthena* Player) const;

	UFUNCTION()
	void SendTokenStats();

	UFUNCTION(BlueprintPure)
	virtual bool ShouldBeUI_Visible(const AFortPlayerStateAthena* Player) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Leaders, Category="Scoring")
	TArray<TObjectPtr<AFortPlayerStateAthena>> TeamLeadersInOrder;

	UPROPERTY(BlueprintReadOnly, Category="Scoring")
	TArray<TObjectPtr<AFortPlayerStateAthena>> PlayerLeadersInOrder;

	UPROPERTY(BlueprintAssignable)
	FWaxEventSignature OnFlyingTokensApplied;

	UPROPERTY(BlueprintAssignable)
	FWaxEventSignature OnTokensAwarded;

	UPROPERTY(BlueprintAssignable)
	FWaxEventSignature OnTokensCollected;

	UPROPERTY(BlueprintAssignable)
	FWaxEventSignature_NoParams PodiumChanged;

	UPROPERTY(BlueprintAssignable)
	FWaxTokenFlashSignature OnPendingFlashes;

	UPROPERTY(BlueprintAssignable)
	FWaxEventSignature_NoParams AnyTokenChange;

protected:
	UFUNCTION()
	virtual void CommonDeadPawn(AFortPlayerPawnAthena* DeadPawn);

	UFUNCTION()
	void OnRep_Leaders();

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Wax")
	TObjectPtr<USoundBase> RespawnSound;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Wax")
	TObjectPtr<USoundBase> GameEndMusicSound;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> GameEndMusicAudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FGameplayTag LeaderSpecialActorCategoryTag;

	UPROPERTY(EditDefaultsOnly, Category="Tokens")
	TSubclassOf<AFortAthena_WaxToken> TokenClass;

	UPROPERTY(EditDefaultsOnly, Category="Tokens")
	TSubclassOf<AFortGameModePickup_Wax> TokenPickupClass;

	UPROPERTY(EditDefaultsOnly, Category="Tokens")
	TObjectPtr<UFortWorldItemDefinition> PickupItemDef;

	UPROPERTY(EditDefaultsOnly, Category="Tokens")
	FName TokenSpawnBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat TokensToWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat TokensToStartWith;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat TokenPercentDropOnElim_Podium;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat TokenPercentDropOnElim_Commoner;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat TokensAwardedPerEliminationOnKill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat ThresholdShowTeamFlashAt_One;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat ThresholdShowTeamFlashAt_Two;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat ThresholdShowTeamFlashAt_Three;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat ThresholdShowEnemyFlashAt_One;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat ThresholdShowEnemyFlashAt_Two;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat ThresholdShowEnemyFlashAt_Three;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat BigTokenAmountForSingleElim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat MediumTokenAmountForSingleElim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat UseLiteralTokenAward;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat TokensToMarkPermanentlyMaxTier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tokens")
	FScalableFloat DrawSecondGenTokensOnCompass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mechanics")
	FScalableFloat LivesToStartPlayerWith;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mechanics")
	FScalableFloat PodiumSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mechanics")
	TArray<FWaxNoStormZone> NoStormZones;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, EditFixedSize, Category="Mechanics")
	TMap<EWaxState, FWaxVisibilityModifiers> VisibilityModifiers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, EditFixedSize, Category="Mechanics")
	TMap<EWaxState, FScalableFloat> StateTokenCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mechanics")
	FScalableFloat DistanceConsideredNearbyForUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mechanics")
	FScalableFloat VelocityConsideredMovingForUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mechanics")
	FScalableFloat TimeConsideredRecentForUI;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FWaxRespawnLogicData RespawnSettings;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	FScalableFloat WaxStateAboveWhichLeadersDrawSpecialStyleOnUI;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	FScalableFloat WaxLeadersMaximumCompassDistance;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	FScalableFloat MapLeaderboard_TeamBased;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	FScalableFloat AboutToWinPopup_TeamBased;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	FScalableFloat PodiumIcons_TeamBased;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	TArray<FSlateBrush> CompassBrushesByPlace;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	TArray<FSlateBrush> SquadmateCompassBrushesByPlace;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	TArray<FSlateBrush> MapBrushesByPlace;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	TArray<FSlateBrush> SquadmateMapBrushesByPlace;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	FScalableFloat UseSquadPlacementIconsOnMap;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	FScalableFloat UseSquadPlacementIconsOnCompass;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	FScalableFloat SquadPlacementScaleOnMap;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics|Visuals")
	FVector2D SquadPlacementOffsetPct;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FScalableFloat TokenThresholdAboveWhichToWarn;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_EnemyToWinSoon;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_PlayerToWinSoon;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_PlayerTookWaxLead;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_PlayerLostWaxLead;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_WaxLeaderChanged;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	TArray<FAthenaGameMessageData> BusGameMessages;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FText ShowTextOnEnteringSpecialBuilding;

	UPROPERTY(EditAnywhere, Category="Skins")
	FGameplayTagContainer SkinMetaTagsToSkip;

	UPROPERTY(EditAnywhere, Category="Skins")
	TArray<FWaxPartOverrideData> OverrideParts;

	UPROPERTY(EditAnywhere, Category="Skins")
	FScalableFloat ShouldSwapSkins;

	UPROPERTY(Replicated)
	FWaxPlayerDataArray PlayerData;

	UPROPERTY(Transient)
	TMap<TWeakObjectPtr<AFortPlayerStateAthena>, int32> StatDataNumTokensCollectedByPlayerMap;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Wax")
	TArray<TObjectPtr<UFortQuestItemDefinition>> NumTokensCollectedStatTrackingQuestItemDefinitions;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Wax")
	FGameplayTagContainer NumTokensCollectedStatTrackingTags;

	UPROPERTY()
	TArray<TObjectPtr<AFortGameModePickup_Wax>> WaxPickupsToDraw;

private:
	UPROPERTY()
	TMap<TObjectPtr<AFortPlayerStateAthena>, float> TimeSinceLastFireMap;

	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> LastEligibleLeader;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> PlayersAboveThresholdByPlace;

	UPROPERTY()
	TMap<uint8, TObjectPtr<AFortPlayerStateAthena>> TopPlayerInSquadID;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> RegisteredWaxPickupActors;

};

UCLASS(MinimalAPI)
class UFortCheatManager_Wax : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DisableWaxRespawningLogic();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EnableWaxRespawningLogic();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetGameScore(int32 CurrentScoreAt);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetRespawnsRemaining(int32 NumberOfRespawnsRemaining);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetTargetGoalScore(int32 TargetGoalScore);

};

