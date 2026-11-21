// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "HudTalkingHead.generated.h"

class UTexture2D;
enum class EFortAnnouncementDisplayPreference : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UHudTalkingHead : public UFortHUDElementWidget
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

};

