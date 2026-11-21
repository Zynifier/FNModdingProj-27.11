// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "FortHUDElementWidget.h"
#include "FortInputBlockedWarning.generated.h"

UCLASS(meta=(DisableNativeTick))
class UFortInputBlockedWarning : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInputFiltered(ECommonInputType AttemptedInputType);

};

