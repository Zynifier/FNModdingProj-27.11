// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "AthenaSocialScreen.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, Config=Game, MinimalAPI, meta=(DisableNativeTick))
class UAthenaSocialScreen : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	void ShowCareerScreen();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ViewCareer;

};

