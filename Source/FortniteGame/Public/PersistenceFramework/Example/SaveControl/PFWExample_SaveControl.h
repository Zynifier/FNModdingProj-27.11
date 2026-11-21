// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/PersistenceFrameworkFilteredListContainer.h"
#include "PersistenceFramework/PersistenceFrameworkSaveTriggers.h"
#include "PFWExample_SaveControl.generated.h"

UCLASS()
class FORTNITEGAME_API UPFWExample_FilteredListContainer : public UPersistenceFrameworkFilteredListContainer
{
	GENERATED_BODY()

};

UCLASS()
class UPFWExample_Trigger : public UPersistenceFrameworkSaveTrigger_Manual
{
	GENERATED_BODY()

};

