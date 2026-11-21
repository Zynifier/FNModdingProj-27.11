// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAppliedSwapItemAndVariantStateEnum.generated.h"

UENUM(BlueprintType)
enum class EFortAppliedSwapItemAndVariantState : uint8
{
	None = 0,
	Active = 1,
	Inactive = 2,
};

