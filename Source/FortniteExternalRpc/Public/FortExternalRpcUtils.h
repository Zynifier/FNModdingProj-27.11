// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortExternalRpcUtils.generated.h"

class AFortPlayerController;
class UWorld;

UCLASS()
class UFortExternalRpcUtils : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UWorld* FindGameWorld();

	UFUNCTION(BlueprintCallable)
	static AFortPlayerController* FindPlayerController();

	UFUNCTION(BlueprintCallable)
	static bool TryExecuteConsoleCommand(const FString& CommandString, FString& OutError);

};

