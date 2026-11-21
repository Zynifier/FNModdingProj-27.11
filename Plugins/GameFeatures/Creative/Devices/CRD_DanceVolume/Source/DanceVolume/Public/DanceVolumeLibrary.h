// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DanceVolumeLibrary.generated.h"

class AController;
class AFortPawn;
class UFortItemDefinition;

UCLASS()
class DANCEVOLUME_API UDanceVolumeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void ForceStopMontage(const AFortPawn* FortPawn);

	UFUNCTION(BlueprintPure)
	static UFortItemDefinition* GetLastEmoteExecuted(AController* Controller);

};

