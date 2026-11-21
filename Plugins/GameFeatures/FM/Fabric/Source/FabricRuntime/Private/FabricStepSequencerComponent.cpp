// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricStepSequencerComponent.h"
#include "Net/UnrealNetwork.h"

void UFabricStepSequencerComponent::ApplyPage(int32 PageIndex, const FStepSequencePage& PageData)
{
}

void UFabricStepSequencerComponent::ApplyTemplate(const UMidiStepSequence* Template, int32 StepSequencePageIndex)
{
}

void UFabricStepSequencerComponent::ClearCurrentPage()
{
}

void UFabricStepSequencerComponent::ClearPage(int32 Page)
{
}

void UFabricStepSequencerComponent::GetContinuationFocusIndeces(int32& OutRowIndex, int32& OutStepIndex, int32& OutNumContinuationSteps)
{
}

int32 UFabricStepSequencerComponent::GetCurrentPage() const
{
	return int32();
}

float UFabricStepSequencerComponent::GetLengthStepBeats() const
{
	return float();
}

float UFabricStepSequencerComponent::GetLengthStepQuarterNotes() const
{
	return float();
}

float UFabricStepSequencerComponent::GetLengthTrackBeats() const
{
	return float();
}

float UFabricStepSequencerComponent::GetLengthTrackQuarterNotes() const
{
	return float();
}

float UFabricStepSequencerComponent::GetLongestContinuationLengthForColumn(int32 Column) const
{
	return float();
}

float UFabricStepSequencerComponent::GetLongestContinuationLengthForColumnOnPage(int32 Page, int32 Column) const
{
	return float();
}

int32 UFabricStepSequencerComponent::GetMaxSteps() const
{
	return int32();
}

UMidiStepSequence* UFabricStepSequencerComponent::GetMidiStepSequence()
{
	return nullptr;
}

int32 UFabricStepSequencerComponent::GetNumberSteps() const
{
	return int32();
}

int32 UFabricStepSequencerComponent::GetNumberTracks() const
{
	return int32();
}

int32 UFabricStepSequencerComponent::GetNumUsedSteps(int32 TotalSteps) const
{
	return int32();
}

void UFabricStepSequencerComponent::GetPageData(int32 PageIndex, FStepSequencePage& OutPageData) const
{
}

float UFabricStepSequencerComponent::GetStepContinuationLength(int32 Row, int32 Column) const
{
	return float();
}

float UFabricStepSequencerComponent::GetStepContinuationLengthOnPage(int32 Page, int32 Row, int32 Column) const
{
	return float();
}

bool UFabricStepSequencerComponent::GetStepEnabled(int32 Row, int32 Column) const
{
	return false;
}

bool UFabricStepSequencerComponent::GetStepEnabledOnPage(int32 Page, int32 Row, int32 Column) const
{
	return false;
}

bool UFabricStepSequencerComponent::GetStepIsContinuation(int32 Row, int32 Column) const
{
	return false;
}

bool UFabricStepSequencerComponent::GetStepIsContinuationOnPage(int32 Page, int32 Row, int32 Column) const
{
	return false;
}

float UFabricStepSequencerComponent::GetStepStartBeat(int32 Step) const
{
	return float();
}

float UFabricStepSequencerComponent::GetStepStartQuarterNotes(int32 Step) const
{
	return float();
}

bool UFabricStepSequencerComponent::GetSupportsContinuation() const
{
	return false;
}

bool UFabricStepSequencerComponent::IsPageBlank(int32 PageIndex) const
{
	return false;
}

bool UFabricStepSequencerComponent::IsStepEnabledForAnyTrack(int32 Column) const
{
	return false;
}

bool UFabricStepSequencerComponent::IsStepEnabledForAnyTrackOnPage(int32 Page, int32 Column) const
{
	return false;
}

void UFabricStepSequencerComponent::OnRep_PackedStepTable()
{
}

void UFabricStepSequencerComponent::RandomizeCurrentPage()
{
}

void UFabricStepSequencerComponent::RandomizePage(int32 Page)
{
}

void UFabricStepSequencerComponent::SetBeatScale(float BeatScale)
{
}

void UFabricStepSequencerComponent::SetCurrentPage(int32 NewPage)
{
}

void UFabricStepSequencerComponent::SetLoop(bool bNewLoop)
{
}

void UFabricStepSequencerComponent::SetMaxSteps(int32 NumSteps)
{
}

void UFabricStepSequencerComponent::SetMonophonic(bool bNewMonophonic)
{
}

void UFabricStepSequencerComponent::SetMusicClock(UMusicClockComponent* InMusicClock)
{
}

void UFabricStepSequencerComponent::SetNoteForTrack(FMidiNote Note, int32 Track)
{
}

void UFabricStepSequencerComponent::SetNoteStyle(EFabricNoteStyle Style)
{
}

void UFabricStepSequencerComponent::SetNumberPages(int32 NumPages)
{
}

void UFabricStepSequencerComponent::SetNumberSteps(int32 NumSteps)
{
}

void UFabricStepSequencerComponent::SetNumberTracks(int32 NumTracks)
{
}

void UFabricStepSequencerComponent::SetPlaying(bool bNewPlaying)
{
}

void UFabricStepSequencerComponent::SetQuarterNotesLength(float QuarterNotes)
{
}

void UFabricStepSequencerComponent::SetStepContinuation(int32 Row, int32 Column, bool bIsContinuation)
{
}

void UFabricStepSequencerComponent::SetStepContinuationOnPage(int32 Page, int32 Row, int32 Column, bool bIsContinuation)
{
}

void UFabricStepSequencerComponent::SetStepEnabled(int32 Row, int32 Column, bool bState)
{
}

void UFabricStepSequencerComponent::SetStepEnabledOnPage(int32 Page, int32 Row, int32 Column, bool bState)
{
}

void UFabricStepSequencerComponent::ToggleStepEnabled(int32 Row, int32 Column)
{
}

void UFabricStepSequencerComponent::ToggleStepEnabledOnPage(int32 Page, int32 Row, int32 Column)
{
}

void UFabricStepSequencerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFabricStepSequencerComponent, PackedStepTable);
}
