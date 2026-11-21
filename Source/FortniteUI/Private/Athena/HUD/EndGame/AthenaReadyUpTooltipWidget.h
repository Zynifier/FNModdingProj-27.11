// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaReadyUpTooltipWidget.generated.h"

class UAthenaReadyUpTooltipTickWidget;

UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UAthenaReadyUpTooltipWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandlePartyWidgetReadinessChanged(bool bIsReadied);

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaReadyUpTooltipTickWidget>> PartyWidgets;

};

