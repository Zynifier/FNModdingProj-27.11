// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "FortAudioMixSettings.generated.h"

class USoundControlBus;
class USoundControlBusMix;

USTRUCT()
struct FFortUserMixSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortUserMixSettings")
	TObjectPtr<USoundControlBusMix> Mix;

	UPROPERTY(EditAnywhere, Category="FortUserMixSettings")
	TObjectPtr<USoundControlBus> MainBus;

	UPROPERTY(EditAnywhere, Category="FortUserMixSettings")
	TObjectPtr<USoundControlBus> MusicBus;

	UPROPERTY(EditAnywhere, Category="FortUserMixSettings")
	TObjectPtr<USoundControlBus> SFXBus;

	UPROPERTY(EditAnywhere, Category="FortUserMixSettings")
	TObjectPtr<USoundControlBus> DialogueBus;

	UPROPERTY(EditAnywhere, Category="FortUserMixSettings")
	TObjectPtr<USoundControlBus> ChatBus;

	UPROPERTY(EditAnywhere, Category="FortUserMixSettings")
	TObjectPtr<USoundControlBus> CinematicsBus;

	UPROPERTY(EditAnywhere, Category="FortUserMixSettings")
	TObjectPtr<USoundControlBus> PIPBus;

};

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Audio Mix"))
class UFortAudioMixSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Config")
	FFortUserMixSettings UserMixSettings;

};

