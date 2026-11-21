// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/Widgets/FortSettingsListEntry.h"
#include "HUDLayoutToolV2SettingsListEntry_Scalar.generated.h"

class UHUDLayoutToolV2_Button;

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UHUDLayoutToolV2SettingsListEntry_Scalar : public UFortSettingsListEntrySetting_Scalar
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_DecreaseValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_IncreaseValue;

};

