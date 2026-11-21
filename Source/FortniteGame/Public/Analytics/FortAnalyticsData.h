// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortAnalyticsData.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAnalyticsData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Phoebe Send Percentage")
	FScalableFloat PlaylistAnalyticPercentBotWriteAllEvents;

	UPROPERTY(EditDefaultsOnly, Category="Phoebe Send Percentage")
	FScalableFloat PlaylistAnalyticPercentBotEndPhase;

	UPROPERTY(EditDefaultsOnly, Category="Player Send Percentage")
	FScalableFloat PlaylistAnalyticPercentPCEndPhase;

	UPROPERTY(EditDefaultsOnly, Category="Phoebe Send Percentage")
	FScalableFloat PlaylistAnalyticPercentBotSlide;

	UPROPERTY(EditDefaultsOnly, Category="Player Send Percentage")
	FScalableFloat PlaylistAnalyticPercentPCSlide;

	UPROPERTY(EditDefaultsOnly, Category="Phoebe Send Percentage")
	FScalableFloat PlaylistAnalyticPercentBotMatchStats;

	UPROPERTY(EditDefaultsOnly, Category="Phoebe Send Percentage")
	FScalableFloat PlaylistAnalyticPercentBotsWonMatch;

	UPROPERTY(EditDefaultsOnly, Category="Phoebe Send Percentage")
	FScalableFloat PlaylistAnalyticPercentBotStartMatch;

	UPROPERTY(EditDefaultsOnly, Category="Phoebe Send Percentage")
	FScalableFloat PlaylistAnalyticPercentBotStartZone;

	UPROPERTY(EditDefaultsOnly, Category="Phoebe Send Percentage")
	FScalableFloat PlaylistAnalyticPercentBotDeath;

	UPROPERTY(EditDefaultsOnly, Category="Player Send Percentage")
	FScalableFloat PlaylistAnalyticPercentPCDeath;

	UPROPERTY(EditDefaultsOnly, Category="Player Send Percentage")
	FScalableFloat PlaylistAnalyticPercentPlayerInterrogated;

	UPROPERTY(Transient)
	FScalableFloat PlaylistAnalyticPercentZero;

	UPROPERTY(Transient)
	FScalableFloat PlaylistAnalyticPercentOneHundred;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortAnalyticsData")
	FGameplayTagContainer DownedOrFinishTagWhitelist;

	UPROPERTY(EditDefaultsOnly, Category="FortAnalyticsData")
	TArray<FGameplayTag> WhiteListTags;

	UPROPERTY(EditDefaultsOnly, Category="FortAnalyticsData")
	FGameplayTag BanhammerTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAnalyticsData")
	FGameplayTag RemovedFromGameTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAnalyticsData")
	FGameplayTag LoggedOutTag;

};

