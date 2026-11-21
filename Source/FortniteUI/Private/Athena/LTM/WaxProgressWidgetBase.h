// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "WaxProgressWidgetBase.generated.h"

class AFortAthenaMutator_Wax;

UCLASS()
class UWaxProgressWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void AdjustForSpectate(bool bIsSpectating);

	UFUNCTION(BlueprintImplementableEvent)
	void DoCoinPulseFor(int32 BarIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void HideCloseToVictoryIfShown();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnAnyTokenChange"))
	void K2_OnAnyTokenChange();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnPodiumChange"))
	void K2_OnPodiumChange();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowEnemyCloseToVictory(int32 CoinsAwayFromVictory);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowPlayerCloseToVictory(int32 CoinsAwayFromVictory);

	UPROPERTY(BlueprintReadOnly, Category="WaxProgressWidgetBase")
	TObjectPtr<AFortAthenaMutator_Wax> WaxMutator;

private:
	UFUNCTION()
	void OnAnyTokenChange();

	UFUNCTION()
	void OnPendingFlashes(const TArray<int32>& Flashes);

};

