// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Sound/FortSwimmingAudioBank.h"
#include "FortAnimNotify_PlaySwimmingSound.generated.h"

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="Play Swimming Sound"))
class UFortAnimNotify_PlaySwimmingSound : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Swimming Sound Type")
	TEnumAsByte<EFortSwimmingAudioType::Type> SoundType;

};

