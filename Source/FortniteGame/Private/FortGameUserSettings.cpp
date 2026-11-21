// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameUserSettings.h"

int32 UFortGameUserSettings::GetAntiAliasingMethod() const
{
	return int32();
}

FString UFortGameUserSettings::GetAudioOutputDeviceId() const
{
	return FString();
}

bool UFortGameUserSettings::GetAutoDownloadHighResTextures() const
{
	return false;
}

int32 UFortGameUserSettings::GetCachedAlienStylePoints() const
{
	return int32();
}

int32 UFortGameUserSettings::GetCachedBattleStars() const
{
	return int32();
}

int32 UFortGameUserSettings::GetCachedClaimableRewards(const FString& ClaimableRewardsPageType) const
{
	return int32();
}

int32 UFortGameUserSettings::GetCachedHighestBattlePassUnlockedPage() const
{
	return int32();
}

int32 UFortGameUserSettings::GetCachedPlayerLevel() const
{
	return int32();
}

int32 UFortGameUserSettings::GetCachedStylePoints() const
{
	return int32();
}

bool UFortGameUserSettings::GetCosmeticStreamingEnabled() const
{
	return false;
}

float UFortGameUserSettings::GetDisplayGamma() const
{
	return float();
}

bool UFortGameUserSettings::GetDLSSFrameGenerationEnabled() const
{
	return false;
}

int32 UFortGameUserSettings::GetDLSSQuality() const
{
	return int32();
}

const FFireModeData& UFortGameUserSettings::GetFireModeData() const
{
	static FFireModeData Dummy;
	return Dummy;
}

int32 UFortGameUserSettings::GetGlobalIlluminationQualityForGameMode() const
{
	return int32();
}

bool UFortGameUserSettings::GetHardwareRayTracingEnabled() const
{
	return false;
}

bool UFortGameUserSettings::GetHasSeenCreativeHeatmapTutorial() const
{
	return false;
}

bool UFortGameUserSettings::GetHasSeenCreativePhoneTutorial() const
{
	return false;
}

bool UFortGameUserSettings::GetHasSeenPanningTip() const
{
	return false;
}

bool UFortGameUserSettings::GetHasSeenTapToShoot() const
{
	return false;
}

uint32 UFortGameUserSettings::GetInstalledTextureQuality() const
{
	return uint32();
}

bool UFortGameUserSettings::GetLastSelectedFillOption() const
{
	return false;
}

int32 UFortGameUserSettings::GetMeshQuality() const
{
	return int32();
}

bool UFortGameUserSettings::GetNaniteEnabled() const
{
	return false;
}

bool UFortGameUserSettings::GetPredownloadCosmeticsEnabled() const
{
	return false;
}

int32 UFortGameUserSettings::GetReflectionQualityForGameMode() const
{
	return int32();
}

ERHIType UFortGameUserSettings::GetRenderingAPI() const
{
	return ERHIType();
}

ERHIType UFortGameUserSettings::GetRenderingAPISelection() const
{
	return ERHIType();
}

float UFortGameUserSettings::GetResolutionFraction() const
{
	return float();
}

float UFortGameUserSettings::GetSafeZone() const
{
	return float();
}

bool UFortGameUserSettings::GetShowActorsWithSeasonItemTagMapIndicators() const
{
	return false;
}

bool UFortGameUserSettings::GetShowCareerTabBang() const
{
	return false;
}

bool UFortGameUserSettings::GetShowTemperature() const
{
	return false;
}

bool UFortGameUserSettings::GetStopRenderingInBackground() const
{
	return false;
}

int32 UFortGameUserSettings::GetTemporalSuperResolutionQuality() const
{
	return int32();
}

bool UFortGameUserSettings::GetUseGPUCrashDebugging() const
{
	return false;
}

bool UFortGameUserSettings::GetUseLatencyFlash() const
{
	return false;
}

bool UFortGameUserSettings::GetUseLatencyTweak1() const
{
	return false;
}

int32 UFortGameUserSettings::GetUseLatencyTweak2() const
{
	return int32();
}

float UFortGameUserSettings::GetUserInterfaceContrast() const
{
	return float();
}

int32 UFortGameUserSettings::GetViewDistanceAndFoliageQuality() const
{
	return int32();
}

bool UFortGameUserSettings::GetWillBeLetoGame() const
{
	return false;
}

bool UFortGameUserSettings::HasRecordedStat(const FName& RecordName) const
{
	return false;
}

bool UFortGameUserSettings::IsDynamicResolutionSupported() const
{
	return false;
}

bool UFortGameUserSettings::IsEnergySavingEnabledFocusLoss() const
{
	return false;
}

bool UFortGameUserSettings::IsEnergySavingEnabledIdle() const
{
	return false;
}

bool UFortGameUserSettings::IsHeadphoneModeEnabled() const
{
	return false;
}

bool UFortGameUserSettings::IsInPerformanceMode() const
{
	return false;
}

bool UFortGameUserSettings::IsLowInputLatencyModeEnabled() const
{
	return false;
}

