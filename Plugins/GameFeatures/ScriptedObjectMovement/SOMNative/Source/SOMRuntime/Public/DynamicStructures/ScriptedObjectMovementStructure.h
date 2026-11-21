// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScriptedObjectMovementStructure.generated.h"

class UFortScriptedObjectMovement_Slot;
class UFortScriptedObjectMovement_SlotDefinition;

UCLASS(BlueprintType, Blueprintable)
class AFortScriptedObjectMovement_Structure : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortScriptedObjectMovement_Slot>> CachedObjectSlots;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortScriptedObjectMovement_SlotDefinition>> CachedSlotDefinitions;

};

