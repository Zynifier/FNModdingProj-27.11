// Copyright Epic Games, Inc. All Rights Reserved.

#include "Analytics/FortBlueprintAnalytics.h"

FFortAnalyticsEventAttribute UFortBlueprintAnalytics::ConstructAnalyticsAttribute(const FString AttributeName, const FString StringValue, const FGuid FGuidValue, const int32 IntValue, const float floatValue, const bool BoolValue)
{
	return FFortAnalyticsEventAttribute();
}

void UFortBlueprintAnalytics::FireAnalyticEventEnvironmentalItemUsed(AFortPlayerController* FortPC, AActor* EnvironmentalItem, const float SessionLength, const EEnvironmentalItemEndReason SessionEndReason, const AActor* OptionalSecondaryItem)
{
}

void UFortBlueprintAnalytics::FireAnalyticEventItemIDScannerUsed(AFortPlayerController* FortPC, const AActor* ConnectedActor, const FVector ScanneraPos, const EIDScannerResult IdScannerResult)
{
}

void UFortBlueprintAnalytics::FireAnalyticsEvent_Blueprint(const UObject* SourceBp, const FString& EventName, const FFortAnalyticsEventAttribute& Attribute)
{
}

void UFortBlueprintAnalytics::FireAnalyticsEvent_BlueprintArray(const UObject* SourceBp, const FString& EventName, const TArray<FFortAnalyticsEventAttribute>& Attributes)
{
}

void UFortBlueprintAnalytics::FireCreativeAnalyticsEvent_BlueprintArray(const UObject* SourceBp, const ECreativeCreatorAnalyticsType SendType, const TArray<FFortCreativeCreatorAnalyticsEventAttribute>& Array_Attributes, AActor* Volume)
{
}

void UFortBlueprintAnalytics::FireEvent_AttemptLoadingStreamingLevel(UObject* WorldContextObject, const FString& LevelName)
{
}

void UFortBlueprintAnalytics::FireEvent_BeginFishingSession(AFortPlayerPawn* PlayerPawn)
{
}

void UFortBlueprintAnalytics::FireEvent_BuildLimitProgressDecremented(const UObject* SourceBP, AController* Destroyer, AFortMission* Mission, EFortBuildingType::Type BuildingType, int32 BuildLimitProgress, int32 BuildLimit)
{
}

void UFortBlueprintAnalytics::FireEvent_BuildLimitProgressIncremented(const UObject* SourceBP, AFortPlayerController* FortPC, AFortMission* Mission, EFortBuildingType::Type BuildingType, int32 BuildLimitProgress, int32 BuildLimit)
{
}

void UFortBlueprintAnalytics::FireEvent_EndFishingSession(AFortPlayerPawn* PlayerPawn, const AFortPickup* ItemFished, const bool bFromFishingPool, const AActor* ItemUsedToFish, const FString& FishVariantTag, float FishLength, bool bBestCollected)
{
}

void UFortBlueprintAnalytics::FireEvent_ItemThrownBP(const UObject* SourceBp, const FString& ItemName, const FVector& Velocity)
{
}

void UFortBlueprintAnalytics::FireEvent_MatchmakingClientEnded(const UObject* SourceBP, bool bPartyStateIsWorldView, bool bPartyStateIsTheaterView, bool bPartyStateIsReturningToFrontEnd, bool bMatchmakingComplete, bool bLobbyStarted, bool bMatchmakingCancelled)
{
}

void UFortBlueprintAnalytics::FireEvent_MatchmakingClientStarted(const UObject* SourceBP, bool bMatchmakingStarted, bool bClientPartyStateMatchmaking, bool bClientPartyStateChangedPostMatchmaking)
{
}

void UFortBlueprintAnalytics::FireEvent_MatchmakingClientStatusTextChanged(const UObject* SourceBP, bool bMatchmakingIsLocal, bool bUserIsMatchmaking, bool bPartyIsPostMatchmaking, bool bIsStormShieldMission, const FString& QueueState, EMatchmakingState::Type MatchmakingState)
{
}

void UFortBlueprintAnalytics::FireEvent_PurchaseTierScreen_Interaction(const UObject* SourceBp, const FString& Interaction, const int32 NumberOfTiers)
{
}

void UFortBlueprintAnalytics::FireEvent_StreamingLevelLoaded(UObject* WorldContextObject, const FString& LevelName)
{
}

void UFortBlueprintAnalytics::FireEvent_StreamingMediaRelevancy(AFortPlayerController* FortPC, float Time)
{
}

void UFortBlueprintAnalytics::FireMissionAnalyticsEvent_Blueprint(const UObject* SourceBp, const FString& EventName, const FFortAnalyticsEventAttribute& Attribute)
{
}

void UFortBlueprintAnalytics::FireMissionAnalyticsEvent_BlueprintArray(const UObject* SourceBp, const FString& EventName, const TArray<FFortAnalyticsEventAttribute>& Attributes)
{
}

