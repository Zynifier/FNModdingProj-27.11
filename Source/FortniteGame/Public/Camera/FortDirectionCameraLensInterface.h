// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "FortDirectionCameraLensInterface.generated.h"

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UFortDirectionCameraLensInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortDirectionCameraLensInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void SetStrength(float InStrength);

	UFUNCTION(BlueprintCallable)
	virtual void SetTint(const FLinearColor& Color);

};

