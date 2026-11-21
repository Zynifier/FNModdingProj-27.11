// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/MinigameWidgetBase.h"
#include "MinigameHUD_SpectatorGameTimer.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, MinimalAPI)
class UMinigameHUD_SpectatorGameTimer : public UMinigameWidgetBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Time;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Centiseconds;

};

