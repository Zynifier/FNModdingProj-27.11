// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerInput.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Bacchus/FortMobileActionButtonInterface.h"
#include "Bacchus/FortMobileHUDElement.h"
#include "FortMobileActionButton.generated.h"

class UFortMobileActionButtonBehavior;
class UImage;
class UOverlay;
class USizeBox;

UCLASS(Abstract)
class UFortMobileActionButton : public UFortMobileHUDElement, public IFortMobileActionButtonInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleInstanceOnly, Transient, Category="FortMobileActionButton")
	TObjectPtr<UFortMobileActionButtonBehavior> ButtonBehavior;

private:
	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag IconSizePropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag ClickthroughPropertyTag;

	UPROPERTY(EditAnywhere, Category="Display", meta=(sRGB="true"))
	FLinearColor PressedColor;

	UPROPERTY(EditAnywhere, Category="Display", meta=(sRGB="true"))
	FLinearColor ReleasedColor;

	UPROPERTY(EditAnywhere, Category="Display", meta=(sRGB="true"))
	FLinearColor DisabledColor;

	UPROPERTY()
	TArray<FInputActionKeyMapping> InputActionKeyMappings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_HitboxSize;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_VisualSize;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ButtonContents;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Background;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

};

