// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "Layout/Margin.h"
#include "Math/Color.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "DateTime/FortDateTimeLibrary.h"
#include "Online/FortMatchmakingUtilityDataTypes.h"
#include "Online/FortTournamentManagerTypes.h"
#include "FortShowdownDetailView.generated.h"

class UCommonTextBlock;
class UEpicCMSImage;
class UTextBlock;
enum class EFortDateTimeStyle : uint8;
enum class EFortEventWindowEligibility : uint8;
enum class EFortShowdownEventState : uint8;
enum class EFortShowdownMatchType : uint8;
enum class EFortShowdownPinState : uint8;
enum class ETimespanAsTextFormat : uint8;

UENUM(BlueprintType)
enum class EFortDateTimeStyle : uint8
{
	Default = 0,
	Short = 1,
	Medium = 2,
	Long = 3,
	Full = 4,
};

UENUM(BlueprintType)
enum class EFortEventWindowEligibility : uint8
{
	Unknown = 0,
	Public = 1,
	Private = 2,
	Locked = 3,
};

UENUM(BlueprintType)
enum class EFortShowdownEventState : uint8
{
	Unknown = 0,
	FutureTBD = 1,
	FutureScheduled = 2,
	FutureNext = 3,
	Live = 4,
	LiveParticipating = 5,
	LiveNotParticipating = 6,
	Completed = 7,
	CompletedParticipated = 8,
	CompletedNotPartipated = 9,
	Cancelled = 10,
};

UENUM(BlueprintType)
enum class EFortShowdownMatchType : uint8
{
	Unknown = 0,
	Solo = 1,
	Duos = 2,
	Squads = 3,
};

UENUM(BlueprintType)
enum class EFortShowdownPinState : uint8
{
	None = 0,
	Locked = 1,
	Unlocked = 2,
};

USTRUCT(BlueprintType)
struct FFortEventStyleInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor BaseColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor PrimaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor SecondaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor HighlightColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor TitleColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor ShadowColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor BackgroundLeftColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor BackgroundRightColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor BackgroundTextColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortEventStyleInfo")
	FLinearColor PosterFadeColor;

};

USTRUCT(BlueprintType)
struct FFortShowdownEventBestResultsSummary
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortShowdownEventBestResultsSummary")
	int32 TotalScore;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownEventBestResultsSummary")
	int32 MatchesPlayed;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownEventBestResultsSummary")
	int32 NumVictoryRoyales;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownEventBestResultsSummary")
	int32 PlacementPoints;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownEventBestResultsSummary")
	int32 EliminationPoints;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownEventBestResultsSummary")
	int32 EntryFeePoints;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownEventBestResultsSummary")
	bool bIsValidSummary;

};

