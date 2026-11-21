// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortLeaderboardEntryDetails.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortLeaderboardEntryDetails : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	const FText GetAlternativeLeaderboardTrackedStatLabel(const FString& TrackedStatName) const;

	UFUNCTION(BlueprintPure)
	const TArray<FString> GetAlternativeLeaderboardTrackedStats(const FString& TournamentId, const FString& EventWindowId, const FString& LeaderboardGroupingKey, const FString& LeaderboardInstanceId) const;

	UFUNCTION(BlueprintCallable)
	void WatchLiveMatch(const FString& SessionId);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLeaderboardEntryDetails")
	bool bAllowProfileNavigation;

};

