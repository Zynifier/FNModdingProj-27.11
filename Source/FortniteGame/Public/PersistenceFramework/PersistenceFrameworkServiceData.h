// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceFrameworkServiceData.generated.h"

class UPersistenceFrameworkActionQueue;
class UPersistenceFrameworkContainer;
class UPersistenceFrameworkModule;
class UPersistenceFrameworkRootArea;

UCLASS(Abstract)
class FORTNITEGAME_API UPersistenceFrameworkServiceData : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> MakeReadyForPersistenceProcess;

	UPROPERTY()
	bool bMakeReadyForPersistenceProcessFailedOnLastAttempt;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> DeinitProcess;

	UPROPERTY()
	FString Description;

};

UCLASS(Abstract)
class FORTNITEGAME_API UPersistenceFrameworkServiceDataContainer : public UPersistenceFrameworkServiceData
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkContainer> Container;

};

UCLASS(Abstract)
class FORTNITEGAME_API UPersistenceFrameworkServiceDataModule : public UPersistenceFrameworkServiceData
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkModule> Module;

};

UCLASS(Abstract)
class FORTNITEGAME_API UPersistenceFrameworkServiceDataRootArea : public UPersistenceFrameworkServiceData
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkRootArea> RootArea;

	UPROPERTY()
	bool bLoggedOut;

};

