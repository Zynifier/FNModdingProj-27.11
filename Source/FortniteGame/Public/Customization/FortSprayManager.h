// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortSprayManager.generated.h"

class AFortSprayDecalInstance;

UCLASS()
class UFortSprayManager : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<AFortSprayDecalInstance>> RegisteredSprays;

};

