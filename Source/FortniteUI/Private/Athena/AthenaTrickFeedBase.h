// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaTrickFeedBase.generated.h"

class UFortVehicleTrickSet;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaTrickFeedBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void AddTrick(const FText& TrickName);

	UFUNCTION(BlueprintCallable)
	void RequestNextSequence();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void TrickSequenceCanceled();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void TrickSequenceComplete();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void TrickSequenceFailed();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void TrickSequenceStarted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateMultiplier(int32 Multiplier);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateScore(UFortVehicleTrickSet* TrickSet, int32 TotalScore);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateTrickStats(const FText& StatsText);

};

