// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PFWCheatTestSetup.generated.h"

class UPersistenceFrameworkActionQueue;

UENUM()
enum class UPFWCheat_RootArea : uint8
{
	Player = 0,
	WorldForPlayer = 1,
	World = 2,
};

UCLASS(Abstract)
class FORTNITEGAME_API UPFWCheatTestSetup : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> SaveAndRestoreActionsQueue;

};

