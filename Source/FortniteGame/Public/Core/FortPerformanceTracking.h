// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPerformanceTracking.generated.h"

UENUM()
enum class EFortBadMatchTriggerOperation : uint8
{
	LessThan = 0,
	LessThanOrEqual = 1,
	Equal = 2,
	GreaterThan = 3,
	GreaterThanOrEqual = 4,
};

UENUM()
enum class EFortBadMatchTriggerType : uint8
{
	Unspecified = 0,
	SmallTeam = 1,
	LargeTeam = 2,
	LetoTeam = 3,
};

USTRUCT()
struct FFortBadMatchTrigger
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName Key;

	UPROPERTY(Config)
	EFortBadMatchTriggerOperation Operation;

	UPROPERTY(Config)
	double Value;

	UPROPERTY(Config)
	TArray<FName> Playlists;

	UPROPERTY(Config)
	EFortBadMatchTriggerType Type;

};

UCLASS(Config=Game)
class UFortPerfReport : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TArray<FFortBadMatchTrigger> BadMatchTriggers;

	UPROPERTY(Config)
	TArray<FString> PhasesToInclude;

	UPROPERTY(Config)
	double ReportProbability;

	UPROPERTY(Config)
	bool bEnabled;

	UPROPERTY(Config)
	bool bEnableCsvProfile;

	UPROPERTY(Config)
	bool bUploadAllCsvs;

};

UCLASS()
class UFortPerfReportCampaign : public UFortPerfReport
{
	GENERATED_BODY()

};

