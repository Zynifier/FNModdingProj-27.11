// Copyright Epic Games, Inc. All Rights Reserved.

#include "DaySequenceEditorSubsystem.h"

TArray<FMovieSceneBindingProxy> UDaySequenceEditorSubsystem::AddActors(const TArray<AActor*>& Actors)
{
	return TArray<FMovieSceneBindingProxy>();
}

void UDaySequenceEditorSubsystem::AddActorsToBinding(const TArray<AActor*>& Actors, const FMovieSceneBindingProxy& ObjectBinding)
{
}

void UDaySequenceEditorSubsystem::BakeTransform(const TArray<FMovieSceneBindingProxy>& ObjectBindings, const FFrameTime& BakeInTime, const FFrameTime& BakeOutTime, const FFrameTime& BakeInterval, const FMovieSceneScriptingParams& Params)
{
}

FMovieSceneBindingProxy UDaySequenceEditorSubsystem::ConvertToPossessable(const FMovieSceneBindingProxy& ObjectBinding)
{
	return FMovieSceneBindingProxy();
}

TArray<FMovieSceneBindingProxy> UDaySequenceEditorSubsystem::ConvertToSpawnable(const FMovieSceneBindingProxy& ObjectBinding)
{
	return TArray<FMovieSceneBindingProxy>();
}

void UDaySequenceEditorSubsystem::CopyBindings(const TArray<FMovieSceneBindingProxy>& Bindings, FString& ExportedText)
{
}

void UDaySequenceEditorSubsystem::CopyFolders(const TArray<UMovieSceneFolder*>& Folders, FString& ExportedText)
{
}

void UDaySequenceEditorSubsystem::CopySections(const TArray<UMovieSceneSection*>& Sections, FString& ExportedText)
{
}

void UDaySequenceEditorSubsystem::CopyTracks(const TArray<UMovieSceneTrack*>& Tracks, FString& ExportedText)
{
}

void UDaySequenceEditorSubsystem::FixActorReferences()
{
}

bool UDaySequenceEditorSubsystem::PasteBindings(const FString& TextToImport, FMovieScenePasteBindingsParams PasteBindingsParams, TArray<FMovieSceneBindingProxy>& OutObjectBindings)
{
	return false;
}

bool UDaySequenceEditorSubsystem::PasteFolders(const FString& TextToImport, FMovieScenePasteFoldersParams PasteFoldersParams, TArray<UMovieSceneFolder*>& OutFolders)
{
	return false;
}

bool UDaySequenceEditorSubsystem::PasteSections(const FString& TextToImport, FMovieScenePasteSectionsParams PasteSectionsParams, TArray<UMovieSceneSection*>& OutSections)
{
	return false;
}

bool UDaySequenceEditorSubsystem::PasteTracks(const FString& TextToImport, FMovieScenePasteTracksParams PasteTracksParams, TArray<UMovieSceneTrack*>& OutTracks)
{
	return false;
}

void UDaySequenceEditorSubsystem::RebindComponent(const TArray<FMovieSceneBindingProxy>& ComponentBindings, const FName& ComponentName)
{
}

void UDaySequenceEditorSubsystem::RemoveActorsFromBinding(const TArray<AActor*>& Actors, const FMovieSceneBindingProxy& ObjectBinding)
{
}

void UDaySequenceEditorSubsystem::RemoveAllBindings(const FMovieSceneBindingProxy& ObjectBinding)
{
}

void UDaySequenceEditorSubsystem::RemoveInvalidBindings(const FMovieSceneBindingProxy& ObjectBinding)
{
}

void UDaySequenceEditorSubsystem::ReplaceBindingWithActors(const TArray<AActor*>& Actors, const FMovieSceneBindingProxy& ObjectBinding)
{
}

void UDaySequenceEditorSubsystem::SnapSectionsToTimelineUsingSourceTimecode(const TArray<UMovieSceneSection*>& Sections)
{
}

void UDaySequenceEditorSubsystem::SyncSectionsUsingSourceTimecode(const TArray<UMovieSceneSection*>& Sections)
{
}
