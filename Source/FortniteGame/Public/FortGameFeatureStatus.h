// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortErrorSeverity.h"
#include "FortGameFeatureEnum.h"
#include "FortGameFeatureStatus.generated.h"

UENUM(BlueprintType)
enum class EFortGameFeatureState : uint8
{
	// Unknown what state this is in

	Unknown = 0,
	// Explicitly requested to uninstall data and that had an error during uninstall

	UninstallFailled = 1,
	// Explicitly requested to uninstall data and that has finished

	Uninstalled = 2,
	// Explicitly have requested to uninstall data and it is not yet finished uninstalling

	Uninstalling = 3,
	// Explicitly set to unavailable

	Unavailable = 4,
	// Currently downloading, will transition to Unavailable or Available

	Downloading = 5,
	// Currently downloading, but downloading is paused by the user or cellular data usage settings

	DownloadingPaused = 6,
	// Download failed, but may be retried

	DownloadFailed = 7,
	// This is available on disk but we haven't decided if we want to load it

	Available = 8,
	// Transitioning from available into Preloaded, may be doing some async loading

	Preloading = 9,
	// Failure transitioning from Available to PreLoaded. Async loading or Mounting data might have failed.

	PreloadingFailed = 10,
	// All preparatory work done and ready to actively load, main thread will be ticking normally

	Preloaded = 11,
	// Actively loading into memory, main thread may be blocked

	Loading = 12,
	// Loaded into memory and ready to be active

	Loaded = 13,
	Count = 13,
};

USTRUCT()
struct FCombinedFeatureProgressSummary
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortGameFeature GameFeature;

	UPROPERTY()
	FString PrimaryTextKey;

	UPROPERTY()
	FString LocalizedPrimaryText;

	UPROPERTY()
	float CombinedProgress;

	UPROPERTY()
	bool bIsPaused;

	UPROPERTY()
	bool bCanBePaused;

	UPROPERTY()
	bool bIsFinished;

};

USTRUCT(BlueprintType)
struct FFortGameFeatureStatusBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureStatusBase")
	EFortGameFeature Feature;

	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureStatusBase")
	EFortGameFeatureState CurrentState;

	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureStatusBase")
	EFortGameFeatureState RequestedState;

	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureStatusBase")
	FString ErrorCode;

	UPROPERTY()
	FText ErrorText;

	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureStatusBase")
	bool bIsUsingBackgroundDownloads;

	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureStatusBase")
	bool bIsProgressPaused;

	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureStatusBase")
	FString PauseReason;

	UPROPERTY()
	float Progress;

	UPROPERTY()
	int32 BundlesToInstall;

	UPROPERTY()
	bool bEnoughFreeSpace;

	UPROPERTY()
	FCombinedFeatureProgressSummary ProgressSummary;

};

USTRUCT()
struct FFortGameFeatureOptionalInstallStatus : public FFortGameFeatureStatusBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bContentReady;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortGameFeatureResponse
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureResponse")
	FString ErrorCode;

	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureResponse")
	FText ErrorText;

	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureResponse")
	EFortErrorSeverity ErrorSeverity;

};

USTRUCT()
struct FFortGameFeatureSize
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint64 DownloadSize;

	UPROPERTY()
	uint64 InstallSize;

	UPROPERTY()
	uint64 FreeSpace;

};

USTRUCT()
struct FFortGameFeatureSizeDetailed
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint64 DownloadSize;

	UPROPERTY()
	uint64 InstallSize;

	UPROPERTY()
	uint64 InstallOverheadSize;

	UPROPERTY()
	uint64 FreeSpace;

};

USTRUCT(BlueprintType)
struct FFortGameFeatureStatus : public FFortGameFeatureStatusBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureStatus")
	bool IsActive;

	UPROPERTY(BlueprintReadOnly, Category="FortGameFeatureStatus")
	bool IsPendingActive;

};

USTRUCT()
struct FFortGameFeatureStatusList
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FCombinedFeatureProgressSummary ProgressSummary;

	UPROPERTY()
	TArray<FFortGameFeatureStatus> Features;

	UPROPERTY()
	TArray<FFortGameFeatureOptionalInstallStatus> FeatureOptionalInstalls;

	UPROPERTY()
	bool bHasNetworkConnection;

	UPROPERTY()
	bool bIsUsingCellularConnection;

	UPROPERTY()
	bool bAutoLaunchFullGame;

};

