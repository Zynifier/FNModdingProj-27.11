// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Missions/FortMissionStormShield.h"
#include "AthenaCobaltStormShield.generated.h"

class AFortAthenaMutator_Cobalt;
class UAudioComponent;
class USoundBase;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AAthenaCobaltStormShield : public AFortMissionStormShield
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<USoundBase> ShieldBoundarySound;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float LowpassAudioListenerRange;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float LowpassAudioValueOutside;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float LowpassAudioValueInside;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float LowpassAudioInterpSpeed;

private:
	UFUNCTION()
	void ClientStormShieldShrinkTimerComplete();

	UFUNCTION()
	void OnRep_ClientStormShieldShrinkTimerValue();

	UFUNCTION()
	void StormShieldShrinkTimerComplete();

	UPROPERTY(Replicated)
	TObjectPtr<AFortAthenaMutator_Cobalt> CachedMutator;

	UPROPERTY()
	FTimerHandle ShrinkTimerHandle;

	UPROPERTY()
	FTimerHandle ClientShrinkTimerHandle;

	UPROPERTY(ReplicatedUsing=OnRep_ClientStormShieldShrinkTimerValue)
	float ClientStormShieldShrinkTimerValue;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> ShieldBoundaryAudio;

};

