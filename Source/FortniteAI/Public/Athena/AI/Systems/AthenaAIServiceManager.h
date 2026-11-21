// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AISubsystem.h"
#include "AthenaAIServiceManager.generated.h"

class UAthenaAIService;

UCLASS(MinimalAPI)
class UAthenaAIServiceManager : public UAISubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaAIService>> AIServices;

};

