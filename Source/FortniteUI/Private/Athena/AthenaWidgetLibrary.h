// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AthenaWidgetLibrary.generated.h"

class APlayerController;
class APlayerState;
class UObject;

UCLASS()
class UAthenaWidgetLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static APlayerState* GetRelevantPlayerState(const APlayerController* PlayerController);

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static bool IsPlayingReplay(const UObject* WorldContextObject);

};

