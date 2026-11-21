// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/TimerHandle.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortSoundIndicatorInterface.h"
#include "GameplayCueNotify_Jetpack_Hovering.generated.h"

class AFortPlayerPawn;
class UAudioComponent;
class UCurveFloat;
class UFortSoundIndicatorComponent;
class UParticleSystemComponent;
class USoundBase;

UCLASS(HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AGameplayCueNotify_Jetpack_Hovering : public AFortGameplayCueNotify_Loop, public IFortSoundIndicatorInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayLowFuelWarning();

	UFUNCTION(BlueprintImplementableEvent)
	void TryToPlayGroundEffects();

	UPROPERTY(EditAnywhere, Category="GameplayCueNotify_Jetpack_Hovering")
	bool bUsesFuel;

	UPROPERTY(EditAnywhere, Category="GameplayCueNotify_Jetpack_Hovering")
	TObjectPtr<UCurveFloat> OutOfFuelAudioCurve;

	UPROPERTY(BlueprintReadWrite, Export, Category="GameplayCueNotify_Jetpack_Hovering", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AccelAudioComp;

	UPROPERTY(BlueprintReadWrite, Export, Category="GameplayCueNotify_Jetpack_Hovering", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> IdleAudioComp;

	UPROPERTY(BlueprintReadWrite, Export, Category="GameplayCueNotify_Jetpack_Hovering", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> OutOfFuelAudioComp;

	UPROPERTY(BlueprintReadWrite, Export, Category="GameplayCueNotify_Jetpack_Hovering", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> ParticleSystemComp;

	UPROPERTY(BlueprintReadOnly, Category="GameplayCueNotify_Jetpack_Hovering")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(BlueprintReadOnly, Category="GameplayCueNotify_Jetpack_Hovering")
	float ActivationTime;

	UPROPERTY()
	float UpwardVelocity;

	UPROPERTY()
	float FuelVolumeMultiplier;

	UPROPERTY()
	bool bPlayedFuelWarning;

	UPROPERTY()
	FGameplayAttribute FuelAttribute;

	UPROPERTY()
	FGameplayAttribute MaxFuelAttribute;

	UPROPERTY()
	FGameplayAttribute UpwardThrustAttribute;

	UPROPERTY()
	FTimerHandle GroundFXTimerHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LowFuel")
	TArray<float> BeepTimes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LowFuel")
	TObjectPtr<USoundBase> SoundOnFuelLowWarning;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Export, Category="Sound Indicator", meta=(EditInline="true"))
	TObjectPtr<UFortSoundIndicatorComponent> SoundIndicatorComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator")
	TObjectPtr<USoundBase> SoundOnThrust;

};

