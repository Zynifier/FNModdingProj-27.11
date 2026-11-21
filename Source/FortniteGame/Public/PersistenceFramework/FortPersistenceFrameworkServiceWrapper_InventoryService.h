// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/PersistenceFrameworkServiceData.h"
#include "PersistenceFramework/PersistenceFrameworkServiceWrapper.h"
#include "FortPersistenceFrameworkServiceWrapper_InventoryService.generated.h"

class UVkPersistence;
class UVkPersistenceManager;

UENUM()
enum class EStateOfGetPersistence : uint8
{
	/** The operation not started yet */
	NotStarted = 0,
	/** The operation failed */
	Failed = 1,
	/** The operation will retry after some time */
	WaitingToRetry = 2,
	/** The operation Succeeded */
	Success = 3,
	/** The operation is not yet done */
	InProgress = 4,
};

USTRUCT()
struct FORTNITEGAME_API FFortPersistenceFrameworkContainerLocation_InventoryService
{
	GENERATED_BODY()

};

UCLASS()
class UFortPersistenceFrameworkInventoryServiceDataContainer : public UPersistenceFrameworkServiceDataContainer
{
	GENERATED_BODY()

};

UCLASS()
class UFortPersistenceFrameworkInventoryServiceDataModule : public UPersistenceFrameworkServiceDataModule
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class UFortPersistenceFrameworkInventoryServiceDataRootArea : public UPersistenceFrameworkServiceDataRootArea
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UVkPersistence> Persistence;

};

UCLASS()
class UFortPersistenceFrameworkInventoryServiceDataRootAreaPlayer : public UFortPersistenceFrameworkInventoryServiceDataRootArea
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 RetryCount;

	UPROPERTY()
	float RetryTime;

	UPROPERTY()
	EStateOfGetPersistence StateOfGetPersistence;

	UPROPERTY()
	bool bPersistenceLogoutInProgress;

	UPROPERTY()
	float ForLogging_WaitStartTime;

	UPROPERTY()
	float ForLogging_NextLogTime;

	UPROPERTY()
	bool bForLogging_LogWaiting;

};

UCLASS(Abstract)
class UFortPersistenceFrameworkInventoryServiceDataRootArea_HACK_REUSE_RootAreaPlayer : public UFortPersistenceFrameworkInventoryServiceDataRootArea
{
	GENERATED_BODY()

};

UCLASS()
class UFortPersistenceFrameworkInventoryServiceDataRootAreaWorldForPlayer : public UFortPersistenceFrameworkInventoryServiceDataRootArea_HACK_REUSE_RootAreaPlayer
{
	GENERATED_BODY()

};

UCLASS()
class UFortPersistenceFrameworkInventoryServiceDataRootAreaWorldPart : public UFortPersistenceFrameworkInventoryServiceDataRootArea_HACK_REUSE_RootAreaPlayer
{
	GENERATED_BODY()

};

UCLASS()
class FORTNITEGAME_API UFortPersistenceFrameworkServiceWrapper_InventoryService : public UPersistenceFrameworkServiceWrapper
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UVkPersistenceManager> VkPersistenceManager;

};

