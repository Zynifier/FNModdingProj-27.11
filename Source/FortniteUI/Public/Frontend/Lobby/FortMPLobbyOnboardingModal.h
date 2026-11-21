// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortMPLobbyOnboardingModal.generated.h"

class UCommonButtonBase;

UCLASS(Config=Game, meta=(DisableNativeTick))
class UFortMPLobbyOnboardingModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ExitModal();

	UPROPERTY(BlueprintReadWrite, Export, Category="FortMPLobbyOnboardingModal", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GetStarted;

};

