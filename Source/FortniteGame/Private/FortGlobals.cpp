// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGlobals.h"

bool UFortGlobals::AllowContainersInCreativeItemLists()
{
	return false;
}

bool UFortGlobals::AreFriendCodesEnabled()
{
	return false;
}

float UFortGlobals::ContentInstallationProgress(const ESubGame SubGame)
{
	return float();
}

float UFortGlobals::GameFeatureContentInstallationProgress(const EFortGameFeature GameFeature)
{
	return float();
}

EFortAccountLinkingUIConfig UFortGlobals::GetAccountLinkingUIConfig()
{
	return EFortAccountLinkingUIConfig();
}

FString UFortGlobals::GetAccountLinkingUIURL()
{
	return FString();
}

ESubGame UFortGlobals::GetCurrentSubGame(const UObject* WorldContextObject)
{
	return ESubGame();
}

float UFortGlobals::GetDoubleClickTime(const UObject* WorldContextObject)
{
	return float();
}

bool UFortGlobals::GetForceBuildingActorRecordUpdatesEnabled()
{
	return false;
}

EContentInstallState UFortGlobals::GetGameFeatureContentInstallState(const EFortGameFeature GameFeature)
{
	return EContentInstallState();
}

float UFortGlobals::GetGlobalSnowAltitude()
{
	return float();
}

FVector UFortGlobals::GetGlobalSnowOrigin()
{
	return FVector();
}

float UFortGlobals::GetGlobalSnowRadius()
{
	return float();
}

bool UFortGlobals::GetIronCityEnabled()
{
	return false;
}

bool UFortGlobals::GetIronCityEndlessEnabled()
{
	return false;
}

const TArray<FName>& UFortGlobals::GetIronCityWargameTagList()
{
	static TArray<FName> Dummy;
	return Dummy;
}

FContentInstallError UFortGlobals::GetLastOnDemandContentInstallError()
{
	return FContentInstallError();
}

int32 UFortGlobals::GetMaxTheaterListRefreshDelay()
{
	return int32();
}

int64 UFortGlobals::GetMemoryRequirementForMediaStreamingMB()
{
	return int64();
}

int32 UFortGlobals::GetMinTheaterListRefreshDelay()
{
	return int32();
}

EContentInstallState UFortGlobals::GetOnDemandContentInstallState(const ESubGame SubGame)
{
	return EContentInstallState();
}

bool UFortGlobals::GetPapayaSpeakersEnabled()
{
	return false;
}

FGameplayTagContainer UFortGlobals::GetRiskyReelsPlaylistDenylistFilter()
{
	return FGameplayTagContainer();
}

EFortStartupPhase UFortGlobals::GetStartupPhase()
{
	return EFortStartupPhase();
}

EContentInstallState UFortGlobals::GetStWTutorialContentInstallState()
{
	return EContentInstallState();
}

EPhysicalSurface UFortGlobals::GetSurfaceType(const FHitResult& Hit, const UObject* WorldContextObject)
{
	return EPhysicalSurface();
}

float UFortGlobals::GetTimeLimitForReplayCinematic(ETimeLimitForReplayCinematic TimeLimitForReplayCinematic)
{
	return float();
}

float UFortGlobals::GetTimeLimitForWatchBattlePassMovie(ETimeLimitForReplayCinematic TimeLimitForWatchBattlePassMovie)
{
	return float();
}

bool UFortGlobals::GetUseLegacyMediaSource()
{
	return false;
}

bool UFortGlobals::GetUseLegacyMediaSourceForCreative()
{
	return false;
}

void UFortGlobals::HandleClientUpdateRequired(EFortClientUpdateType Type, bool RequestExit)
{
}

bool UFortGlobals::InstallAllOnDemandContent(const ESubGame SubGame)
{
	return false;
}

bool UFortGlobals::InstallGameFeatureContent(const EFortGameFeature GameFeature)
{
	return false;
}

bool UFortGlobals::InstallStWTutorialContent()
{
	return false;
}

bool UFortGlobals::IsAccountLinkingEnabled()
{
	return false;
}

