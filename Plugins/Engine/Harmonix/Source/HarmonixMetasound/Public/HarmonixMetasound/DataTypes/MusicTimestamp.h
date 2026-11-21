// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MetasoundOutput.h"
#include "HarmonixMidi/BarMap.h"
#include "MusicTimestamp.generated.h"

UCLASS()
class UMusicTimestampBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category="MetaSoundOutput")
	static FMusicTimestamp GetMusicTimestamp(const FMetaSoundOutput& Output, bool& Success);

	UFUNCTION(BlueprintCallable, Category="MetaSoundOutput")
	static bool IsMusicTimestamp(const FMetaSoundOutput& Output);

};

