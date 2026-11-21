// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GasDebuggerCommandListener.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class GASDEBUGGEREXTERNALS_API UGasDebuggerCommandListener : public UInterface
{
	GENERATED_BODY()
};

class GASDEBUGGEREXTERNALS_API IGasDebuggerCommandListener
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnGasDebuggerCommand();

};

