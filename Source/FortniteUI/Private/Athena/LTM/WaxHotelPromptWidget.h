// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "WaxHotelPromptWidget.generated.h"

UCLASS()
class UWaxHotelPromptWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void CloseWidget();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OpenWidget();

};

