// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponHitNotifyAudioBank.generated.h"

class USoundBase;

UCLASS(BlueprintType)
class UWeaponHitNotifyAudioBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundBody;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundCrit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundShield;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundDeath;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundDeathCrit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundBodyReceive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundShieldReceive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundCritReceive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundDeathReceive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundDeathCritReceive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundFallReceive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundFallDeathReceive;

};

