// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixMetasound/DataTypes/MidiStepSequence.h"

void UMidiStepSequence::DisableRowsAbove(int32 FirstDisabledRow)
{
}

FStepSequenceCell UMidiStepSequence::GetCell(int32 Row, int32 Column)
{
	return FStepSequenceCell();
}

FStepSequenceCell UMidiStepSequence::GetCellOnPage(int32 Page, int32 Row, int32 Column)
{
	return FStepSequenceCell();
}

const FStepSequenceTable& UMidiStepSequence::GetStepTable() const
{
	static FStepSequenceTable Dummy;
	return Dummy;
}

FStepSequenceCell UMidiStepSequence::SetCell(int32 Row, int32 Column, bool State)
{
	return FStepSequenceCell();
}

FStepSequenceCell UMidiStepSequence::SetCellContinuation(int32 Row, int32 Column, bool bState)
{
	return FStepSequenceCell();
}

FStepSequenceCell UMidiStepSequence::SetCellContinuationOnPage(int32 Page, int32 Row, int32 Column, bool bState)
{
	return FStepSequenceCell();
}

FStepSequenceCell UMidiStepSequence::SetCellOnPage(int32 Page, int32 Row, int32 Column, bool State)
{
	return FStepSequenceCell();
}

void UMidiStepSequence::SetNumColumns(int32 Count)
{
}

void UMidiStepSequence::SetNumPages(int32 Count)
{
}

void UMidiStepSequence::SetNumRows(int32 Count)
{
}

bool UMidiStepSequence::SetRowNoteNumber(int32 RowIndex, int32 MidiNoteNumber)
{
	return false;
}

bool UMidiStepSequence::SetRowVelocity(int32 RowIndex, int32 MidiVelocoty)
{
	return false;
}

bool UMidiStepSequence::SetStepSkipIndex(int32 StepIndex)
{
	return false;
}

void UMidiStepSequence::SetStepTable(const FStepSequenceTable& NewStepTable)
{
}

FStepSequenceCell UMidiStepSequence::ToggleCell(int32 Row, int32 Column)
{
	return FStepSequenceCell();
}

FStepSequenceCell UMidiStepSequence::ToggleCellOnPage(int32 Page, int32 Row, int32 Column)
{
	return FStepSequenceCell();
}
