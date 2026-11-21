// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/EndGame/FortPostGameScreen.h"
#include "FortEliminationScreen.generated.h"

class UAthenaLastKillerInfoWidget;
class UCommonButtonBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEliminationScreen : public UFortPostGameScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void PlayIntroAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void SetContinueButtonText(const FText& InText);

private:
	UPROPERTY(EditAnywhere, Category="Auto-Advance Properties")
	float ScreenDuration;

	UPROPERTY(EditAnywhere, Category="Auto-Advance Properties")
	bool bShouldAutoAdvance;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaLastKillerInfoWidget> Widget_KillerInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEliminationScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Continue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ReportPlayer;

};

