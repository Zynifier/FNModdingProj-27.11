// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "TalkingHead.generated.h"

class UTexture2D;
enum class EFortAnnouncementDisplayPreference : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UTalkingHead : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginSpokenDialog();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCloseTalkingHead();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndSpokenDialog();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenTalkingHead(UTexture2D* Image, const FText& Title, const FText& Subtitle, EFortAnnouncementDisplayPreference DisplayPreference);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShouldBlockSubtitlePortraitChanged(bool bShouldBlockSubtitlePortrait);

};

