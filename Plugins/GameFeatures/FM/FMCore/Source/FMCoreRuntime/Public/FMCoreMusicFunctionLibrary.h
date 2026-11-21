// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HarmonixMidi/Blueprint/MidiNote.h"
#include "FMCoreMusicFunctionLibrary.generated.h"

enum class EHarmonicProgression : uint8;
enum class EMusicInterval : uint8;
enum class EMusicKey : uint8;
enum class EMusicKeyMode : uint8;

UCLASS(BlueprintType, Blueprintable)
class FMCORERUNTIME_API UFMCoreMusicFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static int32 GetDegreeShiftFromProgression(EHarmonicProgression Progression);

	UFUNCTION(BlueprintPure)
	static EMusicInterval GetIntervalAtStepInScale(int32 ScaleStep, EMusicKeyMode KeyMode);

	UFUNCTION(BlueprintPure)
	static EMusicInterval GetIntervalForNote(FMidiNote Note, EMusicKey Key);

	UFUNCTION(BlueprintPure)
	static int32 GetIntervalStepInScale(EMusicInterval Interval, EMusicKeyMode KeyMode);

	UFUNCTION(BlueprintPure)
	static FMidiNote GetMidiNoteFromScale(EMusicKey Key, int32 Octave, EMusicInterval Interval);

	UFUNCTION(BlueprintPure)
	static FMidiNote SnapToScale(FMidiNote Note, EMusicKey Key, EMusicKeyMode KeyMode);

};

