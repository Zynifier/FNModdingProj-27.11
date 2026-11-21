// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortContentGatingIntroModal.generated.h"

class UCommonButtonBase;

UCLASS()
class UFortContentGatingIntroModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	void ExitModal();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

};

