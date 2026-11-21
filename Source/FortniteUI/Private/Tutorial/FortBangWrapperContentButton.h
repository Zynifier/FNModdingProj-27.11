// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "Tutorial/FortBangWrapperContentInterface.h"
#include "FortBangWrapperContentButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortBangWrapperContentButton : public UCommonButtonLegacy, public IFortBangWrapperContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="BangWrapperContentButton")
	void FinishTutorialCallout();

};

