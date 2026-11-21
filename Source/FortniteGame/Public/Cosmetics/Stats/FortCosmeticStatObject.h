// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCosmeticStatObject.generated.h"

class AFortPlayerController;
class UFortCosmeticStatSubsystem;

UCLASS(Abstract, MinimalAPI)
class UFortCosmeticStatObject : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticStatObject")
	FName StatName;

private:
	UPROPERTY(Transient)
	TMap<TWeakObjectPtr<AFortPlayerController>, int32> CachedStatValues;

	UPROPERTY(Transient)
	TObjectPtr<UFortCosmeticStatSubsystem> OwningSubsystem;

};

