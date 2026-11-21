// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Items/FortPersistentTypes.h"
#include "Items/FortRewardReport.h"
#include "UI/PlayerReportingInfo.h"
#include "FortLocalPlayer.generated.h"

class UFortClientSettingsRecord;
class UFortContentControlsManager;
class UFortGameUserSettings;
class UFortOnlineAccount;
class UFortPoiTracker;
class UFortSupervisedSettingsManager;

UCLASS(MinimalAPI)
class UFortLocalPlayer : public ULocalPlayer
{
	GENERATED_BODY()

public:
	UFUNCTION()
	UFortClientSettingsRecord* GetClientSettings() const;

	UFUNCTION()
	UFortContentControlsManager* GetContentControlsManager() const;

	UFUNCTION()
	UFortContentControlsManager* GetContentControlsManagerEvenIfUninitialized() const;

	UFUNCTION()
	UFortGameUserSettings* GetLocalSettings() const;

	UFUNCTION()
	UFortSupervisedSettingsManager* GetSupervisedSettingsManager() const;

	UPROPERTY(Transient)
	TObjectPtr<UFortOnlineAccount> FortOnlineAccount;

	UPROPERTY()
	FFortRewardReport CachedRewardReport;

	UPROPERTY()
	TArray<FFortPlayerScoreReport> CachedScoreReports;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortClientSettingsRecord> ClientSettingsRecord;

	UPROPERTY(Transient)
	TObjectPtr<UFortContentControlsManager> ContentControlsManager;

	UPROPERTY(Transient)
	UFortSupervisedSettingsManager* SupervisedSettingsManager;

private:
	UPROPERTY()
	bool bControllerAttached;

	UPROPERTY()
	FUniqueNetIdRepl PlatformUID;

	UPROPERTY()
	FPlayerReportingInfoContainer PlayerReportingInfoContainer;

	UPROPERTY(Transient)
	TObjectPtr<UFortPoiTracker> PoiTracker;

};

