// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/EndGame/AthenaPostMatchPanel.h"
#include "Context/AthenaHUDContext.h"
#include "FrontEnd/Habanero/FortHabaneroDisplayData.h"
#include "AthenaPostMatchPanel_RankedRecap.generated.h"

class UEndOfMatchQuestUpdateWidget;
class UFortHabaneroDisplayData;
enum class EHabaneroProgressError : uint8;

UENUM(BlueprintType)
enum class EHabaneroProgressError : uint8
{
	None = 0,
	//Habanero component issues

	MissingHabaneroComponent = 1,
	HabaneroComponentSocialUserNotBound = 2,
	HabaneroComponentUnableToQueryProgress = 3,
	//progress processing issues

	EmptyRankType = 4,
	InitialProgressMapInvalid = 5,
	CurrentProgressMapInvalid = 6,
	InvalidCurrentTrack = 7,
	InitialProgressEntryNotFound = 8,
	CurrentProgressEntryNotFound = 9,
	GameModeNotFound = 10,
	CurrentTierLessThanZero = 11,
	NotEnoughTiersForInitialTier = 12,
	NotEnoughTiersForCurrentTier = 13,
	FailedToFindUnrankedTier = 14,
	UnknownError = 15,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaPostMatchPanel_RankedRecap : public UAthenaPostMatchPanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	float GetFailsafeDelayDuration() const;

	UFUNCTION(BlueprintCallable)
	bool GetUnrankedTierData(FFortHabaneroTier& OutUnrankedTierData);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void PlayQuestsIntro() const;

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateEliminationTimeline(const TArray<FEliminationTimelineEntry>& EliminationTimeline, float MatchTime);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHabaneroErrorCode(const EHabaneroProgressError ProgressError, const FString& OptionalText);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTierDisplay(const TArray<FFortHabaneroTier>& TierList, const int32 InitialTierIndex, const float InitialProgress, const int32 InitialPlayerPosition, const int32 CurrentTierIndex, const float CurrentProgress, const int32 CurrentPlayerPosition, const bool bIsStale);

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEndOfMatchQuestUpdateWidget> Widget_QuestRecap;

private:
	UFUNCTION()
	void QueryProgress();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPostMatchPanel_RankedRecap", meta=(AllowPrivateAccess))
	TObjectPtr<UFortHabaneroDisplayData> HabaneroDisplayData;

};

