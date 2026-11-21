// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Abilities/FortGameplayCueNotify_Looping.h"
#include "GameplayCueNotify_Jetpack_FuelRegen.generated.h"

class AFortPlayerPawn;
class UAudioComponent;
class UCurveFloat;
class USoundBase;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Replication"))
class AGameplayCueNotify_Jetpack_FuelRegen : public AFortGameplayCueNotify_Looping
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Jetpack")
	void ResetBlink(AFortPlayerPawn* PlayerPawn);

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(Transient)
	uint8 bAudioEnabled : 1;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> OnFuelRegenRampComponent;

	UPROPERTY(Transient)
	float FuelRegenRampVolumeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	FGameplayAttribute FuelAttribute;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	FGameplayAttribute FuelMaxAttribute;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	FGameplayAttribute ReserveFuelAttribute;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	FGameplayAttribute ReserveFuelMaxAttribute;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> SoundOnFuelChangeRamp;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> SoundOnFuelRecharged;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<UCurveFloat> FuelRegenRampVolumeCurve;

};

