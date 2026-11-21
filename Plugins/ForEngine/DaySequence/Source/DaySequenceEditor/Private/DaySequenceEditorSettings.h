// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "DaySequenceEditorSettings.generated.h"

USTRUCT()
struct FDaySequencePropertyTrackSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="PropertyTrack")
	FString ComponentPath;

	UPROPERTY(EditAnywhere, Config, Category="PropertyTrack")
	FString PropertyPath;

};

USTRUCT()
struct FDaySequenceTrackSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, NoClear, Category="TrackSettings", meta=(MetaClass="/Script/Engine.Actor"))
	FSoftClassPath MatchingActorClass;

	UPROPERTY(EditAnywhere, Config, NoClear, Category="TrackSettings", meta=(MetaClass="/Script/MovieScene.MovieSceneTrack"))
	TArray<FSoftClassPath> DefaultTracks;

	UPROPERTY(EditAnywhere, Config, NoClear, Category="TrackSettings", meta=(MetaClass="/Script/MovieScene.MovieSceneTrack"))
	TArray<FSoftClassPath> ExcludeDefaultTracks;

	UPROPERTY(EditAnywhere, Config, Category="TrackSettings")
	TArray<FDaySequencePropertyTrackSettings> DefaultPropertyTracks;

	UPROPERTY(EditAnywhere, Config, Category="TrackSettings")
	TArray<FDaySequencePropertyTrackSettings> ExcludeDefaultPropertyTracks;

};

UCLASS(Config=EditorPerProjectUserSettings)
class UDaySequenceEditorSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Tracks")
	TArray<FDaySequenceTrackSettings> TrackSettings;

	UPROPERTY(EditAnywhere, Config, Category="Playback")
	bool bAutoBindToPIE;

	UPROPERTY(EditAnywhere, Config, Category="Playback")
	bool bAutoBindToSimulate;

};

