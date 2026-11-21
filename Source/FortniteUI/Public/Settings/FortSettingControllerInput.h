// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/FortSettingValue.h"
#include "FortSettingControllerInput.generated.h"

UCLASS()
class UFortSettingControllerInput : public UFortSettingValue
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetKeyIndex() const;

};

