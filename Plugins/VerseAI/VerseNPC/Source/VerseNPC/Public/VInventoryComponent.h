// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "VInventoryComponent.generated.h"

class AFortInventory;
class AFortPawn;
class UBlackboardComponent;

UCLASS(ClassGroup=("Fortnite"))
class VERSENPC_API UInventoryComponentBase : public UEntityComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortInventory> CachedFortInventory;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> CachedFortPawn;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBlackboardComponent> CachedBlackboardComponent;

};

