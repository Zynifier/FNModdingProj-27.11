// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HardcoreModifierStatusBar.generated.h"

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UHardcoreModifierStatusBar : public UCommonUserWidget
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="NumToPreview"))
	int32 NumToPreview;
#endif

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleUpdateActiveModifiers(int32 NumActiveModifiers);

};

