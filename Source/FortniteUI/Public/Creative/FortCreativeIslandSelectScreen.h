// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortCreativeIslandSelectScreen.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonBase;
class UFortCreativeTabGroup;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandSelectScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCreativeIslandSelectScreen(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION()
	virtual void HandleTabChanged(int32 TabIndex);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeTabGroup> Tab_Group;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeIslandSelectScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Widget_Switcher;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseMobile;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Cancel;

};

