// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWeakPointProviderInterface.generated.h"

class AFortPlayerController;

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortWeakPointProviderInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortWeakPointProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	float GetWeakSpotEnabledTimeout(AFortPlayerController* Controller) const;

};

