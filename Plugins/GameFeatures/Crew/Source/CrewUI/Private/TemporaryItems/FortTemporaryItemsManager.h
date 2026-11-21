// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortTemporaryItemsManager.generated.h"

UCLASS()
class UFortTemporaryItemsManager : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnTemporaryItemsStateChanged();

};

