// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NVIDIAGfeSDKTypes.generated.h"

UENUM(BlueprintType)
enum class EGfeSDKHighlightSignificance : uint8
{
	NONE = 0 UMETA(Hidden),
	ExtremelyBad = 1,
	VeryBad = 2,
	Bad = 4,
	Neutral = 8,
	Good = 16,
	VeryGood = 32,
	ExtremelyGood = 64,
	MAX = 128,
};

UENUM(BlueprintType)
enum class EGfeSDKHighlightType : uint8
{
	NONE = 0 UMETA(Hidden),
	Milestone = 1,
	Achievement = 2,
	Incident = 4,
	StateChange = 8,
	MAX = 16,
};

UENUM(BlueprintType)
enum class EGfeSDKPermission : uint8
{
	Granted = 0,
	Denied = 1,
	MustAsk = 2,
	Unknown = 3,
	MAX = 4,
};

UENUM(BlueprintType)
enum class EGfeSDKReturnCode : uint8
{
	Success = 0,
	SuccessIpcOldSdk = 1,
	SuccessIpcOldGfe = 2,
	Error = 3,
	ErrorGfeVersion = 4,
	ErrorSdkVersion = 5,
	ErrorModuleNotLoaded = 6,
};

UENUM(BlueprintType)
enum class EGfeSDKScope : uint8
{
	Highlights = 0,
	HighlightsRecordVideo = 1,
	HighlightsRecordScreenshot = 2,
	MAX = 3,
};

USTRUCT()
struct FGfeSDKCreateInputParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString AppName;

	UPROPERTY()
	TArray<EGfeSDKScope> RequiredScopes;

	UPROPERTY()
	bool PollForCallbacks;

};

USTRUCT()
struct FGfeSDKCreateResponse
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint16 VersionMajor;

	UPROPERTY()
	uint16 VersionMinor;

	UPROPERTY()
	FString NVIDIAGfeVersion;

	UPROPERTY()
	TMap<EGfeSDKScope, EGfeSDKPermission> ScopePermissions;

};

USTRUCT()
struct FGfeSDKHighlightCloseGroupParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GroupId;

	UPROPERTY()
	bool DestroyHighlights;

};

USTRUCT()
struct FGfeSDKHighlightDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	bool UserDefaultInterest;

	UPROPERTY()
	EGfeSDKHighlightType HighlightTags;

	UPROPERTY()
	EGfeSDKHighlightSignificance Significance;

	UPROPERTY()
	TMap<FString, FString> NameTranslationTable;

};

USTRUCT()
struct FGfeSDKHighlightConfigParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FGfeSDKHighlightDefinition> HighlightDefinitions;

	UPROPERTY()
	FString DefaultLocale;

};

USTRUCT()
struct FGfeSDKHighlightGroupView
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GroupId;

	UPROPERTY()
	EGfeSDKHighlightType TagsFilter;

	UPROPERTY()
	EGfeSDKHighlightSignificance SignificanceFilter;

};

USTRUCT()
struct FGfeSDKHighlightOpenGroupParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GroupId;

	UPROPERTY()
	TMap<FString, FString> GroupDescriptionTranslationTable;

};

USTRUCT()
struct FGfeSDKHighlightScreenshotParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GroupId;

	UPROPERTY()
	FString HighlightId;

};

USTRUCT()
struct FGfeSDKHighlightSummaryParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FGfeSDKHighlightGroupView> GroupViews;

};

USTRUCT()
struct FGfeSDKHighlightVideoParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GroupId;

	UPROPERTY()
	FString HighlightId;

	UPROPERTY()
	int32 StartDelta;

	UPROPERTY()
	int32 EndDelta;

};

USTRUCT()
struct FGfeSDKPermissionsChangedData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<EGfeSDKScope, EGfeSDKPermission> ScopePermissions;

};

USTRUCT()
struct FGfeSDKRequestPermissionsParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<EGfeSDKScope> Scopes;

};

