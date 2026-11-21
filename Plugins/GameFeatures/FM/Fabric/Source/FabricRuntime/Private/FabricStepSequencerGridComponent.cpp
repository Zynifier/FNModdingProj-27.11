// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricStepSequencerGridComponent.h"

FVector UFabricStepSequencerGridComponent::GetGridSquareExtents(const int32 RowIndex, const int32 ColumnIndex) const
{
	return FVector();
}

FVector2D UFabricStepSequencerGridComponent::GetGridSquareSize(const int32 NumSteps, const int32 NumRows) const
{
	return FVector2D();
}

float UFabricStepSequencerGridComponent::GetGridSquareXPosition(const int32 NumSteps, const int32 StepIndex)
{
	return float();
}

float UFabricStepSequencerGridComponent::GetGridSquareYPosition(const int32 NumRows, const int32 RowIndex)
{
	return float();
}

bool UFabricStepSequencerGridComponent::IsBypassed()
{
	return false;
}

bool UFabricStepSequencerGridComponent::IsStepToggledOnForAnyTrack(int32 StepIndex) const
{
	return false;
}

void UFabricStepSequencerGridComponent::NotifyInteractionFocusTargetExternallyChanged(APlayerController* PlayerController, int32 SourceRowIndex, int32 SourceColumnIndex, int32 FocusRowIndex, int32 FocusColumnIndex, bool bIsFocused)
{
}

void UFabricStepSequencerGridComponent::OnBeatOffsetChanged(float BeatOffset)
{
}

void UFabricStepSequencerGridComponent::OnBeatScaleChanged(float BeatScale)
{
}

void UFabricStepSequencerGridComponent::OnCurrentPageChanged(int32 NewPage)
{
}

void UFabricStepSequencerGridComponent::OnFullTableChanged()
{
}

void UFabricStepSequencerGridComponent::OnNoteStyleChanged(EFabricNoteStyle Style)
{
}

void UFabricStepSequencerGridComponent::OnNumStepsChanged(int32 NumSteps)
{
}

void UFabricStepSequencerGridComponent::OnNumTracksChanged(int32 NumTracks)
{
}

void UFabricStepSequencerGridComponent::OnQuarterNotesLengthChanged(float QuarterNotesLength)
{
}

void UFabricStepSequencerGridComponent::OnStepChanged(const FFabricSequencerStepChangedInfo& StepInfo)
{
}

void UFabricStepSequencerGridComponent::SetActiveTrackIndex(int32 ActiveTrackIndex)
{
}

void UFabricStepSequencerGridComponent::SetBypassed(bool bBypassed)
{
}

void UFabricStepSequencerGridComponent::SetGridVisible(bool bInGridVisible, bool bForceRefresh)
{
}
