// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/CobaltWidgetBase.h"
#include "CobaltPreRoundWidgetBase.generated.h"

UCLASS()
class UCobaltPreRoundWidgetBase : public UCobaltWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandlePreRoundWidgetInfo_BP(int32 CurrentActiveRound, const FText& RoundName, const FText& POIName);

	UFUNCTION()
	void HandleUpdatePreRoundWidgetVisibility(bool bNewVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleUpdatePreRoundWidgetVisibility_BP(bool bNewVisibility);

};

