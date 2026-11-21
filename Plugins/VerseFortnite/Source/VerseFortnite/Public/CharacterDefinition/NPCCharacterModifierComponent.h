// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserOptionContainerComponent.h"
#include "NPCCharacterModifierComponent.generated.h"

class UNPCCharacterModifier;

UCLASS(MinimalAPI, HideCategories=("Activation", "Collision", "Components", "ComponentTick", "ComponentReplication", "Navigation", "Tags", "Replication", "Variable"), SparseClassDataType=UserOptionDefinitionContainer, meta=(BlueprintSpawnableComponent))
class UNPCCharacterModifiersComponent : public UFortUserOptionContainerComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, SaveGame, Instanced, Category="UserOptions")
	TArray<TObjectPtr<UNPCCharacterModifier>> Modifiers;

};

