// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GameplayTagContainer.h"
#include "FortAnimNotify_PlayPetSound.generated.h"

UCLASS(HideCategories=("Object"), meta=(DisplayName="Play Pet Sound"))
class UFortAnimNotify_PlayPetSound : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sound", meta=(Categories="Cosmetics.Pet.Sound"))
	FGameplayTag PetSoundTag;

};

