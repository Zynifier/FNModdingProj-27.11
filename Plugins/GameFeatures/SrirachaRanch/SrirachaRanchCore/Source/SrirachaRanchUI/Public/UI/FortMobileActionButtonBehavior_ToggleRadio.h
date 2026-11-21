// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "Components/StreamingRadioPlayerComponent.h"
#include "FortMobileActionButtonBehavior_ToggleRadio.generated.h"

class UPaperSprite;
class UStreamingRadioPlayerComponent;

UCLASS()
class SRIRACHARANCHUI_API UFortMobileActionButtonBehavior_ToggleRadio : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleRadioPlaying(UStreamingRadioPlayerComponent* Radio, FAthenaRadioStation Source);

	UFUNCTION()
	void HandleRadioStopped(UStreamingRadioPlayerComponent* Radio, FAthenaRadioStation Source);

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> ToggleRadioOffSprite;

};

