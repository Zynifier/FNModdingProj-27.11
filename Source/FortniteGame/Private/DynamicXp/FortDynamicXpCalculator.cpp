// Copyright Epic Games, Inc. All Rights Reserved.

#include "DynamicXp/FortDynamicXpCalculator.h"

void UFortDynamicXpCalculator::AddAccolade(const FString& AccoladeId, const FDynamicXpCreatorAccoladeTuning& Tuning)
{
}

float UFortDynamicXpCalculator::CalculatePotentialXp(FDynamicXpPlayerSession& PlayerSession, const FString& AccoladeId, const float CurrentTime, const bool bIsFromTrigger)
{
	return float();
}

void UFortDynamicXpCalculator::GetAccoladeNameAndGrouping(FString& AccoladeName, FString& Grouping, const FString& FromId)
{
}

float UFortDynamicXpCalculator::GetDailyExcessXpThreshold() const
{
	return float();
}

float UFortDynamicXpCalculator::GetDailyXpCutoffThreshold() const
{
	return float();
}

float UFortDynamicXpCalculator::GetTimespanOutlierThreshold() const
{
	return float();
}

const FDynamicXpProfileStats& UFortDynamicXpCalculator::GetXpProfileStats(const FDynamicXpPlayerSession& PlayerSession)
{
	static FDynamicXpProfileStats Dummy;
	return Dummy;
}

const FDynamicXpAggregatedStats& UFortDynamicXpCalculator::GetXpStats() const
{
	static FDynamicXpAggregatedStats Dummy;
	return Dummy;
}

float UFortDynamicXpCalculator::GetXpVarianceMult() const
{
	return float();
}

void UFortDynamicXpCalculator::InitializeConstantData(const float XpBudgetPerMin, const float CappedSessionLenMinutes, const FDynamicXpCircuitBreaker& CircuitBreakerValues, const FDynamicXpAfkPenalty& Afk)
{
}

void UFortDynamicXpCalculator::InitializePlayerSession(FDynamicXpPlayerSession& PlayerSession, const float SessionStartTime) const
{
}

void UFortDynamicXpCalculator::InitializeXpStats(const FDynamicXpAggregatedStats& AggregatedStats, const int32 CurrentGameVersion)
{
}

bool UFortDynamicXpCalculator::IsCalculatingPotentialXp(EDynamicXpCalibrationPhase CalibrationPhase) const
{
	return false;
}

bool UFortDynamicXpCalculator::IsGrantingRealXp() const
{
	return false;
}

bool UFortDynamicXpCalculator::IsLive(EDynamicXpCalibrationPhase CalibrationPhase) const
{
	return false;
}

#if WITH_EDITOR
bool UFortDynamicXpCalculator::JsonStrToStats(FDynamicXpAggregatedStats& Stats, TArray<FAccoladePublishData>& PublishData, const FString& JsonStr)
{
	return false;
}
#endif

FString UFortDynamicXpCalculator::MakeAccoladeId(const FString& AccoladeName, const FString& AccoladeGrouping)
{
	return FString();
}

void UFortDynamicXpCalculator::OnRoundEndForPlayer(FDynamicXpPlayerSession& PlayerSession, const bool bIsGameEnd, const float CurrentTime)
{
}

void UFortDynamicXpCalculator::OnRoundStartForPlayer(FDynamicXpPlayerSession& PlayerSession, const bool bIsGameStart, const float CurrentTime)
{
}

int32 UFortDynamicXpCalculator::OnTriggerCalculateXp(FDynamicXpPlayerSession& PlayerSession, const FString& AccoladeId, const float CurrentTime, const int32 CurrentDay)
{
	return int32();
}

void UFortDynamicXpCalculator::RemoveAccolade(const FString& AccoladeId)
{
}

#if WITH_EDITOR
void UFortDynamicXpCalculator::SetXpProfileStats(FDynamicXpPlayerSession& PlayerSession, const FDynamicXpProfileStats& Stats)
{
}
#endif
