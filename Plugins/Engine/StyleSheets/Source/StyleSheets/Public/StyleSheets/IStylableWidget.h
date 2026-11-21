// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IStylableWidget.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UStylableWidget : public UInterface
{
	GENERATED_BODY()
};

class IStylableWidget
{
	GENERATED_BODY()

protected:
	/** Called if WBP implements this interface. */
	UFUNCTION(BlueprintImplementableEvent, Category="StyleSheets", meta=(DisplayName="On Widget Styled"))
	void BP_OnWidgetStyled();

};

