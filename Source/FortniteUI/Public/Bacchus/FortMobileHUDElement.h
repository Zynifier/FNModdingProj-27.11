// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortHUDElementWidget.h"
#include "FortMobileHUDElement.generated.h"

class UScaleBox;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortMobileHUDElement : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SizePropertyTag;

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDElement")
	int32 ForcedZOrder;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_HUDWidgetScale;

};

