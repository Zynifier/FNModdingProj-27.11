// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaAerialVOMute.generated.h"

class UCommonTextBlock;
class UFortKeybindWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaAerialVOMute : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnVOMuteHoldEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnVOMuteHoldStarted(const float Duration);

	UFUNCTION(BlueprintImplementableEvent)
	void OnVOMuteStateChanged(const bool bIsMuted);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Feedback;

private:
	UFUNCTION()
	void HandleKeybindsChanged();

	UFUNCTION()
	void HandleQuestVOMuteHoldEnded();

	UFUNCTION()
	void HandleQuestVOMuteHoldStarted(const float Duration);

	UFUNCTION()
	void HandleQuestVOMuteStateChanged(const bool bIsMuted);

	UFUNCTION()
	void HandleQuestVOPlayStateChanged(const bool bIsPlaying);

};