void UFortBlueprintAnalytics::FireQuestAnalyticsEvent_Blueprint(const UObject* SourceBp, const FString& EventName, const UFortQuestItem* Quest)
{
}

void UFortBlueprintAnalytics::FireQuestAnalyticsEvent_BlueprintArray(const UObject* SourceBp, const FString& EventName, const UFortQuestItem* Quest, const TArray<FFortAnalyticsEventAttribute>& Attributes)
{
}

void UFortDeployableBaseAnalytics::FireAnalyticsEvent_CombatZone_ConsoleOpened(AFortPlayerController* FortPC)
{
}

void UFortDeployableBaseAnalytics::FireAnalyticsEvent_CombatZone_TierCompleted(AFortPlayerController* FortPC, int32 Tier, int32 FinalWave, int32 NumberOfPlayers, const TArray<ADeployableBaseCore*>& TargetCores, const TArray<ADeployableBaseCore*>& AllCores, const FFortTierCollectionLayoutOutput& CollectionData)
{
}

void UFortDeployableBaseAnalytics::FireAnalyticsEvent_CombatZone_TierFailed(AFortPlayerController* FortPC, int32 Tier, int32 Wave, int32 NumberOfPlayers, const FFortTierCollectionLayoutOutput& CollectionData)
{
}

void UFortDeployableBaseAnalytics::FireAnalyticsEvent_CombatZone_TierStarted(AFortPlayerController* FortPC, int32 Tier, int32 NumberOfPlayers, const FFortTierCollectionLayoutOutput& CollectionData)
{
}

void UFortDeployableBaseAnalytics::FireAnalyticsEvent_CombatZone_WaveFailed(AFortPlayerController* FortPC, int32 Tier, int32 Wave, int32 NumberOfPlayers, const TArray<ADeployableBaseCore*>& TargetCores, const TArray<ADeployableBaseCore*>& AllCores, const FFortTierCollectionLayoutOutput& CollectionData)
{
}

void UFortDeployableBaseAnalytics::FireAnalyticsEvent_CombatZone_WaveStarted(AFortPlayerController* FortPC, int32 Tier, int32 Wave, int32 NumberOfPlayers, const TArray<ADeployableBaseCore*>& TargetCores, const TArray<ADeployableBaseCore*>& AllCores, const FFortTierCollectionLayoutOutput& CollectionData)
{
}

void UFortDeployableBaseAnalytics::FireAnalyticsEvent_Neighborhood_ConsoleOpened(AFortPlayerController* FortPC, const FUniqueNetIdRepl& OwnerId)
{
}

void UFortOnboardingAnalytics::FireAnalyticsEvent_CinematicSkipped(const UObject* SourceBp, const FString& CinematicName)
{
}

void UFortOnboardingAnalytics::FireAnalyticsEvent_MineCartDestroyed(const UObject* SourceBp)
{
}

void UFortOnboardingAnalytics::FireAnalyticsEvent_TutorialCanceled(const UObject* SourceBp)
{
}

void UFortOnboardingAnalytics::FireAnalyticsEvent_TutorialCompleted(const UObject* SourceBp, bool WasSuccessful)
{
}

void UFortOnboardingAnalytics::FireAnalyticsEvent_TutorialStartupFailed(const UObject* SourceBp, const int32 MatchmakingResult)
{
}

void UFortOnboardingAnalytics::FireAnalyticsEvent_VinderTipPlayed(const UObject* SourceBp, const FString& VinderTipTag)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostAttackWaveCompleted(const UObject* SourceBp, const FString& BuildingType, const int32 NumWavesCompleted, const bool Succeeded, const FString& Direction, const int32 DefenseLeg)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostAttackWaveStarted(const UObject* SourceBp, const FString& BuildingType, const int32 NumWavesStarted, const FString& Direction, const int32 DefenseLeg)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostBuildingActivated(const UObject* SourceBP, const FString& BuildingType, const int32 NumMissionsCompleted)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostBuildingDefended(const UObject* SourceBP, const FString& BuildingType, const int32 NumMissionsCompleted)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostDefenseEnd(const UObject* SourceBp, const int32 NumWavesStarted, const int32 NumWavesTotal, bool bSucceeded, bool bAbandoned, const int32 DefenseLeg)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostDefenseStart(const UObject* SourceBp, const int32 NumWavesTotal, const int32 DefenseLeg)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostLeaveOutpost(const UObject* SourceBp, const FString& BuildingType, const int32 NumWavesStarted, const int32 DefenseLeg)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostLoaded(const UObject* SourceBp, const int32 DefenseLeg)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostSupplyDropPickedUp(const UObject* SourceBp, const TArray<FFortAnalyticsEventAttribute>& Resourcees)
{
}

void UFortOutpostAnalytics::FireAnalyticsEvent_OutpostTimedOut(const UObject* SourceBp)
{
}
