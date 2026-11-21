// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "CommonActivatablePanelLegacy.h"
#include "AthenaProfileStatsRecentMatchesBase.generated.h"

class UAthenaMatchStatView;
class UFortMcpProfileAthenaStats;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UAthenaProfileStatsRecentMatchesBase : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AthenaProfileStatsRecentMatchesBase")
	TArray<UAthenaMatchStatView*> GetRecentMatches() const;

	UFUNCTION(BlueprintPure, Category="AthenaProfileStatsRecentMatchesBase")
	FUniqueNetIdRepl GetUniqueID() const;

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaProfileStatsRecentMatchesBase")
	void OnDataRecieved();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaProfileStatsRecentMatchesBase")
	void OnNoData();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaProfileStatsRecentMatchesBase")
	void OnRecentMatcheChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaProfileStatsRecentMatchesBase")
	void OnStartFetchingData();

	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatsRecentMatchesBase")
	void Setup(const FUniqueNetIdRepl& InUniqueId);

private:
	UFUNCTION()
	void OnProfileLoaded(UFortMcpProfileAthenaStats* ProfileAthenaStats);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaMatchStatView>> RecentMatches;

};

