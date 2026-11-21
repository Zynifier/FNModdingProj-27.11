// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/GasDebuggerCommandListener.h"
#include "GasDebuggerCommandComponent.generated.h"

UCLASS(ClassGroup=("GAS", "Debugger"), meta=(BlueprintSpawnableComponent))
class GASDEBUGGER_API UGasDebuggerCommandComponent : public UActorComponent, public IGasDebuggerCommandListener
{
	GENERATED_BODY()

private:
	UFUNCTION(Server, Reliable)
	void ServerOpenGasDebugger();

};

