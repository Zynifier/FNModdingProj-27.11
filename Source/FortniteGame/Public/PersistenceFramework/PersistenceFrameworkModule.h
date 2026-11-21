// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceFrameworkModule.generated.h"

class UPersistenceFrameworkActionQueue;
class UPersistenceFrameworkContainer;
class UPersistenceFrameworkServiceData;

USTRUCT()
struct FPersistenceFrameworkModule_NameToContainerMap
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FName, UPersistenceFrameworkContainer*> Map;

};

UCLASS(Abstract)
class FORTNITEGAME_API UPersistenceFrameworkModule : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer GameplayTagContainer;

protected:
	UPROPERTY()
	TMap<FName, TObjectPtr<UPersistenceFrameworkContainer>> Containers;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkServiceData> ServiceData;

	UPROPERTY()
	FString PersistentName;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> MakeReadyForPersistenceProcess;

	UPROPERTY()
	bool bMakeReadyForPersistenceProcessFailedOnLastAttempt;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> DeinitProcess;

	UPROPERTY()
	FString Description;

};

