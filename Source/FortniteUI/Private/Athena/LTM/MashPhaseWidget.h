// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "Athena/Modifiers/FortAthenaMutator_Mash.h"
#include "MashPhaseWidget.generated.h"

class AFortAthenaMutator_Mash;
class AFortPawn;
class AFortPlayerControllerAthena;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UMashPhaseWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownStarted(int32 TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownUpdate(int32 TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerAlive();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerDead();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMashBossPawnChanged(AFortPawn* NewBossPawn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPhaseChanged(const EMashPhase::Type NewPhase, const int32 CurrentObjectiveIndex, const int32 TotalObjectiveArea);

protected:
	UFUNCTION()
	void HandleCountdownFinished();

	UFUNCTION()
	void HandleCountdownStarted(const int32 TimeRemaining);

	UFUNCTION()
	void HandleCountdownUpdate();

	UFUNCTION()
	void HandleMashPhaseChanged(int32 NewPhase);

	UFUNCTION()
	void HandlePlayersLeftChanged(int32 InPlayersLeft);

	UPROPERTY(BlueprintReadOnly, Transient, Category="MashPhaseWidget")
	TEnumAsByte<EMashPhase::Type> CurrentPhase;

	UPROPERTY(Transient)
	int32 CurrentObjectiveAreaIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MashPhaseWidget")
	TObjectPtr<AFortAthenaMutator_Mash> MashMutatorRef;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerControllerAthena> CachedLocalPlayerController;

	UPROPERTY(Transient)
	bool CachedIsLocalPlayerAlive;

};

