// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMCoreMusicFunctionLibrary.h"

int32 UFMCoreMusicFunctionLibrary::GetDegreeShiftFromProgression(EHarmonicProgression Progression)
{
	return int32();
}

EMusicInterval UFMCoreMusicFunctionLibrary::GetIntervalAtStepInScale(int32 ScaleStep, EMusicKeyMode KeyMode)
{
	return EMusicInterval();
}

EMusicInterval UFMCoreMusicFunctionLibrary::GetIntervalForNote(FMidiNote Note, EMusicKey Key)
{
	return EMusicInterval();
}

int32 UFMCoreMusicFunctionLibrary::GetIntervalStepInScale(EMusicInterval Interval, EMusicKeyMode KeyMode)
{
	return int32();
}

FMidiNote UFMCoreMusicFunctionLibrary::GetMidiNoteFromScale(EMusicKey Key, int32 Octave, EMusicInterval Interval)
{
	return FMidiNote();
}

FMidiNote UFMCoreMusicFunctionLibrary::SnapToScale(FMidiNote Note, EMusicKey Key, EMusicKeyMode KeyMode)
{
	return FMidiNote();
}
