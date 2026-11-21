// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaTemperatureBase.generated.h"

class UTextBlock;

UCLASS(meta=(DisableNativeTick))
class UAthenaTemperatureBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Temperature;

private:
	UFUNCTION(BlueprintCallable, Category="Timer")
	void StartTimer();

	UFUNCTION(BlueprintCallable, Category="Timer")
	void StopTimer();

};

