// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "FortAutoFireTargetInterface.h"
#include "FortLockOnTargetInterface.h"
#include "FortAthenaTutorialShootingTarget.generated.h"

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortAthenaTutorialShootingTarget : public ABuildingProp, public IFortLockOnTargetInterface, public IFortAutoFireTargetInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AutoFire")
	bool bIsAimAssistingTarget;

};

