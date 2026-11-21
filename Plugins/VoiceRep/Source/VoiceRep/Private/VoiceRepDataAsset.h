// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VoiceRepDataAsset.generated.h"

class UWidget;

UCLASS()
class UVoiceRepDataAsset : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<UWidget> VoiceChatTooltipWidgetClass;

	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<UWidget> FirstOnboardingWidgetClass;

	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<UWidget> SecondOnboardingWidgetClass;

	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<UWidget> ReportVoiceWidgetClass;

};

