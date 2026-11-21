// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCreativeExitDialog.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeExitDialog : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnBackClicked();

	UFUNCTION()
	void OnConfirmClicked();

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeExitDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Confirm;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeExitDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

};

