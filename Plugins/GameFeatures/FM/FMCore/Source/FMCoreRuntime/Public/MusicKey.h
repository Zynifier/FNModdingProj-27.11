// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MusicKey.generated.h"

UENUM(BlueprintType)
enum class EHarmonicProgression : uint8
{
	NegI = 0 UMETA(DisplayName="-I"),
	NegII = 1 UMETA(DisplayName="-II"),
	NegIII = 2 UMETA(DisplayName="-III"),
	NegIV = 3 UMETA(DisplayName="-IV"),
	NegV = 4 UMETA(DisplayName="-V"),
	NegVI = 5 UMETA(DisplayName="-VI"),
	NegVII = 6 UMETA(DisplayName="-VII"),
	I = 7 UMETA(DisplayName="I"),
	II = 8 UMETA(DisplayName="II"),
	III = 9 UMETA(DisplayName="III"),
	IV = 10 UMETA(DisplayName="IV"),
	V = 11 UMETA(DisplayName="V"),
	VI = 12 UMETA(DisplayName="VI"),
	VII = 13 UMETA(DisplayName="VII"),
	PlusI = 14 UMETA(DisplayName="+I"),
	/* Note: keep UFMCoreMusicFunctionLibrary::kProgressionInterval Maps updated with these entries. */
	Num = 15 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EMusicInterval : uint8
{
	P1 = 0,
	Min2 = 1,
	Maj2 = 2,
	Min3 = 3,
	Maj3 = 4,
	P4 = 5,
	TT = 6,
	P5 = 7,
	Min6 = 8,
	Maj6 = 9,
	Min7 = 10,
	Maj7 = 11,
	Num = 12 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
enum class EMusicKey : uint8
{
	C = 0 UMETA(DisplayName="C"),
	Db = 1 UMETA(DisplayName="C♯/D♭"),
	D = 2 UMETA(DisplayName="D"),
	Eb = 3 UMETA(DisplayName="D♯/E♭"),
	E = 4 UMETA(DisplayName="E"),
	F = 5 UMETA(DisplayName="F"),
	Gb = 6 UMETA(DisplayName="F♯/G♭"),
	G = 7 UMETA(DisplayName="G"),
	Ab = 8 UMETA(DisplayName="G♯/A♭"),
	A = 9 UMETA(DisplayName="A"),
	Bb = 10 UMETA(DisplayName="A♯/B♭"),
	B = 11 UMETA(DisplayName="B"),
	Num = 12 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
enum class EMusicKeyMode : uint8
{
	Major = 0,
	Minor = 1,
	Num = 2 UMETA(DisplayName="None"),
};

