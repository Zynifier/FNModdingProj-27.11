// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ComponentInstanceDataCache.h"
#include "Components/ActorComponent.h"
#include "FabricModulatable.h"
#include "HarmonixMetasound/DataTypes/MidiStepSequence.h"
#include "HarmonixMidi/Blueprint/MidiNote.h"
#include "LevelSaveSpawnableInterface.h"
#include "FabricStepSequencerComponent.generated.h"

class AActor;
class UFabricStepSequencerModulatable;
class UMidiStepSequence;
class UMusicClockComponent;
enum class EFabricNoteStyle : uint8;

UENUM(BlueprintType)
enum class EFabricNoteStyle : uint8
{
	Straight = 0,
	Triplet = 1,
	Dotted = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBeatOffsetChanged, float, BeatOffset);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBeatScaleChanged, float, BeatScale);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFabricPageChanged, int32, CurrentPage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFullTableChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoopEnded);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNoteStyleChanged, EFabricNoteStyle, NoteStyle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNumFabricStepsChanged, int32, NumSteps);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNumFabricTracksChanged, int32, NumTracks);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPageCleared, int32, PageIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuarterNotesLengthChanged, float, QuarterNotes);

USTRUCT(BlueprintType)
struct FFabricSequencerStepChangedInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricSequencerStepChangedInfo")
	int32 Page;

	UPROPERTY(BlueprintReadWrite, Category="FabricSequencerStepChangedInfo")
	int32 Row;

	UPROPERTY(BlueprintReadWrite, Category="FabricSequencerStepChangedInfo")
	int32 Step;

	UPROPERTY(BlueprintReadWrite, Category="FabricSequencerStepChangedInfo")
	FStepSequenceCell Cell;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStepChanged, const FFabricSequencerStepChangedInfo&, StepInfo);

USTRUCT(BlueprintType)
struct FFabricStepTrackPacked
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, SaveGame, Category="FabricStepTrackPacked")
	TArray<int32> PackedEnabledSquares;

	UPROPERTY(VisibleAnywhere, SaveGame, Category="FabricStepTrackPacked")
	TArray<int32> PackedContinuationSquares;

	UPROPERTY(VisibleAnywhere, SaveGame, Category="FabricStepTrackPacked")
	int32 TrackIndex;

};

USTRUCT(BlueprintType)
struct FFabricStepPagePacked
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, SaveGame, Category="FabricStepPagePacked")
	TArray<FFabricStepTrackPacked> PackedTracks;

	UPROPERTY(VisibleAnywhere, SaveGame, Category="FabricStepPagePacked")
	int32 PageNumber;

};

USTRUCT(BlueprintType)
struct FFabricStepTablePacked
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, SaveGame, Category="FabricStepTablePacked")
	TArray<FFabricStepPagePacked> PackedPages;

	UPROPERTY(VisibleAnywhere, SaveGame, Category="FabricStepTablePacked")
	TArray<FStepSequenceNote> Notes;

	UPROPERTY(VisibleAnywhere, SaveGame, Category="FabricStepTablePacked")
	int32 StepSkipIndex;

};

USTRUCT()
struct FFabricStepSequencerComponentBaseInstanceData : public FActorComponentInstanceData
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FFabricStepTablePacked PackedStepTable;

};

