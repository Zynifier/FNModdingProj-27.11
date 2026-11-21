// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "BacchusCloseButton.generated.h"

UCLASS(meta=(DisableNativeTick))
class UBacchusCloseButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="BacchusCloseButton")
	bool bIgnorePlatform;

};

