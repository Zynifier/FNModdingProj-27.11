// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DynamicXp/FortDynamicXpCalculatorData.h"
#include "FortDynamicXpCalculator.generated.h"

class UObject;
enum class EDynamicXpCalibrationPhase : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnExceededPotentialCap, const FDynamicXpSessionAccoladeStats&, Stats, const float, ResultingPotential, const float, TotalXpCap);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnExceededTriggerLimit, const FDynamicXpSessionAccoladeStats&, Stats, const int32, Triggers, const int32, TriggerLimit);

UCLASS(MinimalAPI, BlueprintType)
class UFortDynamicXpCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Initialize")
	void AddAccolade(const FString& AccoladeId, const FDynamicXpCreatorAccoladeTuning& Tuning);

	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator")
	float CalculatePotentialXp(UPARAM(ref) FDynamicXpPlayerSession& PlayerSession, const FString& AccoladeId, const float CurrentTime = 0.000000f, const bool bIsFromTrigger = false);

#if WITH_EDITOR
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="DynamicXp|Calculator|Utility")
	FString DoCommand(UObject* Caller, const FString& Command, const TMap<FString, FString>& Args);
#endif

	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Utility")
	static void GetAccoladeNameAndGrouping(FString& AccoladeName, FString& Grouping, const FString& FromId);

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator|Query")
	float GetDailyExcessXpThreshold() const;

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator|Query")
	float GetDailyXpCutoffThreshold() const;

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator|Query")
	float GetTimespanOutlierThreshold() const;

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator|Query")
	static const FDynamicXpProfileStats& GetXpProfileStats(const FDynamicXpPlayerSession& PlayerSession);

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator|Query")
	const FDynamicXpAggregatedStats& GetXpStats() const;

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator|Query")
	float GetXpVarianceMult() const;

	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Initialize")
	void InitializeConstantData(const float XpBudgetPerMin, const float CappedSessionLenMinutes, const FDynamicXpCircuitBreaker& CircuitBreakerValues, const FDynamicXpAfkPenalty& Afk);

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator|Initialize")
	void InitializePlayerSession(UPARAM(ref) FDynamicXpPlayerSession& PlayerSession, const float SessionStartTime = 0.000000f) const;

	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Initialize")
	void InitializeXpStats(const FDynamicXpAggregatedStats& AggregatedStats, const int32 CurrentGameVersion);

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator|Query")
	bool IsCalculatingPotentialXp(EDynamicXpCalibrationPhase CalibrationPhase = EDynamicXpCalibrationPhase::None) const;

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator")
	bool IsGrantingRealXp() const;

	UFUNCTION(BlueprintPure, Category="DynamicXp|Calculator|Query")
	bool IsLive(EDynamicXpCalibrationPhase CalibrationPhase = EDynamicXpCalibrationPhase::None) const;

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Utility")
	static bool JsonStrToStats(FDynamicXpAggregatedStats& Stats, TArray<FAccoladePublishData>& PublishData, const FString& JsonStr);
#endif

	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Utility")
	static FString MakeAccoladeId(const FString& AccoladeName, const FString& AccoladeGrouping);

	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Initialize")
	void OnRoundEndForPlayer(UPARAM(ref) FDynamicXpPlayerSession& PlayerSession, const bool bIsGameEnd, const float CurrentTime);

	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Initialize")
	void OnRoundStartForPlayer(UPARAM(ref) FDynamicXpPlayerSession& PlayerSession, const bool bIsGameStart, const float CurrentTime);

	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator")
	int32 OnTriggerCalculateXp(UPARAM(ref) FDynamicXpPlayerSession& PlayerSession, const FString& AccoladeId, const float CurrentTime, const int32 CurrentDay);

	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Initialize")
	void RemoveAccolade(const FString& AccoladeId);

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="DynamicXp|Calculator|Utility")
	static void SetXpProfileStats(UPARAM(ref) FDynamicXpPlayerSession& PlayerSession, const FDynamicXpProfileStats& Stats);
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintAssignable)
	FOnExceededTriggerLimit OnExceededTriggerLimit;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintAssignable)
	FOnExceededPotentialCap OnExceededPotentialCap;
#endif

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	FDynamicXpCircuitBreaker CircuitBreaker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	FDynamicXpAfkPenalty AfkPenalty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Analytics")
	FDynamicXpAggregatedStats XpStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Calculations")
	TMap<FString, float> AccoladeGroupingTotalWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Calculations")
	TMap<FString, FDynamicXpCreatorAccoladeTuning> AccoladeTuning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Calculations")
	float XpBudgetPerMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Calculations")
	float CappedSessionLengthMinutes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Calculations")
	bool bHasVarianceReduction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Calculations")
	bool bRecalculateWeights;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Calculations")
	int32 MinXpThreshold;

};

