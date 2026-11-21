// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "Misc/Guid.h"
#include "FortDynamicXpCalculatorData.generated.h"

class UFortControllerComponent_EndMatchPersistence;

UENUM(BlueprintType)
enum class EDynamicXpCalibrationPhase : uint8
{
	None = 0,
	DataGathering = 1,
	DataAnalysis = 2,
	LiveXpOnceApproved = 3,
	LiveXp = 4,
	Failed = 5,
};

UENUM()
enum class EDynamicXpReportingStatus : uint8
{
	NotSet = 0,
	Creative = 1,
	VkPlayXps = 2,
	VkPlayDisabled = 3,
	VkPlayXpsNotAvail = 4,
	VkPlayXpsNoData = 5,
	VkPlayXpsPlayerNotCached = 6,
	VkPlayXpsUpdateFailed = 7,
};

USTRUCT(BlueprintType)
struct FAccoladePublishData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AccoladePublishData")
	FString ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AccoladePublishData")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AccoladePublishData")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AccoladePublishData")
	FGameplayTag Weight;

};

USTRUCT()
struct FAccoladeTriggerPerMinute
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	TMap<FString, double> Tpm;

};

USTRUCT(BlueprintType)
struct FDynamicXpAfkPenalty
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Penalties")
	float AfkThresholdSecs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Penalties")
	float AfkMinRewardMult;

};

USTRUCT(BlueprintType)
struct FDynamicXpAggregatedAccoladeStats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpAggregatedAccoladeStats")
	FString AccoladeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpAggregatedAccoladeStats")
	double TriggersPerMinute;

};

USTRUCT(BlueprintType)
struct FDynamicXpCalibrationResult
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpCalibrationResult")
	EDynamicXpCalibrationPhase Result;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpCalibrationResult")
	FString Ids;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpCalibrationResult")
	FDateTime ResultExpiresAt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpCalibrationResult")
	float XpVarianceMult;

};

USTRUCT(BlueprintType)
struct FDynamicXpAggregatedStats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpAggregatedStats")
	FString UniqueGameId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpAggregatedStats")
	int32 UniqueGameVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpAggregatedStats")
	FDynamicXpCalibrationResult CalibrationResult;

	UPROPERTY()
	TArray<FAccoladeTriggerPerMinute> LilAccoladeTPM;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpAggregatedStats")
	TArray<FDynamicXpAggregatedAccoladeStats> Accolades;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpAggregatedStats")
	double MeanSessionLengthMinutes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpAggregatedStats")
	TArray<FAccoladePublishData> PublishData;

};

USTRUCT(BlueprintType)
struct FDynamicXpCircuitBreaker
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Outliers")
	float TimespanOutlierMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Outliers")
	int32 TimespanOutlierDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Remedies")
	float BankXpRemovalMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Remedies")
	float BankXpRemovalTimeIntervalSecs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Remedies")
	float ExcessXpThresholdMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Remedies")
	float XpCutoffThresholdMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Remedies")
	float XpCutoffRewardMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Remedies")
	float FrequencyThresholdMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Booster")
	float MinXpThresholdMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Booster")
	float MaxXpBoosterMult;

};

USTRUCT(BlueprintType)
struct FDynamicXpCreatorAccoladeTuning
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tuning")
	float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tuning")
	float MaxWeightPercentage;

};

USTRUCT(BlueprintType)
struct FDynamicXpQueuedAccolade
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpQueuedAccolade")
	FGuid DeviceGuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpQueuedAccolade")
	FString TeamClassGrouping;

};

USTRUCT(BlueprintType)
struct FDynamicXpPlayerSessionTransient
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	TArray<FDynamicXpQueuedAccolade> QueuedAccolade;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	FGuid LastVoteGuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	int32 TotalXpGained;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	int32 TotalXpPotential;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	float SessionStartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	float LastTimeUpdate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	float BankXpReductionTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	bool bInMiddleOfRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	bool bHitXpThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	bool bPrevHitXpThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	bool bHitExcessXpCutoff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	bool bPrevHitExcessXpCutoff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	int32 TimeSpanOutliers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	int32 LastPotentialXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	float LastBoostedXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	bool bReportedTimeSpanOutlier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	float AfkTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	float PrevAfkTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	float TotalAfkTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	float AfkRewardMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	int32 NumTimesAfk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	int32 NumTimesAfkMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	int32 NumTimesBoosted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpPlayerSessionTransient")
	bool bWasAfk;

};

USTRUCT(BlueprintType)
struct FDynamicXpPlayerSession : public FDynamicXpPlayerSessionTransient
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_EndMatchPersistence> EndMatchPersistence;

};

USTRUCT(BlueprintType)
struct FDynamicXpProfileStats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpProfileStats")
	float Timespan;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpProfileStats")
	int32 BucketXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpProfileStats")
	int32 BankXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpProfileStats")
	float BankXpMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpProfileStats")
	int32 BoosterBucketXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpProfileStats")
	float BoosterXpMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpProfileStats")
	float DailyExcessXpMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpProfileStats")
	int32 CurrentDayXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpProfileStats")
	int32 CurrentDay;

};

USTRUCT(BlueprintType)
struct FDynamicXpReportPlayerLeaving
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FDynamicXpSessionAccoladeStats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpSessionAccoladeStats")
	FString AccoladeId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpSessionAccoladeStats")
	FString AccoladeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpSessionAccoladeStats")
	FString Grouping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpSessionAccoladeStats")
	int32 Triggers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpSessionAccoladeStats")
	int32 GrantedXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicXpSessionAccoladeStats")
	int32 PotentialXp;

};

USTRUCT(BlueprintType)
struct FPublicDynamicXpStats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PublicDynamicXpStats")
	int32 UniqueGameVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PublicDynamicXpStats")
	EDynamicXpCalibrationPhase CalibrationPhase;

};

