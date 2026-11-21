// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortPostGameMobileButtonOverlay.generated.h"

class UBacchusButton;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPostGameMobileButtonOverlay : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBacchusButton> Button_PushToTalk;

};

