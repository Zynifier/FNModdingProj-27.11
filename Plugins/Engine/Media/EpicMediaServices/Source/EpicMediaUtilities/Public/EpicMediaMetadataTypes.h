// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "EpicMediaMetadataTypes.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaAudioMetadataDataExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString ShortName;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	int32 SongID;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Title;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Artist;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Album;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Genre;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	int32 Year;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TMap<FString, int32> Difficulty;

};

USTRUCT(BlueprintType)
struct EPICMEDIAUTILITIES_API FEpicMediaAudioMetadataTrackIndicesExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<int32> Indices;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaAudioMetadataExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TMap<FString, FEpicMediaAudioMetadataTrackIndicesExt> Tracks;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<float> Pans;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<float> Volumes;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<uint8> Midi;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FEpicMediaAudioMetadataDataExt MetadataData;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaAudioMetadataTrackExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TMap<FString, FEpicMediaAudioMetadataTrackIndicesExt> TrackData;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaAudioOnlyPeriodDataExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FLinearColor Color;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	bool bColorSet;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	double StartFrame;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	double EndFrame;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaExtraMetadataExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString AssetId;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<FString> BaseURLs;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString BaseURL;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	int64 Version;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	int64 ExpiresAt;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	bool bSupportsCaching;

};

// Blueprint versions

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaImageDataExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Url;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString FullUrl;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	int32 Width;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	int32 Height;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	float AspectRatio;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaVolumeChangeDataExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	double Frame;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	double Level;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	double Lerp;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaPlaylistExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Language;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Type;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Url;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString RelUrl;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Data;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	double Duration;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	double FPS;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<FEpicMediaImageDataExt> Images;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<FEpicMediaAudioOnlyPeriodDataExt> AudioOnlyPeriods;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<FEpicMediaVolumeChangeDataExt> VolumeChanges;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	double SkipBoundaryTime;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	double PreEndEventTime;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaRegionLockExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	bool AllowOnError;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Type;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<FString> AllowList;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<FString> DenyList;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TMap<FString, FString> Limits;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString ContentId;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct EPICMEDIAUTILITIES_API FEpicMediaMetadataExt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<FEpicMediaPlaylistExt> Playlists;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<FEpicMediaPlaylistExt> StateStreamPlaylists;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	TArray<FEpicMediaPlaylistExt> SelectedPlaylists;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Type;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Envelope;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Limits;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString Subtitles;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString UserContentProtection;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	bool Sharelock;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	bool AudioOnly;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	float AspectRatio;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	bool PartySync;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	bool Live;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FString DenyHTTPCode;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FEpicMediaRegionLockExt RegionLockData;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FEpicMediaAudioMetadataExt AudioMetadata;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	bool bQuicksilverEP;

	UPROPERTY(BlueprintReadOnly, Category="MediaTypes")
	FEpicMediaExtraMetadataExt ExtraMetadata;

};

