// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/FortInputSettingBase.h"
#include "FortEnhancedInputSetting.generated.h"

class UEnhancedInputUserSettings;

UCLASS()
class FORTNITEUI_API UFortEnhancedInputSetting : public UFortInputSettingBase
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleSettingsChanged(UEnhancedInputUserSettings* InputUserSettings);

};

