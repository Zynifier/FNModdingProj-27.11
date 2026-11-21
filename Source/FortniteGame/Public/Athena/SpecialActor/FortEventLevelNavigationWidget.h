// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "CommonUserWidget.h"
#include "Athena/SpecialActor/FortEventLevelTypes.h"
#include "FortEventLevelNavigationWidget.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventLevelNavigationWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleInputMethodChanged(ECommonInputType CurrentInputType);

	UFUNCTION(BlueprintImplementableEvent)
	void SetBangState(bool bShowBang);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectHoverBegin(const FNavWidgetSettings& NavWidgetSettings);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectHoverEnd();

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Navigation;

};

