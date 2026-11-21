// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GasDebuggerLibrary.generated.h"

class APlayerController;

UCLASS()
class GASDEBUGGER_API UGasDebuggerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="GAS Debugger Library")
	static void ServerOnly_OpenGasDebugger(APlayerController* PlayerController);

};

