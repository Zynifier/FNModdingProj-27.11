// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceFrameworkSaveTriggers.generated.h"

UCLASS(Abstract)
class UPersistenceFrameworkSaveTrigger : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class UPersistenceFrameworkSaveTrigger_Manual : public UPersistenceFrameworkSaveTrigger
{
	GENERATED_BODY()

};

UCLASS()
class UPersistenceFrameworkSaveTrigger_Timed : public UPersistenceFrameworkSaveTrigger
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	float SecondsBetweenTicks;

	UPROPERTY()
	float RemainingSeconds;

};

