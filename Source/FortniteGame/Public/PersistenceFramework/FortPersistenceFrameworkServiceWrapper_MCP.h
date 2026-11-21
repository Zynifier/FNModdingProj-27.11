// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceFramework/PersistenceFrameworkServiceWrapper.h"
#include "FortPersistenceFrameworkServiceWrapper_MCP.generated.h"

class UFortPersistenceFrameworkContainerData_MCP;
class UFortPersistenceFrameworkRootAreaPlayer;
class UFortPersistenceFrameworkRootAreaPlayerData_MCP;
class UFortPersistenceFrameworkServiceWrapper_MCP;

USTRUCT()
struct FORTNITEGAME_API FFortPersistenceFrameworkContainerLocation_MCP
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortPersistenceFrameworkContainerData_MCP> ContainerData;

};

UCLASS()
class FORTNITEGAME_API UFortPersistenceFrameworkContainerData_MCP : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortPersistenceFrameworkRootAreaPlayerData_MCP> RootAreaPlayerData;

};

UCLASS()
class FORTNITEGAME_API UFortPersistenceFrameworkRootAreaPlayerData_MCP : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortPersistenceFrameworkRootAreaPlayer> RootAreaPlayer;

	UPROPERTY()
	TObjectPtr<UFortPersistenceFrameworkServiceWrapper_MCP> ServiceWrapper;

};

UCLASS()
class FORTNITEGAME_API UFortPersistenceFrameworkServiceWrapper_MCP : public UPersistenceFrameworkServiceWrapper
{
	GENERATED_BODY()

};

