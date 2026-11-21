// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/FortSettingAction.h"
#include "Settings/FortSettingValueScalarDynamic.h"
#include "FortSettingAction_SafeZoneEditor.generated.h"

class UFortSettingValueScalarDynamic_SafeZoneValue;

UCLASS()
class UFortSettingAction_SafeZoneEditor : public UFortSettingAction
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortSettingValueScalarDynamic_SafeZoneValue> SafeZoneValueSetting;

};

UCLASS()
class UFortSettingValueScalarDynamic_SafeZoneValue : public UFortSettingValueScalarDynamic
{
	GENERATED_BODY()

};

