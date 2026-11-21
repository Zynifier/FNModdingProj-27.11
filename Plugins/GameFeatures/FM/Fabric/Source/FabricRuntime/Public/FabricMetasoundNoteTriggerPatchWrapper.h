// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MetasoundOutput.h"
#include "FabricMetasoundPatchWrapper.h"
#include "HarmonixMetasound/DataTypes/MidiEventInfo.h"
#include "FabricMetasoundNoteTriggerPatchWrapper.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNoteTriggerMatchingMidiEventPassed, const FMidiEventInfo&, MidiEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNoteTriggerMidiEventPassed, const FMidiEventInfo&, MidiEvent, bool, bMatchesOctave);

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricNoteTriggerPatchWrapper : public UFabricMetaSoundPatchWrapper
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Metasounds")
	FName NoteOutputName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modulatable")
	FString OctaveParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modulatable")
	TArray<FString> TriggerNoteParams;

	UPROPERTY(BlueprintAssignable)
	FOnNoteTriggerMidiEventPassed OnAnyMidiEventPassed;

	UPROPERTY(BlueprintAssignable)
	FOnNoteTriggerMatchingMidiEventPassed OnMatchingMidiEventPassed;

protected:
	UFUNCTION()
	void OnMetaSoundMidiEventPassed(FName OutputName, const FMetaSoundOutput& Output);

};