USTRUCT(BlueprintType)
struct FFortTournamentDisplayInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText TitleLine1;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText TitleLine2;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText ScheduleInfo;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText FlavorDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText DetailsDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText ShortFormatTitle;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText LongFormatTitle;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText BackgroundTitle;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	int32 PinScoreRequirement;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText PinEarnedText;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor BaseColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor PrimaryColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor SecondaryColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor HighlightColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor TitleColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor ShadowColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor BackgroundLeftColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor BackgroundRightColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor BackgroundTextColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FLinearColor PosterFadeColor;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText AlertText;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	FText SeriesPointLeaderboardName;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	EFortTournamentAlertType AlertType;

	UPROPERTY(BlueprintReadOnly, Category="FortTournamentDisplayInfo")
	TArray<FText> RoundDisplayNames;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortShowdownDetailView : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortShowdownDetailView")
	void SetTournament(const FString& TournamentId, const FString& EventId = TEXT(""), const bool bForceRefreshUI = true);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_ResetDetailView();

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailsView")
	bool CanGroupTournamentEventsByVisualRoundNumber() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool CanUseAlternativeScore() const;

	UFUNCTION(BlueprintCallable, Category="FortShowdownDetailView")
	FLinearColor ConvertCMSStringToColor(const FString& ColorString);

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool DoCalloutMFARequirement() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool DoDisplayRoundNumber(bool bGroupByRoundNumber = false) const;

	UFUNCTION(BlueprintCallable, Category="FortShowdownDetailView")
	FFortShowdownEventBestResultsSummary GetAlternativeResultsSummary();

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetBestEventScore() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetCurrentEventAlternativeScore() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetCurrentEventScore() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetCurrentEventTeamNumMatchesPlayed() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FText GetCurrentRegionName() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FDateTime GetEventBeginTime() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FText GetEventDateAsText(FDateTime DateTime, EFortDateTimeStyle Style) const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FDateTime GetEventEndTime() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FString GetEventId() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FString GetEventIdForEligibilityToken(const FString& Token) const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	float GetEventLeaderboardPercentile() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetEventLeaderboardRank() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	EFortShowdownPinState GetEventPinState() const;

	UFUNCTION(BlueprintPure)
	EFortShowdownEventState GetEventPlayerParticipationState() const;

	UFUNCTION(BlueprintCallable, Category="FortShowdownDetailView")
	FFortShowdownEventBestResultsSummary GetEventResultsSummary();

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FText GetEventTimeAsText(FDateTime DateTime, EFortDateTimeStyle Style) const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FTimespan GetEventTimeLeft() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FText GetEventTimespanAsText(FTimespan InTimeRemaining, bool bShowSeconds, ETimespanAsTextFormat FormatType) const;

	UFUNCTION(BlueprintPure)
	EFortShowdownEventState GetEventTimeState() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	EFortEventWindowEligibility GetEventWindowEligibility() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetEventWindowSessionNumber() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetEventWindowVisualRoundNumber() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetNumEventVisualRounds() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	void GetSeriesPointLeaderboardIds(FString& OutEventId, FString& OutEventWindowId) const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FDateTime GetTournamentBeginTime() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	EFortShowdownPinState GetTournamentBestPinState() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetTournamentBestScore() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	EFortEventWindowEligibility GetTournamentEligibility() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FDateTime GetTournamentEndTime() const;

	UFUNCTION(BlueprintCallable, Category="FortShowdownDetailView")
	TArray<FString> GetTournamentEvents(bool bGroupByRoundNumber = false);

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FString GetTournamentId() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetTournamentMatchCap() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	EFortShowdownMatchType GetTournamentMatchType() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FString GetTournamentNextEvent() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	int32 GetTournamentPinUnlockScore() const;

	UFUNCTION(BlueprintCallable, Category="FortShowdownDetailView")
	TArray<FFortShowdownScoringRuleInfo> GetTournamentScoringRules();

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FString GetTournamentSeriesId() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FTimespan GetTournamentTimeLeft() const;

	UFUNCTION(BlueprintPure)
	EFortShowdownEventState GetTournamentTimeState() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FText GetWindowRoundAndSessionDisplayString() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FText GetWindowRoundDisplayString() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	FText GetWindowSessionDisplayString() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool HasRemainingVisualRounds() const;

	UFUNCTION(BlueprintPure)
	bool HasScoreInEvent() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool IsEventLeaderboardAvailable() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool IsFirstDisplayedWindow(bool bGroupByVisualRoundNumber) const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool IsFloatingLeaderboardAvailable() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool IsPreviousDisplayedWindowFromDifferentVisualRound(bool bGroupByVisualRoundNumber) const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool IsSeriesPointLeaderboardAvailable() const;

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool IsWorldCupQualifierEvent() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortShowdownDetailView", meta=(DisplayName="Refresh Data"))
	void RefreshDataBP();

	UFUNCTION(BlueprintPure, Category="FortShowdownDetailView")
	bool ShouldShowCrossplayError() const;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownDetailView")
	FFortTournamentDisplayInfo TournamentDisplayInfo;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownDetailView")
	FShowdownTournamentEntry CMSTournamentData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownDetailView", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TimeRemaining;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownDetailView", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UTextBlock> Text_DebugId;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortShowdownDetailView", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEpicCMSImage> Image_PosterFront;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortShowdownDetailView", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEpicCMSImage> Image_PosterBack;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortShowdownDetailView", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEpicCMSImage> Image_LoadingScreen;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortShowdownDetailView", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEpicCMSImage> Image_PlaylistTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortShowdownDetailView")
	FText TimeRemainingFormat;

	UPROPERTY(EditAnywhere, Category="FortShowdownDetailView")
	bool bTimeRemainingShowSeconds;

	UPROPERTY(EditAnywhere, Category="FortShowdownDetailView")
	bool bTimeRemainingUppercase;

	UPROPERTY(EditAnywhere, Category="FortShowdownDetailView")
	ETimespanAsTextFormat TimeRemainingFormatType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortShowdownDetailView")
	FMargin TitlePaddingMobile;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortShowdownDetailView")
	bool bRefreshDataOnUpdateEventState;

};

