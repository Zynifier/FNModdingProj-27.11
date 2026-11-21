// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortBT/FortBTService_ContextOverride.h"
#include "FortMovementEnums.h"
#include "FortBTContext_MoveUrgency.generated.h"

UCLASS(HideCategories=("Service"))
class UFortBTContext_MoveUrgency : public UFortBTService_ContextOverride
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Context")
	TEnumAsByte<EFortMovementUrgency::Type> MoveUrgency;

};

