// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HarmonixMidi/MidiTrack.h"
#include "HarmonixMidi/SongMaps.h"
#include "MidiFile.generated.h"

class UAssetImportData;

USTRUCT(BlueprintType)
struct HARMONIXMIDI_API FMidiFileData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MidiFile")
	FString MidiFileName;

	UPROPERTY(BlueprintReadOnly, Category="MidiFile")
	int32 TicksPerQuarterNote;

	UPROPERTY(BlueprintReadOnly, Category="MidiFile")
	FSongMaps SongMaps;

	UPROPERTY(BlueprintReadOnly, Category="MidiFile")
	TArray<FMidiTrack> Tracks;

	UPROPERTY(BlueprintReadOnly, Category="MidiFile")
	int32 LastEventTick;

};

/**
 * An FMidFile is primarily a container for FMidiTracks. 
 * 
 * This class can handle loading and saving standard midi files, as well
 * as serializing itself to standard Unreal Engine FArchives.
 */
UCLASS(BlueprintType, meta=(Category="Music"))
class HARMONIXMIDI_API UMidiFile : public UObject
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	// Import data for this MidiFileAsset
// updated during Import in MidiFile

	UPROPERTY(VisibleAnywhere, Instanced, Category="ImportSettings")
	TObjectPtr<UAssetImportData> AssetImportData;
#endif

	//The Start Bar of a Midi File

	UPROPERTY(EditAnywhere, Category="Midi File Start Bar")
	int32 StartBar;

	//Midi File Conform Option, keep track if the files' length are conformed during import

	UPROPERTY(BlueprintReadOnly, Category="MidiFile")
	bool bLengthRoundedDown;

	UPROPERTY(BlueprintReadOnly, Category="MidiFile")
	bool bLengthRoundedUp;

	UPROPERTY(BlueprintReadOnly, Category="MidiFile")
	bool bLengthRoundedToNearest;

protected:
	UPROPERTY()
	FMidiFileData TheMidiData;

};