UCLASS(ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent, DisplayName="Fabric Step Sequencer"))
class FABRICRUNTIME_API UFabricStepSequencerComponent : public UActorComponent, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void ApplyPage(int32 PageIndex, const FStepSequencePage& PageData);

	UFUNCTION(BlueprintCallable)
	void ApplyTemplate(const UMidiStepSequence* Template, int32 StepSequencePageIndex);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void ClearCurrentPage();

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void ClearPage(int32 Page);

	UFUNCTION(BlueprintCallable)
	void GetContinuationFocusIndeces(int32& OutRowIndex, int32& OutStepIndex, int32& OutNumContinuationSteps);

	UFUNCTION(BlueprintPure)
	int32 GetCurrentPage() const;

	UFUNCTION(BlueprintPure)
	float GetLengthStepBeats() const;

	UFUNCTION(BlueprintPure)
	float GetLengthStepQuarterNotes() const;

	UFUNCTION(BlueprintPure)
	float GetLengthTrackBeats() const;

	UFUNCTION(BlueprintPure)
	float GetLengthTrackQuarterNotes() const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	float GetLongestContinuationLengthForColumn(int32 Column) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	float GetLongestContinuationLengthForColumnOnPage(int32 Page, int32 Column) const;

	UFUNCTION(BlueprintPure)
	int32 GetMaxSteps() const;

	UFUNCTION(BlueprintPure)
	UMidiStepSequence* GetMidiStepSequence();

	UFUNCTION(BlueprintPure)
	int32 GetNumberSteps() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumberTracks() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumUsedSteps(int32 TotalSteps) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	void GetPageData(int32 PageIndex, FStepSequencePage& OutPageData) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	float GetStepContinuationLength(int32 Row, int32 Column) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	float GetStepContinuationLengthOnPage(int32 Page, int32 Row, int32 Column) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	bool GetStepEnabled(int32 Row, int32 Column) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	bool GetStepEnabledOnPage(int32 Page, int32 Row, int32 Column) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	bool GetStepIsContinuation(int32 Row, int32 Column) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	bool GetStepIsContinuationOnPage(int32 Page, int32 Row, int32 Column) const;

	UFUNCTION(BlueprintPure)
	float GetStepStartBeat(int32 Step) const;

	UFUNCTION(BlueprintPure)
	float GetStepStartQuarterNotes(int32 Step) const;

	UFUNCTION(BlueprintPure)
	bool GetSupportsContinuation() const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	bool IsPageBlank(int32 PageIndex) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	bool IsStepEnabledForAnyTrack(int32 Column) const;

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	bool IsStepEnabledForAnyTrackOnPage(int32 Page, int32 Column) const;

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void RandomizeCurrentPage();

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void RandomizePage(int32 Page);

	UFUNCTION(BlueprintCallable)
	void SetBeatScale(float BeatScale);

	UFUNCTION(BlueprintCallable)
	void SetCurrentPage(int32 NewPage);

	UFUNCTION(BlueprintCallable)
	void SetLoop(bool bNewLoop);

	UFUNCTION(BlueprintCallable)
	void SetMaxSteps(int32 NumSteps);

	UFUNCTION(BlueprintCallable)
	void SetMonophonic(bool bNewMonophonic);

	UFUNCTION(BlueprintCallable)
	void SetMusicClock(UMusicClockComponent* InMusicClock);

	UFUNCTION(BlueprintCallable)
	void SetNoteForTrack(FMidiNote Note, int32 Track);

	UFUNCTION(BlueprintCallable)
	void SetNoteStyle(EFabricNoteStyle Style);

	UFUNCTION(BlueprintCallable)
	void SetNumberPages(int32 NumPages);

	UFUNCTION(BlueprintCallable)
	void SetNumberSteps(int32 NumSteps);

	UFUNCTION(BlueprintCallable)
	void SetNumberTracks(int32 NumTracks);

	UFUNCTION(BlueprintCallable)
	void SetPlaying(bool bNewPlaying);

	UFUNCTION(BlueprintCallable)
	void SetQuarterNotesLength(float QuarterNotes);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void SetStepContinuation(int32 Row, int32 Column, bool bIsContinuation);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void SetStepContinuationOnPage(int32 Page, int32 Row, int32 Column, bool bIsContinuation);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void SetStepEnabled(int32 Row, int32 Column, bool bState);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void SetStepEnabledOnPage(int32 Page, int32 Row, int32 Column, bool bState);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void ToggleStepEnabled(int32 Row, int32 Column);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void ToggleStepEnabledOnPage(int32 Page, int32 Row, int32 Column);

	UPROPERTY(BlueprintAssignable)
	FOnNumFabricTracksChanged OnNumTracksChanged;

	UPROPERTY(BlueprintAssignable)
	FOnNumFabricStepsChanged OnNumStepsChanged;

	UPROPERTY(BlueprintAssignable)
	FOnFabricPageChanged OnPageChanged;

	UPROPERTY(BlueprintAssignable)
	FOnQuarterNotesLengthChanged OnQuarterNotesLengthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnBeatScaleChanged OnBeatScaleChanged;

	UPROPERTY(BlueprintAssignable)
	FOnBeatOffsetChanged OnBeatOffsetChanged;

	UPROPERTY(BlueprintAssignable)
	FOnStepChanged OnStepChanged;

	UPROPERTY(BlueprintAssignable)
	FOnNoteStyleChanged OnNoteStyleChanged;

	UPROPERTY(BlueprintAssignable)
	FOnFullTableChanged OnFullTableChanged;

	UPROPERTY(BlueprintAssignable)
	FOnPageCleared OnPageCleared;

	UPROPERTY(BlueprintAssignable)
	FOnLoopEnded OnLoopEnded;

