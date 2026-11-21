// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EpicMediaOptions.generated.h"

USTRUCT(BlueprintType)
struct FEpicMediaOptions
{
	GENERATED_BODY()

public:
	// FrameRate is a runtime option that MUST be set for the correct framerate varient to be chosen

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	int32 FrameRate;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	int32 MaxResolutionForMediaStreaming;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	int32 MaxElectraVerticalResolutionOf60fpsVideos;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	int32 MaxElectraVerticalResolutionOfWindowsSWD;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	bool bElectraLiveUseConservativePresentationOffset;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	bool bElectraUseDedicatedMediaSegmentDownloadThreads;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	double ElectraLivePresentationOffset;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	double ElectraLiveAudioPresentationOffset;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	bool bDisableBlastURLStreamSource;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	bool bIsCN;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> VideoEVMap;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<float> CDNDistribution;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> VODHostNames;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> VODHostNamesCN;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> LiveHostNames;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> LiveHostNamesCN;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> VODHostNamesDev;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> LiveHostNamesDev;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> VODHostNamesHF;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> LiveHostNamesHF;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> VODHostNamesCNHF;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	TArray<FString> LiveHostNamesCNHF;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	bool bUseQuicksilverEntryPoint;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	bool bUseSegmentCaching;

	UPROPERTY(BlueprintReadWrite, Category="MediaOptions")
	bool bForceSegmentCaching;

};

