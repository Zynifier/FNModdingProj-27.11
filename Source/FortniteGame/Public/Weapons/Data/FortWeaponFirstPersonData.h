// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortWeaponFirstPersonData.generated.h"

class UAnimMontage;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortWeaponFirstPersonData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> ReloadAnimation;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponReloadMontage;

	UPROPERTY(EditAnywhere, Category="Ranged|CharacterAnimation")
	TObjectPtr<UAnimMontage> FireAnimation;

	UPROPERTY(EditAnywhere, Category="Ranged|CharacterAnimation")
	TObjectPtr<UAnimMontage> FireDownsightsAnimation;

};