protected:
	UPROPERTY(EditAnywhere, Category="Step Sequencer Params")
	FString LengthParam;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Params")
	FString DurationParam;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Params")
	FString PageParam;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Params")
	FString AutoPageParam;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Params")
	FString OctaveParam;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Params")
	FString NoteStyleParam;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Params")
	FString LoopParam;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Settings")
	bool bMonophonic;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Settings")
	bool bSupportsContinuation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Step Sequencer Settings", meta=(ClampMax="4", ClampMin="0.125"))
	float StepLengthQuarterNotes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Step Sequencer Settings", meta=(ClampMax="4", ClampMin="0.125"))
	float StepBeatScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Step Sequencer Settings")
	bool bSkipFourthStepInTriplet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Step Sequencer Settings")
	EFabricNoteStyle NoteStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Step Sequencer Settings", meta=(ClampMax="64", ClampMin="1"))
	int32 MaxSteps;

	UPROPERTY(BlueprintReadOnly, Category="FabricStepSequencerComponent")
	int32 CurrentSteps;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Settings")
	bool bMatchStepsToTimeSignature;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Step Sequencer Settings", meta=(ClampMax="16", ClampMin="1"))
	int32 MaxPages;

	UPROPERTY(BlueprintReadOnly, Category="FabricStepSequencerComponent")
	int32 CurrentPage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Step Sequencer Settings", meta=(ClampMax="16", ClampMin="1"))
	int32 MaxTracks;

	UPROPERTY(EditAnywhere, Category="Step Sequencer Settings", meta=(ClampMax="16", ClampMin="1"))
	int32 CurrentTracks;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricStepSequencerComponent")
	int32 LocalInteractionStartTrackIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricStepSequencerComponent")
	int32 LocalInteractionStartStepIndex;

	UPROPERTY(BlueprintReadOnly, Category="FabricStepSequencerComponent")
	bool bAutoPage;

	UPROPERTY(BlueprintReadWrite, Category="FabricStepSequencerComponent")
	bool bAutoPagePlaysBlankPages;

	UPROPERTY(BlueprintReadOnly, Category="FabricStepSequencerComponent")
	bool bLoop;

	UPROPERTY(EditDefaultsOnly, Category="FabricStepSequencerComponent")
	uint8 RandomizationCommonSampleSize;

	UPROPERTY(EditDefaultsOnly, Category="FabricStepSequencerComponent", meta=(ClampMax="1", ClampMin="0"))
	float RandomizationRestSelectionMaxPct;

	UPROPERTY(EditDefaultsOnly, Category="FabricStepSequencerComponent", meta=(ClampMax="1", ClampMin="0"))
	float RandomizationCommonPitchSelectionMaxPct;

	UPROPERTY(EditAnywhere, Category="FabricStepSequencerComponent")
	TSubclassOf<AActor> ContinuationControlClass;

	UPROPERTY(Transient)
	FStepSequenceTable LocalStepTable;

	UPROPERTY(EditInstanceOnly, SaveGame, ReplicatedUsing=OnRep_PackedStepTable, Category="FabricStepSequencerComponent")
	FFabricStepTablePacked PackedStepTable;

private:
	UFUNCTION()
	void OnRep_PackedStepTable();

	UPROPERTY(Transient)
	TObjectPtr<UFabricStepSequencerModulatable> StepSequencerModulatable;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CachedContinuationControl;

	UPROPERTY(Transient)
	int32 ContinuationRowIndex;

	UPROPERTY(Transient)
	int32 ContinuationStepIndex;

	UPROPERTY(Transient)
	TObjectPtr<UMidiStepSequence> MetaSoundMidiStepSequence;

};

UCLASS()
class UFabricStepSequencerModulatable : public UFabricModulatable
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	bool bIsChromatic;

	UPROPERTY(Transient)
	bool bModulationValueChanged;

};

