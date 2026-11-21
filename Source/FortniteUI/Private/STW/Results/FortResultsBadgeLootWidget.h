// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserWidget.h"
#include "FortResultsBadgeLootWidget.generated.h"

class UCommonBorder;

UCLASS(BlueprintType, Blueprintable)
class UFortResultsBadgeLootWidget : public UFortUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void RecheckLeecherStatus();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_LeechWarning;

};

