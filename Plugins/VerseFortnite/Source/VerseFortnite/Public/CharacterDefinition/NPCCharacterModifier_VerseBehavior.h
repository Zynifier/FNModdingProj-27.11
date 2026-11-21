// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterDefinition/NPCCharacterModifier_Behavior.h"
#include "NPCCharacterModifier_VerseBehavior.generated.h"

class UAIBehaviorScript;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisplayName="Verse Behavior", ShortTooltip="Allow scripting an AI Behavior through Verse."))
class UNPCCharacterModifier_VerseBehavior : public UNPCCharacterModifier_Behavior
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Behavior")
	TObjectPtr<UAIBehaviorScript> AIBehaviorScript;

};

