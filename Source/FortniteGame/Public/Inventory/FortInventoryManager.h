// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortInventoryManager.generated.h"

class UVkPersistenceManager;

UCLASS(Config=Engine, MinimalAPI)
class UFortInventoryManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UVkPersistenceManager> PersistenceManager;

	UPROPERTY(Config)
	FString VkProjectId;

};

