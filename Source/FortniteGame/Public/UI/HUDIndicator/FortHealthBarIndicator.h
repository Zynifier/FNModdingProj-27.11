// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortSlateHUDIndicator.h"
#include "FortHealthBarIndicator.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_RetVal(float, FGetHealthPercent);

UCLASS()
class UFortHealthBarIndicator : public UFortSlateHUDIndicator
{
	GENERATED_BODY()

};

