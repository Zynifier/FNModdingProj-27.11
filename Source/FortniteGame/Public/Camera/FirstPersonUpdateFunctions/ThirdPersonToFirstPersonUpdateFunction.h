// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "ThirdPersonToFirstPersonUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UThirdPersonToFirstPersonUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ThirdPersonToFirstPersonUpdateFunction")
	bool bAllowOpticToOverrideEyeRelief;

};

