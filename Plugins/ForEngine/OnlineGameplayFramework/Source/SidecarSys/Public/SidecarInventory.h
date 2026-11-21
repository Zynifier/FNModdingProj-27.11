// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceInventoryRequestInterface.h"
#include "SidecarInventory.generated.h"

UCLASS(Config=Engine)
class SIDECARSYS_API USidecarInventorySys : public UObject, public IPersistenceInventoryRequestInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	FString InventoryDownloadUrl;

	UPROPERTY(Config)
	FString InventoryLockUrl;

	UPROPERTY(Config)
	FString ItemUpdateUrl;

};

