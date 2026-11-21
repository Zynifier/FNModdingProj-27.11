// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MidiStepSequence.generated.h"

// First, the USTRUCT(s) that make up the user facing data 
// for this asset...

USTRUCT(BlueprintType)
struct FStepSequenceCell
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, EditFixedSize, Category="MidiStepSequence")
	bool bEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, EditFixedSize, Category="MidiStepSequence")
	bool bContinuation;

};

USTRUCT(BlueprintType)
struct FStepSequenceNote
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MidiStepSequence", meta=(ClampMax="127", ClampMin="0"))
	int32 NoteNumber;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MidiStepSequence", meta=(ClampMax="127", ClampMin="0"))
	int32 Velocity;

};

USTRUCT(BlueprintType)
struct FStepSequenceRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, EditFixedSize, Category="MidiStepSequence")
	TArray<FStepSequenceCell> Cells;

	// If the row is disabled, no notes in that row will play

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MidiStepSequence")
	bool bRowEnabled;

};

USTRUCT(BlueprintType)
struct FStepSequencePage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, EditFixedSize, Category="MidiStepSequence")
	TArray<FStepSequenceRow> Rows;

};

USTRUCT(BlueprintType)
struct FStepSequenceTable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, EditFixedSize, Category="MidiStepSequence")
	TArray<FStepSequencePage> Pages;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, EditFixedSize, Category="MidiStepSequence")
	TArray<FStepSequenceNote> Notes;

	// If >0, any step at index X will be skipped if X % N == N - 1

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, EditFixedSize, Category="MidiStepSequence")
	int32 StepSkipIndex;

};

// This class represents a step sequence table. It is used by the MetasSound Step Sequence node
// to generate midi note on/off messages.

UCLASS(BlueprintType)
class HARMONIXMETASOUND_API UMidiStepSequence : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void DisableRowsAbove(int32 FirstDisabledRow);

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	FStepSequenceCell GetCell(int32 Row, int32 Column);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	FStepSequenceCell GetCellOnPage(int32 Page, int32 Row, int32 Column);

	UFUNCTION(BlueprintPure, Category="MidiStepSequence")
	const FStepSequenceTable& GetStepTable() const;

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	FStepSequenceCell SetCell(int32 Row, int32 Column, bool State);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	FStepSequenceCell SetCellContinuation(int32 Row, int32 Column, bool bState);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	FStepSequenceCell SetCellContinuationOnPage(int32 Page, int32 Row, int32 Column, bool bState);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	FStepSequenceCell SetCellOnPage(int32 Page, int32 Row, int32 Column, bool State);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void SetNumColumns(int32 Count);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void SetNumPages(int32 Count);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void SetNumRows(int32 Count);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	bool SetRowNoteNumber(int32 RowIndex, int32 MidiNoteNumber);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	bool SetRowVelocity(int32 RowIndex, int32 MidiVelocoty);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	bool SetStepSkipIndex(int32 StepIndex);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	void SetStepTable(const FStepSequenceTable& NewStepTable);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	FStepSequenceCell ToggleCell(int32 Row, int32 Column);

	UFUNCTION(BlueprintCallable, Category="MidiStepSequence")
	FStepSequenceCell ToggleCellOnPage(int32 Page, int32 Row, int32 Column);

	UPROPERTY(EditAnywhere, BlueprintSetter=SetNumPages, Category="MidiStepSequence", meta=(ClampMax="8", ClampMin="1"))
	int32 Pages;

	UPROPERTY(EditAnywhere, BlueprintSetter=SetNumRows, Category="MidiStepSequence", meta=(ClampMax="16", ClampMin="1"))
	int32 Rows;

	UPROPERTY(EditAnywhere, BlueprintSetter=SetNumColumns, Category="MidiStepSequence", meta=(ClampMax="64", ClampMin="4"))
	int32 Columns;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MidiStepSequence")
	FStepSequenceTable StepTable;

};

