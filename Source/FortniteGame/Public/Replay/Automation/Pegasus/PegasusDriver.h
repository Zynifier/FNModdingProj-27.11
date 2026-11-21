// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UObject/NoExportTypes.h"
#include "Player/FortPlayerControllerSpectating.h"
#include "Replay/Automation/Pegasus/PegasusTimelineEventTypes.h"
#include "Replay/Automation/ReplayVideoManager.h"
#include "Replay/FortReplayTypes.h"
#include "PegasusDriver.generated.h"

class UReplayVideoManager;

UENUM()
enum class EClipMessageSettings : uint8
{
	DontShow = 0,
	ShowString = 1,
	DeduceUnicornAnnotation = 2,
	ShotTitleScreen = 3,
};

USTRUCT()
struct FBackendExportedClipInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PGS_DatabaseId;

	UPROPERTY()
	FString PGS_DatabaseIdPartitionKey;

	UPROPERTY()
	FString PGS_S3Bucket;

	UPROPERTY()
	FString PGS_S3key;

	UPROPERTY()
	float PGS_Duration;

};

USTRUCT()
struct FBackendExportedTimelineEvents
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PGS_DatabaseId;

	UPROPERTY()
	FString PGS_DatabaseIdPartitionKey;

	UPROPERTY()
	TArray<FPegasusTimelineEvent> PGS_TimelineEvents;

};

USTRUCT()
struct FDriverInstanceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PGS_JobsEndpoint;

	UPROPERTY()
	FString PGS_LocalInstanceId;

	UPROPERTY()
	FString PGS_CloudInstanceId;

	UPROPERTY()
	FString PGS_ASGName;

	UPROPERTY()
	FString PGS_InstanceType;

	UPROPERTY()
	FString PGS_CloudOperatingRegion;

};

USTRUCT()
struct FPegasusJobMeta
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PGS_VideoJobId;

	UPROPERTY()
	TArray<FString> PGS_AdditionalTags;

	UPROPERTY()
	FString PGS_RenderJobId;

	UPROPERTY()
	int32 PGS_RenderJobCreationEpoch;

};

USTRUCT()
struct FBackendJobCompletePayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PGS_RenderJobMessageHandle;

	UPROPERTY()
	FString PGS_RenderQueueUrl;

	UPROPERTY()
	FString PGS_AsgName;

	UPROPERTY()
	TArray<FBackendExportedClipInfo> PGS_ExportedVideos;

	UPROPERTY()
	TArray<FBackendExportedTimelineEvents> PGS_ExportedTimelines;

	UPROPERTY()
	FPegasusJobMeta PGS_PayloadMeta;

	UPROPERTY()
	TMap<EVideoManagerStates, float> PGS_VideoManagerStateDurations;

	UPROPERTY()
	FDriverInstanceInfo PGS_InstanceInfo;

};

USTRUCT()
struct FClipInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float StartTimeStamp;

	UPROPERTY()
	float Duration;

	UPROPERTY()
	FUniqueNetIdRepl PlayerId;

	UPROPERTY()
	FString S3KeyName;

	UPROPERTY()
	FString S3Bucket;

	UPROPERTY()
	FString DatabaseId;

	UPROPERTY()
	FString DatabaseParitionKey;

	UPROPERTY()
	ESpectatorCameraType CameraType;

	UPROPERTY()
	EClipMessageSettings MessageSettings;

	UPROPERTY()
	ECameraShotNotificationTypes MessageNotificationType;

	UPROPERTY()
	float MessageDisplayTime;

	UPROPERTY()
	FString MessageString;

	UPROPERTY()
	TMap<EHighlightFeatures, float> FeatureScores;

	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	FSavedSpectatorCameraShot CameraShotPrefab;

};

USTRUCT()
struct FPegasusJob
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ReplayId;

	UPROPERTY()
	bool bExportShotsIndividually;

	UPROPERTY()
	TArray<FClipInfo> ClipsToExport;

	UPROPERTY()
	bool bGenerateTimelineEventData;

	UPROPERTY()
	bool bJobAllowsFailure;

};

USTRUCT()
struct FBackendJobsPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FPegasusJob> JobsToRun;

	UPROPERTY()
	FPegasusJobMeta PayloadMeta;

};

USTRUCT()
struct FBackendAlarmPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PGS_Message;

	UPROPERTY()
	FString PGS_ErrorCode;

	UPROPERTY()
	FBackendJobsPayload PGS_ReceivedJobPayload;

	UPROPERTY()
	FString PGS_RenderQueueUrl;

	UPROPERTY()
	FString PGS_AsgName;

	UPROPERTY()
	FBackendJobCompletePayload PGS_JobProgress;

	UPROPERTY()
	uint32 PGS_SQSRecievedCount;

	UPROPERTY()
	bool PGS_bIsVideoManagerFinished;

	UPROPERTY()
	bool PGS_bIsShuttingDown;

	UPROPERTY()
	int32 PGS_WastedSeconds;

	UPROPERTY()
	FDriverInstanceInfo PGS_InstanceInfo;

};

UCLASS(Config=Game)
class UPegasusDriver : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleVideoManagerFinishedAllJobs();

	UFUNCTION()
	void HandleVideoManagerJobBeganProcessing(const FVideoManagerExtractionJob& ExtractionJob);

	UFUNCTION()
	void HandleVideoManagerJobComplete(const FVideoManagerExtractionJob& ExtractionJob);

	UFUNCTION()
	void HandleVideoManagerJobFailed(const FVideoManagerExtractionJob& ExtractionJob, const FString& FailureReason, const FString& ErrorCode);

	UFUNCTION()
	void HandleVideoManagerJobShotExported(const FVideoManagerExtractionJob& VideoManagerJob, int32 ShotIndex, const FString& VideoPath);

	UFUNCTION()
	void HandleVideoManagerJobShotWatched(const FVideoManagerExtractionJob& VideoManagerJob, const FWatchedReplayShotInfo& WatchedInfo);

	UPROPERTY(Config)
	float PollIntervalSeconds;

	UPROPERTY(Config)
	float BaseHoursUntilClose;

	UPROPERTY()
	TObjectPtr<UReplayVideoManager> VideoManager;

	UPROPERTY(Config)
	bool bShouldDevBuildsShowFPS;

	UPROPERTY(Config)
	float InactivityCheckSecondsInterval;

	UPROPERTY(Config)
	float MaxSecondsBetweenVideoExports;

};

