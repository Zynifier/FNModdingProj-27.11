// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Common/FortTextButton.h"
#include "AthenaItemShopRefreshTimerButton.generated.h"

class UFortEventDateTimeTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaItemShopRefreshTimerButton : public UFortTextButton
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventDateTimeTextBlock> TimerText;

};

