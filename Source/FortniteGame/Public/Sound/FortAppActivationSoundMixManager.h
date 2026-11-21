// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortAppActivationSoundMixManager.generated.h"

class USoundMix;

USTRUCT()
struct FFortAppActivationSoundMixPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAppActivationSoundMixPair")
	TObjectPtr<USoundMix> TrueMix;

	UPROPERTY(EditAnywhere, Category="FortAppActivationSoundMixPair")
	TObjectPtr<USoundMix> FalseMix;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAppActivationSoundMixManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sound Mixes")
	FFortAppActivationSoundMixPair InAppSoundsAllowedMix;

	UPROPERTY(EditAnywhere, Category="Sound Mixes")
	FFortAppActivationSoundMixPair AppActiveSoundMix;

};

