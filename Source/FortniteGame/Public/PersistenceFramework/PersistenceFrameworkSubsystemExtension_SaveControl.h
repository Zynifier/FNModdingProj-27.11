// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/PersistenceFrameworkSubsystemExtension.h"
#include "PersistenceFrameworkSubsystemExtension_SaveControl.generated.h"

class UPersistenceFrameworkFilteredListContainer;
class UPersistenceFrameworkSaveTrigger;

USTRUCT()
struct FPersistenceFrameworkSaveControl
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkFilteredListContainer> FilteredList;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkSaveTrigger> SaveTrigger;

};

UCLASS()
class FORTNITEGAME_API UPersistenceFrameworkSubsystemExtension_SaveControl : public UPersistenceFrameworkSubsystemExtension
{
	GENERATED_BODY()

};

