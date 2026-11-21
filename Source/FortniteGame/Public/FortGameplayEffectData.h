// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortGameplayEffectData.generated.h"

class UGameplayEffect;

UCLASS()
class UFortGameplayEffectData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortGameplayEffectData")
	TSubclassOf<UGameplayEffect> PawnHideGameplayEffectDefault;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayEffectData")
	FGameplayTag GameplayCueDamagePhysicalExplosionTag;

};

