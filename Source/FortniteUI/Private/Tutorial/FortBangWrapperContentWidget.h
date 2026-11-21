// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Tutorial/FortBangWrapperContentInterface.h"
#include "FortBangWrapperContentWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortBangWrapperContentWidget : public UCommonUserWidget, public IFortBangWrapperContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="BangWrapperContentButton")
	void FinishTutorialCallout();

};

