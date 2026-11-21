// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Bacchus/LayoutProfile/FortMobileHUDLayoutProfile.h"
#include "FortMobileCustomizableHUD.generated.h"

class UFortMobileHUDLayer;
class UFortMobileHUDWidgetRegistry;

UCLASS(meta=(DisableNativeTick))
class UFortMobileCustomizableHUD : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Registry", meta=(DisplayName="Base HUD Widget Registry"))
	TObjectPtr<UFortMobileHUDWidgetRegistry> BaseHUDWidgetRegistry;

	UPROPERTY(Transient)
	TObjectPtr<UFortMobileHUDWidgetRegistry> HUDWidgetRegistry;

	UPROPERTY(Transient)
	FFortMobileHUDLayoutProfile LayoutProfile;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMobileHUDLayer> HUDLayer_HUDWidgets;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Editor", meta=(Categories="HUDLayout.Context"))
	FGameplayTagContainer PreviewGameContextTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Editor")
	FGameplayTag PreviewLayoutProfilePresetTag;
#endif

};

