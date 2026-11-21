// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "PowTimerWidgetBase.generated.h"

class AFortAthenaMutator_Pow;

UCLASS()
class UPowTimerWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRespawnTimeElasped();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatedRespawnTime(int32 Minutes, int32 Seconds);

	UPROPERTY(EditDefaultsOnly, Category="PowTimerWidgetBase")
	FScalableFloat TimeShowTimerAt;

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_Pow> BaseMutator;

private:
	UFUNCTION()
	void NewRespawnTime(int32 NewTimeRemaining);

};

