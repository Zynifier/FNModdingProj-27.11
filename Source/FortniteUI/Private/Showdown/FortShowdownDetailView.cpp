// Copyright Epic Games, Inc. All Rights Reserved.

#include "Showdown/FortShowdownDetailView.h"

bool UFortShowdownDetailView::CanGroupTournamentEventsByVisualRoundNumber() const
{
	return false;
}

bool UFortShowdownDetailView::CanUseAlternativeScore() const
{
	return false;
}

FLinearColor UFortShowdownDetailView::ConvertCMSStringToColor(const FString& ColorString)
{
	return FLinearColor();
}

bool UFortShowdownDetailView::DoCalloutMFARequirement() const
{
	return false;
}

bool UFortShowdownDetailView::DoDisplayRoundNumber(bool bGroupByRoundNumber) const
{
	return false;
}

FFortShowdownEventBestResultsSummary UFortShowdownDetailView::GetAlternativeResultsSummary()
{
	return FFortShowdownEventBestResultsSummary();
}

int32 UFortShowdownDetailView::GetBestEventScore() const
{
	return int32();
}

int32 UFortShowdownDetailView::GetCurrentEventAlternativeScore() const
{
	return int32();
}

int32 UFortShowdownDetailView::GetCurrentEventScore() const
{
	return int32();
}

int32 UFortShowdownDetailView::GetCurrentEventTeamNumMatchesPlayed() const
{
	return int32();
}

FText UFortShowdownDetailView::GetCurrentRegionName() const
{
	return FText();
}

FDateTime UFortShowdownDetailView::GetEventBeginTime() const
{
	return FDateTime();
}

FText UFortShowdownDetailView::GetEventDateAsText(FDateTime DateTime, EFortDateTimeStyle Style) const
{
	return FText();
}

FDateTime UFortShowdownDetailView::GetEventEndTime() const
{
	return FDateTime();
}

FString UFortShowdownDetailView::GetEventId() const
{
	return FString();
}

FString UFortShowdownDetailView::GetEventIdForEligibilityToken(const FString& Token) const
{
	return FString();
}

float UFortShowdownDetailView::GetEventLeaderboardPercentile() const
{
	return float();
}

int32 UFortShowdownDetailView::GetEventLeaderboardRank() const
{
	return int32();
}

EFortShowdownPinState UFortShowdownDetailView::GetEventPinState() const
{
	return EFortShowdownPinState();
}

EFortShowdownEventState UFortShowdownDetailView::GetEventPlayerParticipationState() const
{
	return EFortShowdownEventState();
}

FFortShowdownEventBestResultsSummary UFortShowdownDetailView::GetEventResultsSummary()
{
	return FFortShowdownEventBestResultsSummary();
}

FText UFortShowdownDetailView::GetEventTimeAsText(FDateTime DateTime, EFortDateTimeStyle Style) const
{
	return FText();
}

FTimespan UFortShowdownDetailView::GetEventTimeLeft() const
{
	return FTimespan();
}

FText UFortShowdownDetailView::GetEventTimespanAsText(FTimespan InTimeRemaining, bool bShowSeconds, ETimespanAsTextFormat FormatType) const
{
	return FText();
}

EFortShowdownEventState UFortShowdownDetailView::GetEventTimeState() const
{
	return EFortShowdownEventState();
}

EFortEventWindowEligibility UFortShowdownDetailView::GetEventWindowEligibility() const
{
	return EFortEventWindowEligibility();
}

int32 UFortShowdownDetailView::GetEventWindowSessionNumber() const
{
	return int32();
}

int32 UFortShowdownDetailView::GetEventWindowVisualRoundNumber() const
{
	return int32();
}

int32 UFortShowdownDetailView::GetNumEventVisualRounds() const
{
	return int32();
}

void UFortShowdownDetailView::GetSeriesPointLeaderboardIds(FString& OutEventId, FString& OutEventWindowId) const
{
}

FDateTime UFortShowdownDetailView::GetTournamentBeginTime() const
{
	return FDateTime();
}

EFortShowdownPinState UFortShowdownDetailView::GetTournamentBestPinState() const
{
	return EFortShowdownPinState();
}

int32 UFortShowdownDetailView::GetTournamentBestScore() const
{
	return int32();
}

EFortEventWindowEligibility UFortShowdownDetailView::GetTournamentEligibility() const
{
	return EFortEventWindowEligibility();
}

FDateTime UFortShowdownDetailView::GetTournamentEndTime() const
{
	return FDateTime();
}

TArray<FString> UFortShowdownDetailView::GetTournamentEvents(bool bGroupByRoundNumber)
{
	return TArray<FString>();
}

FString UFortShowdownDetailView::GetTournamentId() const
{
	return FString();
}

int32 UFortShowdownDetailView::GetTournamentMatchCap() const
{
	return int32();
}

EFortShowdownMatchType UFortShowdownDetailView::GetTournamentMatchType() const
{
	return EFortShowdownMatchType();
}

FString UFortShowdownDetailView::GetTournamentNextEvent() const
{
	return FString();
}

int32 UFortShowdownDetailView::GetTournamentPinUnlockScore() const
{
	return int32();
}

TArray<FFortShowdownScoringRuleInfo> UFortShowdownDetailView::GetTournamentScoringRules()
{
	return TArray<FFortShowdownScoringRuleInfo>();
}

FString UFortShowdownDetailView::GetTournamentSeriesId() const
{
	return FString();
}

FTimespan UFortShowdownDetailView::GetTournamentTimeLeft() const
{
	return FTimespan();
}

EFortShowdownEventState UFortShowdownDetailView::GetTournamentTimeState() const
{
	return EFortShowdownEventState();
}

FText UFortShowdownDetailView::GetWindowRoundAndSessionDisplayString() const
{
	return FText();
}

FText UFortShowdownDetailView::GetWindowRoundDisplayString() const
{
	return FText();
}

FText UFortShowdownDetailView::GetWindowSessionDisplayString() const
{
	return FText();
}

bool UFortShowdownDetailView::HasRemainingVisualRounds() const
{
	return false;
}

bool UFortShowdownDetailView::HasScoreInEvent() const
{
	return false;
}

bool UFortShowdownDetailView::IsEventLeaderboardAvailable() const
{
	return false;
}

bool UFortShowdownDetailView::IsFirstDisplayedWindow(bool bGroupByVisualRoundNumber) const
{
	return false;
}

bool UFortShowdownDetailView::IsFloatingLeaderboardAvailable() const
{
	return false;
}

bool UFortShowdownDetailView::IsPreviousDisplayedWindowFromDifferentVisualRound(bool bGroupByVisualRoundNumber) const
{
	return false;
}

bool UFortShowdownDetailView::IsSeriesPointLeaderboardAvailable() const
{
	return false;
}

bool UFortShowdownDetailView::IsWorldCupQualifierEvent() const
{
	return false;
}

void UFortShowdownDetailView::SetTournament(const FString& TournamentId, const FString& EventId, const bool bForceRefreshUI)
{
}

bool UFortShowdownDetailView::ShouldShowCrossplayError() const
{
	return false;
}
