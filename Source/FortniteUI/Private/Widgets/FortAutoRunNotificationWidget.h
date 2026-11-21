// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortAutoRunNotificationWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortAutoRunNotificationWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAutoRunEnabled(bool bAutoRunEnabled);

private:
	UPROPERTY(EditDefaultsOnly, Category="Auto Run")
	float TimeToShowWidget;

};

