// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortLockOnTargetInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortLockOnTargetInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortLockOnTargetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetLockOnTargetLocation() const;

};

