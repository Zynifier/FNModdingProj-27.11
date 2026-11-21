// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioGameplayComponent.h"
#include "Interfaces/IAudioGameplayVolumeInteraction.h"
#include "FortMixModComponent.generated.h"

class USoundMix;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AssetUserData", "Activation", "Collision", "Tags", "Cooking"), ClassGroup=("AudioGameplayVolume"), meta=(BlueprintSpawnableComponent, DisplayName="MixMod"))
class UFortMixModComponent : public UAudioGameplayComponent, public IAudioGameplayVolumeInteraction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Mix")
	TArray<TObjectPtr<USoundMix>> SoundMixModifiers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Mix")
	bool bIsPassive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Mix")
	bool bIsRetrigger;

};

