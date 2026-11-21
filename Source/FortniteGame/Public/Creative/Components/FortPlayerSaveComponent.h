// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory/FortInventorySerializationTypes.h"
#include "Inventory/FortPersistenceTypes.h"
#include "FortPlayerSaveComponent.generated.h"

class UVkPersistenceManager;

USTRUCT()
struct FPersistenceDelegateHandle
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortPlayerSaveComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UVkPersistenceManager> PersistenceManager;

	UPROPERTY(Transient)
	FFortInventory_SaveEntrySettings AutoSaveEntrySettings;

	UPROPERTY(Transient)
	FSaveRestrictions SaveRestrictions;

	UPROPERTY(Transient)
	TArray<FPendingToApplyData> PendingToApplyData;

};

