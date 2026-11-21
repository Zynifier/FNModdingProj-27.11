// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAutoFireTargetInterface.h"
#include "FortLockOnTargetInterface.h"
#include "FortStaticMeshActor.h"
#include "FortAthenaTutorialShootingAutofireTarget.generated.h"

UCLASS(HideCategories=("Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaTutorialShootingAutofireTarget : public AFortStaticMeshActor, public IFortLockOnTargetInterface, public IFortAutoFireTargetInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AutoFire")
	bool bIsAimAssistingTarget;

};

