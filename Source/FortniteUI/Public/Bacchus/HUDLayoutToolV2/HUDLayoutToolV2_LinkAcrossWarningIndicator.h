// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/MathFwd.h"
#include "HUDLayoutToolV2_LinkAcrossWarningIndicator.generated.h"

class UHUDLayoutToolV2_TooltipLayer;

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_LinkAcrossWarningIndicator : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_LinkAcrossWarningIndicator")
	FVector2D TooltipOffset;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_LinkAcrossWarningIndicator")
	FVector2D TooltipAllignment;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_LinkAcrossWarningIndicator")
	FText WarningMessage;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_TooltipLayer> TooltipLayer;

};

