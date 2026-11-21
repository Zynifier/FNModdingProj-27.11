// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ReticleExtensions/FortWeaponReticleExtensionWidgetBase.h"
#include "FortPaddleGingerReticleExtensionWidget.generated.h"

class UFortKeybindWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPaddleGingerReticleExtensionWidget : public UFortWeaponReticleExtensionWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPropActivationChanged(const bool Activated);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPropIndexChanged(const FText& CategoryText, int32 PropIndex, int32 MaxPropCount, int32 CategoryIndex, int32 MaxCategoryCount);

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind_ActivateAction;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind_CycleCategoryAction;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind_CyclePropAction;

};

