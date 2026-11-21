// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/FortMobileActionButtonInterface.h"
#include "Bacchus/HUDLayoutToolV2/FortMobileHUDElementProxy.h"
#include "HUDLayoutToolV2_ActionButtonProxy.generated.h"

class UImage;
class USizeBox;

UCLASS(Abstract)
class UHUDLayoutToolV2_ActionButtonProxy : public UFortMobileHUDElementProxy, public IFortMobileActionButtonInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag IconSizePropertyTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_HitboxSize;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_VisualSize;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Background;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

};

