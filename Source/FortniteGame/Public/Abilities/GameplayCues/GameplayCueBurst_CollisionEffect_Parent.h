// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioParameter.h"
#include "Abilities/FortGameplayCueNotify_Burst.h"
#include "GameplayCueBurst_CollisionEffect_Parent.generated.h"

class AActor;
class USoundBase;

UCLASS(HideCategories=("Replication"), meta=(Category="GameplayCue", DisplayName="GCN CollisionEffect Parent"))
class UGameplayCueBurst_CollisionEffect_Parent : public UFortGameplayCueNotify_Burst
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Collision Effect Methods")
	AActor* GetTargetActor() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="Collision Effect Data|Sounds")
	TObjectPtr<USoundBase> DefaultSoundAsset;

	UPROPERTY(EditDefaultsOnly, Category="Collision Effect Data|Sounds")
	TObjectPtr<USoundBase> SmallSoundAsset;

	UPROPERTY(EditDefaultsOnly, Category="Collision Effect Data|Sounds")
	TObjectPtr<USoundBase> AverageSoundAsset;

	UPROPERTY(EditDefaultsOnly, Category="Collision Effect Data|Sounds")
	TObjectPtr<USoundBase> MediumSoundAsset;

	UPROPERTY(EditDefaultsOnly, Category="Collision Effect Data|Sounds")
	TObjectPtr<USoundBase> LargeSoundAsset;

	UPROPERTY(EditDefaultsOnly, Category="Collision Effect Data|Sounds")
	TObjectPtr<USoundBase> ZeroGSoundAsset;

	UPROPERTY(EditDefaultsOnly, Category="Collision Effect Data|Params")
	FAudioParameter AudioParamsArray[2];

};

