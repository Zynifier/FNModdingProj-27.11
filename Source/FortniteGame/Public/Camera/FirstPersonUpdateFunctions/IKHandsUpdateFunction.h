// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "IKHandsUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UIKHandsUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="IKHandsUpdateFunction")
	FVector LeftShoulderCameraSpaceOffset;

	UPROPERTY(EditAnywhere, Category="IKHandsUpdateFunction")
	FVector RightShoulderCameraSpaceOffset;

	UPROPERTY(EditDefaultsOnly, Category="IKHandsUpdateFunction")
	FName FirstPersonAnimGraphTag;

};

