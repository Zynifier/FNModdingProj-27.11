// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tutorial/FortAthenaTutorialBaseInteraction.h"
#include "FortAthenaTutorialButton.generated.h"

class UCommonButtonLegacy;

UENUM()
enum class ETutorialButtonInteractionType : uint8
{
	Click = 0,
	Press = 1,
};

UCLASS(meta=(DisableNativeTick))
class UFortAthenaTutorialButton : public UFortAthenaTutorialBaseInteraction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnTutorialButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnTutorialButtonPressed();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Button Config")
	ETutorialButtonInteractionType InteractionType;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Tutorial;

};

