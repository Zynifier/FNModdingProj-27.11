// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MetasoundOutput.h"
#include "HarmonixMidi/BarMap.h"
#include "MidiEventInfo.generated.h"

USTRUCT(BlueprintType)
struct HARMONIXMETASOUND_API FMidiEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Music")
	FMusicTimestamp Timestamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Music")
	int32 TrackIndex;

};

UCLASS()
class UMidiEventInfoBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category="Music")
	static int32 GetChannel(const FMidiEventInfo& Event);

	UFUNCTION(BlueprintCallable, Category="MetaSoundOutput")
	static FMidiEventInfo GetMidiEventInfo(const FMetaSoundOutput& Output, bool& Success);

	UFUNCTION(BlueprintCallable, Category="Music")
	static int32 GetNoteNumber(const FMidiEventInfo& Event);

	UFUNCTION(BlueprintCallable, Category="Music")
	static int32 GetVelocity(const FMidiEventInfo& Event);

	UFUNCTION(BlueprintCallable, Category="MetaSoundOutput")
	static bool IsMidiEventInfo(const FMetaSoundOutput& Output);

	UFUNCTION(BlueprintCallable, Category="Music")
	static bool IsNote(const FMidiEventInfo& Event);

	UFUNCTION(BlueprintCallable, Category="Music")
	static bool IsNoteOff(const FMidiEventInfo& Event);

	UFUNCTION(BlueprintCallable, Category="Music")
	static bool IsNoteOn(const FMidiEventInfo& Event);

};