bool UFortGlobals::IsAccountLinkingUIURLButtonEnabled()
{
	return false;
}

bool UFortGlobals::IsAllContentInstalled(const ESubGame SubGame)
{
	return false;
}

bool UFortGlobals::IsBROnly()
{
	return false;
}

bool UFortGlobals::IsEnduranceDebugEnabled()
{
	return false;
}

bool UFortGlobals::IsErebus()
{
	return false;
}

bool UFortGlobals::IsErebusOrErebusPreview()
{
	return false;
}

bool UFortGlobals::IsErebusPreview()
{
	return false;
}

bool UFortGlobals::IsFirstShotAccuracyDisabled()
{
	return false;
}

bool UFortGlobals::IsFrontendCraftingEnabled()
{
	return false;
}

bool UFortGlobals::IsFrontendStorageEnabled()
{
	return false;
}

bool UFortGlobals::IsGameFeatureContentInstalled(const EFortGameFeature GameFeature)
{
	return false;
}

bool UFortGlobals::IsHeroLoadoutSystemEnabled()
{
	return false;
}

bool UFortGlobals::IsHestiaEnabled()
{
	return false;
}

bool UFortGlobals::IsInAthena(const UObject* WorldContextObject)
{
	return false;
}

bool UFortGlobals::IsInPhoenixZone(const UObject* WorldContextObject)
{
	return false;
}

bool UFortGlobals::IsInSubGame(const UObject* WorldContextObject, const ESubGame SubGame)
{
	return false;
}

bool UFortGlobals::IsIronCityAutoAmplifierPlacementEnabled()
{
	return false;
}

bool UFortGlobals::IsMobileGame(const UObject* WorldContextObject)
{
	return false;
}

bool UFortGlobals::IsNewRewardFlowEnabled()
{
	return false;
}

bool UFortGlobals::IsRunningInCloud()
{
	return false;
}

bool UFortGlobals::IsStWContentInstalled()
{
	return false;
}

bool UFortGlobals::IsStWTutorialContentInstalled()
{
	return false;
}

bool UFortGlobals::IsTencentBuild()
{
	return false;
}

bool UFortGlobals::IsTouchControlsActive(const AFortPlayerController* FortPC)
{
	return false;
}

bool UFortGlobals::IsTouchInputPlatform()
{
	return false;
}

bool UFortGlobals::IsUsingTouch(const UObject* WorldContextObject)
{
	return false;
}

bool UFortGlobals::IsWargameDebugEnabled()
{
	return false;
}

bool UFortGlobals::IsWIFEEnabled()
{
	return false;
}

void UFortGlobals::SetCurrentSubGame(const UObject* WorldContextObject, const ESubGame SubGame)
{
}

void UFortGlobals::SetGlobalSnowAltitude(float Altitude)
{
}

void UFortGlobals::SetGlobalSnowOrigin(FVector Origin)
{
}

void UFortGlobals::SetGlobalSnowRadius(float Radius)
{
}

bool UFortGlobals::ShouldDelayStartupLoading()
{
	return false;
}

bool UFortGlobals::ShouldDisableParticleEffectsDuringMissionResults()
{
	return false;
}

bool UFortGlobals::ShouldDisablePlayerTeleportDuringMissionResults()
{
	return false;
}

bool UFortGlobals::ShouldFlushGPUWhenPlayerIsTeleportedAtEndOfZone()
{
	return false;
}

bool UFortGlobals::ShouldShowMissionResultsMovies()
{
	return false;
}

bool UFortGlobals::ShouldStreamOutTextureDataWhenPlayerIsTeleportedAtEndOfZone()
{
	return false;
}

bool UFortGlobals::ShowExtendedBattlePassMovie()
{
	return false;
}

float UFortGlobals::StWTutorialContentInstallationProgress()
{
	return float();
}

void UFortGlobals::UpdateAllGameFeaturesOnPauseChanged()
{
}

bool UFortGlobals::UseElectraForReplayCinematic()
{
	return false;
}

bool UFortGlobals::UseElectraForWatchBattlePassMovie()
{
	return false;
}
