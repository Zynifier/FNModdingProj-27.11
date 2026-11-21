// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AthenaPlayerMatchReport.h"
#include "AthenaTravelLogFormatting.generated.h"

class UObject;

UCLASS()
class UAthenaTravelLogFormatting : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static FText FormatTravelLogEntry(UObject* WorldContextObject, const FAthenaTravelLogEntry& Entry);

	UFUNCTION(BlueprintPure)
	static bool IsTravelLogTextDisplayEnabled();

	UFUNCTION(BlueprintPure)
	static bool ShouldDisplayText(const FAthenaTravelLogEntry& Entry);

};

