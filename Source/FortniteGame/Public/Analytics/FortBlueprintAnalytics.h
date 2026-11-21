// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Building/BuildingTypes.h"
#include "Online/FortOnlineSessionTypes.h"
#include "STW/FortTieredCollectionLayout.h"
#include "FortBlueprintAnalytics.generated.h"

class AActor;
class AController;
class ADeployableBaseCore;
class AFortMission;
class AFortPickup;
class AFortPlayerController;
class AFortPlayerPawn;
class UFortQuestItem;
class UObject;
enum class ECreativeCreatorAnalyticsType : uint8;
enum class EEnvironmentalItemEndReason : uint8;
enum class EIDScannerResult : uint8;

UENUM(BlueprintType)
enum class ECreativeCreatorAnalyticsType : uint8
{
	MatchEnd = 0,
	Heartbeat = 1,
};

UENUM(BlueprintType)
enum class EEnvironmentalItemEndReason : uint8
{
	None = 0,
	PlayerExit = 1,
	PlayerDeath = 2,
	ObjectDestroyed = 3,
};

UENUM(BlueprintType)
enum class EIDScannerResult : uint8
{
	Success_PlayerBelongsToFaction = 0,
	Success_DownedPlayer = 1,
	Success_DownedGuard = 2,
	Success_PlayerIsDisguised = 3,
	Failure_NotFromFaction = 4,
	Other = 5,
};

USTRUCT(BlueprintType)
struct FFortAnalyticsEventAttribute
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortCreativeCreatorAnalyticsEventAttribute
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeCreatorAnalyticsEventAttribute")
	FString CreatorEventName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeCreatorAnalyticsEventAttribute")
	int32 Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeCreatorAnalyticsEventAttribute")
	ECreativeCreatorAnalyticsType SendType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeCreatorAnalyticsEventAttribute")
	TSet<FUniqueNetIdRepl> List_PlayerUniqueNetID;

};

UCLASS()
class UFortBlueprintAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Analytics")
	static FFortAnalyticsEventAttribute ConstructAnalyticsAttribute(const FString AttributeName, const FString StringValue, const FGuid FGuidValue, const int32 IntValue = -1, const float floatValue = -1.000000f, const bool BoolValue = false);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(WorldContext="WorldContextObject"))
	static void FireAnalyticEventEnvironmentalItemUsed(AFortPlayerController* FortPC, AActor* EnvironmentalItem, const float SessionLength = 0.000000f, const EEnvironmentalItemEndReason SessionEndReason = EEnvironmentalItemEndReason::None, const AActor* OptionalSecondaryItem = nullptr);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(WorldContext="WorldContextObject"))
	static void FireAnalyticEventItemIDScannerUsed(AFortPlayerController* FortPC, const AActor* ConnectedActor, const FVector ScanneraPos, const EIDScannerResult IdScannerResult);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_Blueprint(const UObject* SourceBp, const FString& EventName, const FFortAnalyticsEventAttribute& Attribute);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_BlueprintArray(const UObject* SourceBp, const FString& EventName, const TArray<FFortAnalyticsEventAttribute>& Attributes);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireCreativeAnalyticsEvent_BlueprintArray(const UObject* SourceBp, const ECreativeCreatorAnalyticsType SendType, const TArray<FFortCreativeCreatorAnalyticsEventAttribute>& Array_Attributes, AActor* Volume);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(WorldContext="WorldContextObject"))
	static void FireEvent_AttemptLoadingStreamingLevel(UObject* WorldContextObject, const FString& LevelName);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fortnite | Fishing")
	static void FireEvent_BeginFishingSession(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBP", HidePin="SourceBP"))
	static void FireEvent_BuildLimitProgressDecremented(const UObject* SourceBP, AController* Destroyer, AFortMission* Mission, EFortBuildingType::Type BuildingType, int32 BuildLimitProgress, int32 BuildLimit);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBP", HidePin="SourceBP"))
	static void FireEvent_BuildLimitProgressIncremented(const UObject* SourceBP, AFortPlayerController* FortPC, AFortMission* Mission, EFortBuildingType::Type BuildingType, int32 BuildLimitProgress, int32 BuildLimit);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fortnite | Fishing")
	static void FireEvent_EndFishingSession(AFortPlayerPawn* PlayerPawn, const AFortPickup* ItemFished = nullptr, const bool bFromFishingPool = false, const AActor* ItemUsedToFish = nullptr, const FString& FishVariantTag = TEXT(""), float FishLength = 0.000000f, bool bBestCollected = false);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireEvent_ItemThrownBP(const UObject* SourceBp, const FString& ItemName, const FVector& Velocity);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBP", HidePin="SourceBP"))
	static void FireEvent_MatchmakingClientEnded(const UObject* SourceBP, bool bPartyStateIsWorldView, bool bPartyStateIsTheaterView, bool bPartyStateIsReturningToFrontEnd, bool bMatchmakingComplete, bool bLobbyStarted, bool bMatchmakingCancelled);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBP", HidePin="SourceBP"))
	static void FireEvent_MatchmakingClientStarted(const UObject* SourceBP, bool bMatchmakingStarted, bool bClientPartyStateMatchmaking, bool bClientPartyStateChangedPostMatchmaking);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBP", HidePin="SourceBP"))
	static void FireEvent_MatchmakingClientStatusTextChanged(const UObject* SourceBP, bool bMatchmakingIsLocal, bool bUserIsMatchmaking, bool bPartyIsPostMatchmaking, bool bIsStormShieldMission, const FString& QueueState, EMatchmakingState::Type MatchmakingState);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireEvent_PurchaseTierScreen_Interaction(const UObject* SourceBp, const FString& Interaction, const int32 NumberOfTiers);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(WorldContext="WorldContextObject"))
	static void FireEvent_StreamingLevelLoaded(UObject* WorldContextObject, const FString& LevelName);

	UFUNCTION(BlueprintCallable, Category="Analytics")
	static void FireEvent_StreamingMediaRelevancy(AFortPlayerController* FortPC, float Time);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireMissionAnalyticsEvent_Blueprint(const UObject* SourceBp, const FString& EventName, const FFortAnalyticsEventAttribute& Attribute);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireMissionAnalyticsEvent_BlueprintArray(const UObject* SourceBp, const FString& EventName, const TArray<FFortAnalyticsEventAttribute>& Attributes);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireQuestAnalyticsEvent_Blueprint(const UObject* SourceBp, const FString& EventName, const UFortQuestItem* Quest);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireQuestAnalyticsEvent_BlueprintArray(const UObject* SourceBp, const FString& EventName, const UFortQuestItem* Quest, const TArray<FFortAnalyticsEventAttribute>& Attributes);

};

