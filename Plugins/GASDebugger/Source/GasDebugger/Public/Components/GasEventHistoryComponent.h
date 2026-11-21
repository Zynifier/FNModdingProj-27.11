// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/GasEventHistoryProvider.h"
#include "GasEventHistoryComponent.generated.h"

UCLASS(ClassGroup=("GAS", "Debugger"), meta=(BlueprintSpawnableComponent))
class GASDEBUGGER_API UGasEventHistoryComponent : public UActorComponent, public IGasEventHistoryProvider
{
	GENERATED_BODY()

};

