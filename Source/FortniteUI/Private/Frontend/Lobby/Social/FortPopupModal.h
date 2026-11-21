// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortPopupModal.generated.h"

class UCommonButtonBase;

UCLASS(meta=(DisableNativeTick))
class UFortPopupModal : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortPopupModal(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* IconTextButton_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* Button_CloseTouch;

};

