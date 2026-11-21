// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterDefinition/NPCCharacterModifier.h"
#include "NPCCharacterModifier_CosmeticSpawn.generated.h"

class AActor;
class UAthenaCharacterItemDefinition;

UENUM()
enum class ECharacterCosmeticType : uint8
{
	// Cosmetic is defined by a CID

	CharacterItemDefinition = 0,
	// Cosmetic is defined by the components inside this Character Blueprint

	CharacterBlueprint = 1,
};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisplayName="NPC Character Cosmetic Spawn Modifier"))
class UNPCCharacterModifier_CosmeticSpawn : public UNPCCharacterModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UAthenaCharacterItemDefinition> GetCharacterCosmetic() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cosmetic")
	ECharacterCosmeticType CosmeticType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Cosmetic", meta=(EditCondition="CosmeticType == ECharacterCosmeticType::CharacterItemDefinition"))
	TSoftObjectPtr<UAthenaCharacterItemDefinition> CharacterCosmetic;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Cosmetic", meta=(EditCondition="CosmeticType == ECharacterCosmeticType::CharacterItemDefinition"))
	FString CharacterCosmeticAssetId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cosmetic", meta=(EditCondition="CosmeticType == ECharacterCosmeticType::CharacterItemDefinition"))
	bool bEnableCharacterCosmeticRetargeting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cosmetic", meta=(EditCondition="bEnableCharacterCosmeticRetargeting || CosmeticType == ECharacterCosmeticType::CharacterBlueprint", MetaClass="/Script/Engine.Actor"))
	TSoftClassPtr<AActor> CharacterBlueprint;

};

