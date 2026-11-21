// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MusicTimeSpan.generated.h"

UENUM()
enum class EMusicTimeSpanLengthUnits : uint8
{
	/** (dependent on time signature) */
	Bars = 0 UMETA(DisplayName="Bars"),
	/** (dependent on time signature and Pulse Override) */
	Beats = 1 UMETA(DisplayName="Beats"),
	ThirtySecondNotes = 2 UMETA(DisplayName="1/32s"),
	SixteenthNotes = 3 UMETA(DisplayName="1/16s"),
	EighthNotes = 4 UMETA(DisplayName="1/8s"),
	QuarterNotes = 5 UMETA(DisplayName="1/4s"),
	HalfNotes = 6 UMETA(DisplayName="Halfs"),
	WholeNotes = 7 UMETA(DisplayName="Wholes"),
	DottedSixteenthNotes = 8 UMETA(DisplayName="(dotted) 1/16s"),
	DottedEighthNotes = 9 UMETA(DisplayName="(dotted) 1/8s"),
	DottedQuarterNotes = 10 UMETA(DisplayName="(dotted) 1/4s"),
	DottedHalfNotes = 11 UMETA(DisplayName="(dotted) Halfs"),
	DottedWholeNotes = 12 UMETA(DisplayName="(dotted) Wholes"),
	SixteenthNoteTriplets = 13 UMETA(DisplayName="1/16 (triplets)"),
	EighthNoteTriplets = 14 UMETA(DisplayName="1/8 (triplets)"),
	QuarterNoteTriplets = 15 UMETA(DisplayName="1/4 (triplets)"),
	HalfNoteTriplets = 16 UMETA(DisplayName="1/2 (triplets)"),
};

UENUM()
enum class EMusicTimeSpanOffsetUnits : uint8
{
	Ms = 0 UMETA(DisplayName="Milliseconds", EnumDefault),
	/** (dependent on time signature) */
	Bars = 1 UMETA(DisplayName="Bars"),
	/** (dependent on time signature and Pulse Override) */
	Beats = 2 UMETA(DisplayName="Beats"),
	ThirtySecondNotes = 3 UMETA(DisplayName="1/32s"),
	SixteenthNotes = 4 UMETA(DisplayName="1/16s"),
	EighthNotes = 5 UMETA(DisplayName="1/8s"),
	QuarterNotes = 6 UMETA(DisplayName="1/4s"),
	HalfNotes = 7 UMETA(DisplayName="Halfs"),
	WholeNotes = 8 UMETA(DisplayName="Wholes"),
	DottedSixteenthNotes = 9 UMETA(DisplayName="(dotted) 1/16s"),
	DottedEighthNotes = 10 UMETA(DisplayName="(dotted) 1/8s"),
	DottedQuarterNotes = 11 UMETA(DisplayName="(dotted) 1/4s"),
	DottedHalfNotes = 12 UMETA(DisplayName="(dotted) Halfs"),
	DottedWholeNotes = 13 UMETA(DisplayName="(dotted) Wholes"),
	SixteenthNoteTriplets = 14 UMETA(DisplayName="1/16 (triplets)"),
	EighthNoteTriplets = 15 UMETA(DisplayName="1/8 (triplets)"),
	QuarterNoteTriplets = 16 UMETA(DisplayName="1/4 (triplets)"),
	HalfNoteTriplets = 17 UMETA(DisplayName="1/2 (triplets)"),
};

USTRUCT(BlueprintType, meta=(Category="HarmonixMidi", ScriptName="MusicalTimeSpan"))
struct HARMONIXMIDI_API FMusicalTimeSpan
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixMidi")
	EMusicTimeSpanLengthUnits LengthUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixMidi")
	int32 Length;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixMidi")
	EMusicTimeSpanOffsetUnits OffsetUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixMidi")
	int32 Offset;

};

