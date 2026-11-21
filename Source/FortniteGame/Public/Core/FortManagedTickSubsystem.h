// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortManagedTickSubsystem.generated.h"

class UObject;

UCLASS(Abstract, MinimalAPI)
class UFortManagedTickSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> ActiveTickList;

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> AllEnabledObjects;

	UPROPERTY(Transient)
	TSet<TObjectPtr<UObject>> AllRegisteredObjects;

};

UCLASS(Abstract, MinimalAPI)
class UFortManagedActorTickSubsystem : public UFortManagedTickSubsystem
{
	GENERATED_BODY()

};

UCLASS(Abstract, MinimalAPI)
class UFortManagedComponentTickSubsystem : public UFortManagedTickSubsystem
{
	GENERATED_BODY()

};

