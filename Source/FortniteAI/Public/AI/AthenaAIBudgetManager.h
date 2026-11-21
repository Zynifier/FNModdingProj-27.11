// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AthenaAIBudgetManager.generated.h"

class UObject;

USTRUCT()
struct FAthenaMemoryBudgetInterfaces
{
	GENERATED_BODY()

};

UCLASS()
class UAthenaAIBudgetManager : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<TWeakObjectPtr<UObject>, FAthenaMemoryBudgetInterfaces> StaticallyRegisteredPawns;

};

