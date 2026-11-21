// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/PersistenceFrameworkServiceSettingsBase.h"
#include "PersistenceFrameworkServiceSettings_InventoryService.generated.h"

UCLASS()
class FORTNITEGAME_API UPersistenceFrameworkServiceSettings_InventoryService : public UPersistenceFrameworkServiceSettingsBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PersistenceFrameworkServiceSettings_InventoryService")
	FString VkProjectId;

};

