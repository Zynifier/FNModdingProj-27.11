// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/HUDLayoutToolV2/FortMobileHUDElementProxy.h"
#include "HUDLayoutToolV2_KeyButtonProxy.generated.h"

class UFortKeybindWidget;

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_KeyButtonProxy : public UFortMobileHUDElementProxy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindWidget;

};

