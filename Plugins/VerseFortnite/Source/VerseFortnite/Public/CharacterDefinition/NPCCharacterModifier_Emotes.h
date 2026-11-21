// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterDefinition/NPCCharacterModifier.h"
#include "NPCCharacterModifier_Emotes.generated.h"

class UAthenaDanceItemDefinition;

USTRUCT(BlueprintType)
struct FCharacterModifierEmote
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Item")
	TSoftObjectPtr<UAthenaDanceItemDefinition> EmoteDefinition;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UNPCCharacterModifier_Emotes : public UNPCCharacterModifier
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Emotes", meta=(AllowPrivateAccess="true"))
	TArray<FCharacterModifierEmote> Emotes;

};

