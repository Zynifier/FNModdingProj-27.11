// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameInstance.h"

bool UFortGameInstance::CancelUninstallAllOptionalContentOnNextBoot()
{
	return false;
}

bool UFortGameInstance::CancelUninstallFortniteBROnNextBoot()
{
	return false;
}

void UFortGameInstance::ChangeActiveGameFeature(const FString& FeatureString)
{
}

void UFortGameInstance::CheckLatestClient(FWebJSResponse Response)
{
}

void UFortGameInstance::ClearOverrideCurrentMusicFFT()
{
}

void UFortGameInstance::ContinueDelayedStartup()
{
}

void UFortGameInstance::DebugCreateBackgroundPlayer(int32 ControllerId)
{
}

void UFortGameInstance::DebugCreatePlayerWithLoginInfo(int32 ControllerId, const FString& Email, const FString& Password)
{
}

void UFortGameInstance::GetAnalyticsSessionDetails(FWebJSResponse Response)
{
}

void UFortGameInstance::GetContentState(EFortGameFeature Feature, FWebJSResponse Response)
{
}

UDAD_CreativeUserOptionsCollection* UFortGameInstance::GetDADCreativeUserOptionsCollection() const
{
	return nullptr;
}

UDAD_IslandQuerier* UFortGameInstance::GetDADIslandQuerier() const
{
	return nullptr;
}

UDataAssetDirectoryManager* UFortGameInstance::GetDataAssetDirectoryManager() const
{
	return nullptr;
}

UFortSeasonalEventManager* UFortGameInstance::GetEventManager() const
{
	return nullptr;
}

void UFortGameInstance::GetFeatureRequiredSizes(EFortGameFeature Feature, FWebJSResponse Response)
{
}

void UFortGameInstance::GetFeatureRequiredSizesOptionalOnly(EFortGameFeature Feature, FWebJSResponse Response)
{
}

void UFortGameInstance::GetFeatureRequiredSizesRequiredOnly(EFortGameFeature Feature, FWebJSResponse Response)
{
}

void UFortGameInstance::GetHotfixHasApplied(FWebJSResponse Response)
{
}

UFortIslandLockManager* UFortGameInstance::GetIslandLockManager() const
{
	return nullptr;
}

UFortLinkDataManager* UFortGameInstance::GetLinkDataManager() const
{
	return nullptr;
}

void UFortGameInstance::GetProjectVersion(FWebJSResponse Response)
{
}

UFortRatingDataManager* UFortGameInstance::GetRatingDataManager() const
{
	return nullptr;
}

void UFortGameInstance::GetUserSetting(const FString& Key, FWebJSResponse Response)
{
}

void UFortGameInstance::IsContentUpToDate(EFortGameFeature Feature, FWebJSResponse Response)
{
}

bool UFortGameInstance::IsCurrentlyShowingLoadingScreen() const
{
	return false;
}

void UFortGameInstance::KairosSubmitBugReport(const FString& Subject, const FString& Body, FWebJSResponse Response)
{
}

void UFortGameInstance::OnContentBeaconGameFeatureActive(const FString& ContentURL)
{
}

void UFortGameInstance::OnContentBeaconGameFeatureDeactive(const FString& ContentURL)
{
}

void UFortGameInstance::OnContentMessageAdded(const FString& NewContentMessage)
{
}

void UFortGameInstance::OnContentReadinessChanged(EClientContentReadinessV2 ContentReadiness)
{
}

void UFortGameInstance::OnGameStateSetInternalCallback(AFortGameState* GameState)
{
}

void UFortGameInstance::OnScriptDiagnosticMessage(const FScriptDiagnosticMessage& Message)
{
}

void UFortGameInstance::OnScriptScreenLogMessage(const FScriptScreenLogMessage& Message)
{
}

void UFortGameInstance::OnScriptScreenLogMessageWithLocalization(const FScriptScreenLogMessageWithLocalization& Message)
{
}

void UFortGameInstance::OnTournamentDataRefreshed()
{
}

void UFortGameInstance::OpenUpdateApp()
{
}

void UFortGameInstance::RequestBroadcast()
{
}

void UFortGameInstance::SetErrorSimulationCommands(const FString& CommandLine)
{
}

void UFortGameInstance::SetFeatureStatusCallback(FWebJSFunction Callback)
{
}

void UFortGameInstance::SetHotfixCompleteCallback(FWebJSFunction Callback)
{
}

void UFortGameInstance::SetMultipleUserSettings(const TMap<FString, FString>& Settings, FWebJSResponse Response)
{
}

void UFortGameInstance::SetOverrideCurrentMusicFFT(float FFT100hz, float FFT2000hz)
{
}

void UFortGameInstance::SetUserSetting(const FString& Key, const FString& Value, FWebJSResponse Response)
{
}

bool UFortGameInstance::UninstallAllOptionalContentOnNextBoot(bool bRestartApp, bool bPromptForRestart)
{
	return false;
}

bool UFortGameInstance::UninstallFortniteBROnNextBoot(bool bRestartApp, bool bPromptForRestart)
{
	return false;
}
