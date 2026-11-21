// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaGenericHUDTimerWidgetBase.generated.h"

class UTextBlock;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaGenericHUDTimerWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TimeText;

};

