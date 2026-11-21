// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceFrameworkServiceWrapper.generated.h"

class UPersistenceFrameworkActionQueue;
class UPersistenceFrameworkRootArea;

UCLASS(Abstract)
class FORTNITEGAME_API UPersistenceFrameworkServiceWrapper : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer GameplayTagContainer;

private:
	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> MakeReadyForPersistenceProcess;

	UPROPERTY()
	bool bMakeReadyForPersistenceProcessFailedOnLastAttempt;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> DeinitProcess;

	UPROPERTY()
	TArray<TObjectPtr<UPersistenceFrameworkRootArea>> RootAreas;

};

