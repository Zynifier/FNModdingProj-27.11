// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/FortMobileHUDElement.h"
#include "FortMobileKeyButton.generated.h"

class UFortKeybindWidget;
class UFortMobileKeyButtonBehavior;

UCLASS(meta=(DisableNativeTick))
class UFortMobileKeyButton : public UFortMobileHUDElement
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindWidget;

	UPROPERTY(Transient)
	TObjectPtr<UFortMobileKeyButtonBehavior> Behavior;

};

