// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/PersistenceFrameworkSaveData_ContainerVersion.h"
#include "PersistenceFramework/PersistenceFrameworkServiceData.h"
#include "PersistenceFramework/PersistenceFrameworkServiceWrapper.h"
#include "PFWExample_ServiceWrapper.generated.h"

USTRUCT()
struct FORTNITEGAME_API FPFWExample_ServiceWrapper_ContainerLocation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FPersistenceFrameworkSaveData_ContainerVersion Version;

	UPROPERTY()
	FString Root;

};

USTRUCT()
struct FPFWExample_ServiceWrapper_Settings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PFWExample_ServiceWrapper_Settings")
	FString Setting;

};

UCLASS()
class FORTNITEGAME_API UPFWExample_ServiceWrapper : public UPersistenceFrameworkServiceWrapper
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FPFWExample_ServiceWrapper_Settings Setting;

	UPROPERTY()
	FString Directory;

};

UCLASS()
class UPFWExample_ServiceWrapper_ServiceDataContainer : public UPersistenceFrameworkServiceDataContainer
{
	GENERATED_BODY()

};

UCLASS()
class UPFWExample_ServiceWrapper_ServiceDataModule : public UPersistenceFrameworkServiceDataModule
{
	GENERATED_BODY()

};

UCLASS()
class UPFWExample_ServiceWrapper_ServiceDataRootArea : public UPersistenceFrameworkServiceDataRootArea
{
	GENERATED_BODY()

};

UCLASS()
class UPFWExample_ServiceWrapper_ServiceDataRootAreaPlayer : public UPFWExample_ServiceWrapper_ServiceDataRootArea
{
	GENERATED_BODY()

};

UCLASS()
class UPFWExample_ServiceWrapper_ServiceDataRootAreaWorldForPlayer : public UPFWExample_ServiceWrapper_ServiceDataRootArea
{
	GENERATED_BODY()

};

UCLASS()
class UPFWExample_ServiceWrapper_ServiceDataRootAreaWorldPart : public UPFWExample_ServiceWrapper_ServiceDataRootArea
{
	GENERATED_BODY()

};

