// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "LevelSequenceEditorSubsystem.h"
#include "Misc/FrameTime.h"
#include "MovieSceneBindingProxy.h"
#include "SequencerUtilities.h"
#include "DaySequenceEditorSubsystem.generated.h"

class AActor;
class UMovieSceneFolder;
class UMovieSceneSection;
class UMovieSceneTrack;

UCLASS()
class DAYSEQUENCEEDITOR_API UDaySequenceEditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	TArray<FMovieSceneBindingProxy> AddActors(const TArray<AActor*>& Actors);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void AddActorsToBinding(const TArray<AActor*>& Actors, const FMovieSceneBindingProxy& ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor", meta=(CPP_Default_Params="()"))
	void BakeTransform(const TArray<FMovieSceneBindingProxy>& ObjectBindings, const FFrameTime& BakeInTime, const FFrameTime& BakeOutTime, const FFrameTime& BakeInterval, const FMovieSceneScriptingParams& Params);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	FMovieSceneBindingProxy ConvertToPossessable(const FMovieSceneBindingProxy& ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	TArray<FMovieSceneBindingProxy> ConvertToSpawnable(const FMovieSceneBindingProxy& ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void CopyBindings(const TArray<FMovieSceneBindingProxy>& Bindings, FString& ExportedText);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void CopyFolders(const TArray<UMovieSceneFolder*>& Folders, FString& ExportedText);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void CopySections(const TArray<UMovieSceneSection*>& Sections, FString& ExportedText);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void CopyTracks(const TArray<UMovieSceneTrack*>& Tracks, FString& ExportedText);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void FixActorReferences();

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	bool PasteBindings(const FString& TextToImport, FMovieScenePasteBindingsParams PasteBindingsParams, TArray<FMovieSceneBindingProxy>& OutObjectBindings);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	bool PasteFolders(const FString& TextToImport, FMovieScenePasteFoldersParams PasteFoldersParams, TArray<UMovieSceneFolder*>& OutFolders);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	bool PasteSections(const FString& TextToImport, FMovieScenePasteSectionsParams PasteSectionsParams, TArray<UMovieSceneSection*>& OutSections);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	bool PasteTracks(const FString& TextToImport, FMovieScenePasteTracksParams PasteTracksParams, TArray<UMovieSceneTrack*>& OutTracks);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void RebindComponent(const TArray<FMovieSceneBindingProxy>& ComponentBindings, const FName& ComponentName);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void RemoveActorsFromBinding(const TArray<AActor*>& Actors, const FMovieSceneBindingProxy& ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void RemoveAllBindings(const FMovieSceneBindingProxy& ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void RemoveInvalidBindings(const FMovieSceneBindingProxy& ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void ReplaceBindingWithActors(const TArray<AActor*>& Actors, const FMovieSceneBindingProxy& ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void SnapSectionsToTimelineUsingSourceTimecode(const TArray<UMovieSceneSection*>& Sections);

	UFUNCTION(BlueprintCallable, Category="Day Sequence Editor")
	void SyncSectionsUsingSourceTimecode(const TArray<UMovieSceneSection*>& Sections);

};

