// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "NPCCharacterType.generated.h"

class UNPCCharacterModifier;

UCLASS(Abstract, EditInlineNew, MinimalAPI, BlueprintType)
class UNPCCharacterType : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Type")
	FGameplayTag CharacterDefinitionTag;

	UPROPERTY(EditDefaultsOnly, NoClear, Category="Modifiers")
	TArray<TSoftClassPtr<UNPCCharacterModifier>> SupportedModifiers;

	UPROPERTY(EditDefaultsOnly, NoClear, Category="Modifiers")
	TArray<TSoftClassPtr<UNPCCharacterModifier>> DefaultModifiers;

};

