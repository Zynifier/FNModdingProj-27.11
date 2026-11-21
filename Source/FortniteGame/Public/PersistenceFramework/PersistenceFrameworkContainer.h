// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceFramework/PersistenceFrameworkPersistentName.h"
#include "PersistenceFramework/PersistenceFrameworkSaveData_ContainerVersion.h"
#include "PersistenceFrameworkContainer.generated.h"

class UPersistenceFrameworkActionQueue;
class UPersistenceFrameworkActionQueueContainerBackendRequests;
class UPersistenceFrameworkServiceData;

UCLASS(Abstract)
class FORTNITEGAME_API UPersistenceFrameworkContainer : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer GameplayTagContainer;

protected:
	UPROPERTY()
	FPersistenceFrameworkSaveData_ContainerVersion RestoreVersionInfo;

	UPROPERTY()
	FPersistenceFrameworkSaveData_VersionTable SupportedVersionsTable;

	UPROPERTY()
	uint64 RestoreAttemptCount;

	UPROPERTY()
	uint64 SaveAttemptCount;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkServiceData> ServiceData;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueueContainerBackendRequests> BackendRequestsQueue;

	UPROPERTY()
	FName PersistentClassName;

	UPROPERTY()
	FPersistenceFrameworkPersistentName PersistentName;

	UPROPERTY()
	FString Description;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> MakeReadyForPersistenceProcess;

	UPROPERTY()
	bool bMakeReadyForPersistenceProcessFailedOnLastAttempt;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> DeinitProcess;

};

