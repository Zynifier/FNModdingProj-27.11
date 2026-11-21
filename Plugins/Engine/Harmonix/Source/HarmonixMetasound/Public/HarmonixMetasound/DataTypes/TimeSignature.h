// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MetasoundOutput.h"
#include "HarmonixMidi/BarMap.h"
#include "TimeSignature.generated.h"

UCLASS()
class UTimeSignatureBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category="MetaSoundOutput")
	static FTimeSignature GetTimeSignature(const FMetaSoundOutput& Output, bool& Success);

	UFUNCTION(BlueprintCallable, Category="MetaSoundOutput")
	static bool IsTimeSignature(const FMetaSoundOutput& Output);

};

