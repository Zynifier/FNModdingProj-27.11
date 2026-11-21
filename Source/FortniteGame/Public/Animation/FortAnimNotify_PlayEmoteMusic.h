// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlaySound.h"
#include "FortAnimNotify_PlayEmoteMusic.generated.h"

class USoundBase;

UCLASS(HideCategories=("Object", "Object", "Object"), meta=(DisplayName="Play Emote Music"))
class UFortAnimNotify_PlayEmoteMusic : public UAnimNotify_PlaySound
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AnimNotify")
	TObjectPtr<USoundBase> Sound3P;

};