bool UFortGameUserSettings::IsVideoPlaybackAllowed()
{
	return false;
}

void UFortGameUserSettings::ResetScalabilityModes()
{
}

void UFortGameUserSettings::ResetToDefaultDeviceScalability()
{
}

void UFortGameUserSettings::SetAntiAliasingMethod(int32 InFrameResolveMethod)
{
}

void UFortGameUserSettings::SetAudioOutputDeviceId(const FString& InAudioOutputDeviceId)
{
}

void UFortGameUserSettings::SetAutoDownloadHighResTexturesBool(bool bValue)
{
}

void UFortGameUserSettings::SetCachedAlienStylePoints(int32 Value)
{
}

void UFortGameUserSettings::SetCachedBattleStars(int32 Value)
{
}

void UFortGameUserSettings::SetCachedClaimableRewards(const FString& ClaimableRewardsPageType, const int32 ClaimableRewards)
{
}

void UFortGameUserSettings::SetCachedHighestBattlePassUnlockedPage(int32 Value)
{
}

void UFortGameUserSettings::SetCachedPlayerLevel(int32 Value)
{
}

void UFortGameUserSettings::SetCachedStylePoints(int32 Value)
{
}

void UFortGameUserSettings::SetCosmeticStreamingEnabled_ByUser(bool bValue)
{
}

void UFortGameUserSettings::SetDisplayGamma(float InGamma)
{
}

void UFortGameUserSettings::SetDLSSFrameGenerationEnabled(bool bEnabled)
{
}

void UFortGameUserSettings::SetDLSSQuality(int32 InDLSSQuality)
{
}

void UFortGameUserSettings::SetDonutShopSequenceMarkedAsSeen(bool bHasSeen)
{
}

void UFortGameUserSettings::SetEnergySavingEnabledFocusLoss(bool bEnable)
{
}

void UFortGameUserSettings::SetEnergySavingEnabledIdle(bool bEnable)
{
}

void UFortGameUserSettings::SetGlobalIlluminationQualityForGameMode(int32 NewGlobalIlluminationQuality)
{
}

void UFortGameUserSettings::SetHardwareRayTracingEnabled(bool bEnable)
{
}

void UFortGameUserSettings::SetHasSeenCreativeHeatmapTutorial(bool bHasSeenCreativeHeatmapTutorial)
{
}

void UFortGameUserSettings::SetHasSeenCreativePhoneTutorial(bool bHasSeenCreativePhoneTutorial)
{
}

void UFortGameUserSettings::SetHasSeenLobbyModeChangedNotification(bool bHasSeen)
{
}

void UFortGameUserSettings::SetHasSeenPanningTip(bool bHasSeenIt)
{
}

void UFortGameUserSettings::SetHasSeenTapToShoot(bool bHasSeenIt)
{
}

void UFortGameUserSettings::SetInstalledTextureQuality(uint32 Value)
{
}

void UFortGameUserSettings::SetLastSelectedFillOption(bool FillOption)
{
}

void UFortGameUserSettings::SetMeshQuality(int32 Value)
{
}

void UFortGameUserSettings::SetMobileFPSMode(const EFortMobileFPSMode Mode)
{
}

void UFortGameUserSettings::SetNaniteEnabled(bool bEnable)
{
}

void UFortGameUserSettings::SetPredownloadCosmeticsEnabled(bool bValue)
{
}

void UFortGameUserSettings::SetReflectionQualityForGameMode(int32 NewReflectionQuality)
{
}

void UFortGameUserSettings::SetRenderingAPISelection(ERHIType InRenderingAPI)
{
}

void UFortGameUserSettings::SetResolutionFraction(float ResolutionFraction)
{
}

void UFortGameUserSettings::SetSafeZone(float Value)
{
}

void UFortGameUserSettings::SetShowActorsWithSeasonItemTagMapIndicators(const bool bInShowActorsWithSeasonItemTagMapIndicators)
{
}

void UFortGameUserSettings::SetShowCareerTabBang(bool Value)
{
}

void UFortGameUserSettings::SetShowTemperature(bool bNewValue)
{
}

void UFortGameUserSettings::SetStopRenderingInBackground(bool bStop)
{
}

void UFortGameUserSettings::SetTemporalSuperResolutionQuality(int32 InTSRQuality)
{
}

void UFortGameUserSettings::SetUseGPUCrashDebugging(bool bEnabled)
{
}

void UFortGameUserSettings::SetUseLatencyFlash(bool bEnabled)
{
}

void UFortGameUserSettings::SetUseLatencyTweak1(bool bEnabled)
{
}

void UFortGameUserSettings::SetUseLatencyTweak2(int32 InLatencyTweak2)
{
}

void UFortGameUserSettings::SetUserInterfaceContrast(float InContrast)
{
}

void UFortGameUserSettings::SetViewDistanceAndFoliageQuality(int32 NewViewDistanceAndFoliageQuality)
{
}

void UFortGameUserSettings::ToggleScalabilityMode(EFortScalabilityMode Mode, bool bEnabled, bool bForceApply, bool bApplyImmediately)
{
}
