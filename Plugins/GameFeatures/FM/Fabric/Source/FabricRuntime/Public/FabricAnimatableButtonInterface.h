// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricAnimatableButtonInterface.generated.h"

UINTERFACE(BlueprintType)
class FABRICRUNTIME_API UFabricAnimatableButtonInterface : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricAnimatableButtonInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PlayCloseAnimation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PlayOpenAnimation();

};

