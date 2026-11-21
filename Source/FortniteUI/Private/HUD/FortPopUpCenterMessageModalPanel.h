// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortPopUpCenterMessageModalPanel.generated.h"

class UCommonUserWidget;

UCLASS(meta=(DisableNativeTick))
class UFortPopUpCenterMessageModalPanel : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPopUpCenterMessageModalPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> Button_Leave;

};