UCLASS(MinimalAPI)
class UFortCollectionBookAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};

UCLASS()
class UFortDeployableBaseAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_CombatZone_ConsoleOpened(AFortPlayerController* FortPC);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_CombatZone_TierCompleted(AFortPlayerController* FortPC, int32 Tier, int32 FinalWave, int32 NumberOfPlayers, const TArray<ADeployableBaseCore*>& TargetCores, const TArray<ADeployableBaseCore*>& AllCores, const FFortTierCollectionLayoutOutput& CollectionData);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_CombatZone_TierFailed(AFortPlayerController* FortPC, int32 Tier, int32 Wave, int32 NumberOfPlayers, const FFortTierCollectionLayoutOutput& CollectionData);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_CombatZone_TierStarted(AFortPlayerController* FortPC, int32 Tier, int32 NumberOfPlayers, const FFortTierCollectionLayoutOutput& CollectionData);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_CombatZone_WaveFailed(AFortPlayerController* FortPC, int32 Tier, int32 Wave, int32 NumberOfPlayers, const TArray<ADeployableBaseCore*>& TargetCores, const TArray<ADeployableBaseCore*>& AllCores, const FFortTierCollectionLayoutOutput& CollectionData);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_CombatZone_WaveStarted(AFortPlayerController* FortPC, int32 Tier, int32 Wave, int32 NumberOfPlayers, const TArray<ADeployableBaseCore*>& TargetCores, const TArray<ADeployableBaseCore*>& AllCores, const FFortTierCollectionLayoutOutput& CollectionData);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_Neighborhood_ConsoleOpened(AFortPlayerController* FortPC, const FUniqueNetIdRepl& OwnerId);

};

UCLASS()
class UFortExpeditionAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortOnboardingAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_CinematicSkipped(const UObject* SourceBp, const FString& CinematicName);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_MineCartDestroyed(const UObject* SourceBp);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_TutorialCanceled(const UObject* SourceBp);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_TutorialCompleted(const UObject* SourceBp, bool WasSuccessful);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_TutorialStartupFailed(const UObject* SourceBp, const int32 MatchmakingResult);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_VinderTipPlayed(const UObject* SourceBp, const FString& VinderTipTag);

};

UCLASS()
class UFortOutpostAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostAttackWaveCompleted(const UObject* SourceBp, const FString& BuildingType, const int32 NumWavesCompleted, const bool Succeeded, const FString& Direction, const int32 DefenseLeg);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostAttackWaveStarted(const UObject* SourceBp, const FString& BuildingType, const int32 NumWavesStarted, const FString& Direction, const int32 DefenseLeg);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostBuildingActivated(const UObject* SourceBP, const FString& BuildingType, const int32 NumMissionsCompleted);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostBuildingDefended(const UObject* SourceBP, const FString& BuildingType, const int32 NumMissionsCompleted);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostDefenseEnd(const UObject* SourceBp, const int32 NumWavesStarted, const int32 NumWavesTotal, bool bSucceeded, bool bAbandoned, const int32 DefenseLeg);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostDefenseStart(const UObject* SourceBp, const int32 NumWavesTotal, const int32 DefenseLeg);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostLeaveOutpost(const UObject* SourceBp, const FString& BuildingType, const int32 NumWavesStarted, const int32 DefenseLeg);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostLoaded(const UObject* SourceBp, const int32 DefenseLeg);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostSupplyDropPickedUp(const UObject* SourceBp, const TArray<FFortAnalyticsEventAttribute>& Resourcees);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="SourceBp", HidePin="SourceBp"))
	static void FireAnalyticsEvent_OutpostTimedOut(const UObject* SourceBp);

};

UCLASS()
class UFortSurvivorAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};

