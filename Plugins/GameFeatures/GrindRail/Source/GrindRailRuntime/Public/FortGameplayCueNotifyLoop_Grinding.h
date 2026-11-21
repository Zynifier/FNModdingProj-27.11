// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "Sound/FortAudioTypes.h"
#include "FortGameplayCueNotifyLoop_Grinding.generated.h"

class AFortPlayerPawn;
class UAudioComponent;
class UFXSystemComponent;
class UFortPawnComponent_GrindRail;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(DisplayName="GCNL Grinding", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_Grinding : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CacheReferences(UAudioComponent* InAudioComponent, UFXSystemComponent* InEffectsComponent, AFortPlayerPawn* InPlayerPawn, UFortPawnComponent_GrindRail* InGrindComponent);

	UFUNCTION(BlueprintImplementableEvent, Category="Audio|Native")
	void OnForwardChanged(bool bNewState);

	UPROPERTY(BlueprintReadWrite, Category="Audio|Native")
	bool bFeetHasLanded;

	UPROPERTY(EditDefaultsOnly, Category="Audio|Native")
	bool bEnableNativeAudioUpdate;

	UPROPERTY(EditDefaultsOnly, Category="Audio|Native")
	float ForwardChangedValueThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Audio|Native")
	FFortAudioFloatParameter Speed;

	UPROPERTY(EditDefaultsOnly, Category="Audio|Native")
	FFortAudioFloatParameter Forward;

	UPROPERTY(EditDefaultsOnly, Category="Audio|Native")
	FFortAudioFloatParameter Boost;

	UPROPERTY(EditDefaultsOnly, Category="Audio|Native")
	FFortAudioFloatParameter Curve;

	UPROPERTY(EditDefaultsOnly, Category="Audio|Native")
	FFortAudioFloatParameter IsGrinding;

	UPROPERTY(EditDefaultsOnly, Category="Audio|Native")
	FFortAudioFloatParameter IsSlowDown;

	UPROPERTY(EditDefaultsOnly, Category="Effects|Native")
	FName LeanForwardSpeedName;

	UPROPERTY(EditDefaultsOnly, Category="Effects|Native")
	FName TurnOnSpeedFXName;

	UPROPERTY(EditDefaultsOnly, Category="Effects|Native")
	float TurnOnSpeedFXThreshold;

private:
	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFXSystemComponent> EffectsComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPawnComponent_GrindRail> GrindComponent;

};

