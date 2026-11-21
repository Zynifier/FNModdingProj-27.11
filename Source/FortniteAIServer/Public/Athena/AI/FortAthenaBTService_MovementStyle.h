// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FortMovementEnums.h"
#include "FortAthenaBTService_MovementStyle.generated.h"

UCLASS(HideCategories=("Service"))
class UFortAthenaBTService_MovementStyle : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<EFortMovementStyle::Type> MovementStyle;

};

