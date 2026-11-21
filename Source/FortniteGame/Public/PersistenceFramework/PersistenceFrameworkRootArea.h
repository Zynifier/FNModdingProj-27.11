// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceFrameworkRootArea.generated.h"

class UObject;
class UPersistenceFrameworkActionQueue;
class UPersistenceFrameworkModule;
class UPersistenceFrameworkServiceData;

USTRUCT()
struct FPersistenceFrameworkRootArea_NameToModuleMap
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FName, UPersistenceFrameworkModule*> Map;

};

UCLASS(Abstract)
class FORTNITEGAME_API UPersistenceFrameworkRootArea : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer GameplayTagContainer;

protected:
	UPROPERTY()
	TMap<UClass*, UPersistenceFrameworkModule*> ClassToModule;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkServiceData> ServiceData;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> MakeReadyForPersistenceProcess;

	UPROPERTY()
	bool bMakeReadyForPersistenceProcessFailedOnLastAttempt;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> DeinitProcess;

	UPROPERTY()
	FString Description;

	UPROPERTY()
	FName PersistentName;

};

