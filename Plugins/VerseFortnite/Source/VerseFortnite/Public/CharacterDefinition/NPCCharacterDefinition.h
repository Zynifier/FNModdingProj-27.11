// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/SoftObjectPath.h"
#include "AI/FortAIPawnCustomizationDefinition.h"
#include "NPCCharacterDefinition.generated.h"

class AActor;
class APawn;
class UAthenaCharacterItemDefinition;
class UFortAthenaAISpawnerDataComponentList;
class UNPCCharacterModifier;
class UNPCCharacterModifier_Behavior;
class UNPCCharacterType;
class UObject;
class USkeletalMesh;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterModifierModifiedDelegate, UNPCCharacterModifier*, Modifier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterTypeModifiedDelegate, UNPCCharacterType*, Type);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FCreateComponentListDelegate, UFortAthenaAISpawnerDataComponentList*, ComponentsList);

USTRUCT(BlueprintType)
struct FCharacterPreviewMesh
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CharacterPreviewMesh")
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CharacterPreviewMesh")
	FGameplayTagContainer MeshDescriptor;

};

UCLASS(MinimalAPI, BlueprintType, meta=(DisplayName="NPC Character Definition"))
class UNPCCharacterDefinition : public UFortAIPawnCustomizationDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponentList* CreateComponentList(UObject* Outer, const TArray<UNPCCharacterModifier*>& AdditionalModifiers, const bool bForPreview = false) const;

	UFUNCTION(BlueprintPure, Category="Preview", meta=(CallInEditor="true"))
	TSubclassOf<AActor> GetCharacterBlueprint(const TArray<UNPCCharacterModifier*>& AdditionalModifiers) const;

	UFUNCTION(BlueprintPure, Category="Preview", meta=(CallInEditor="true"))
	const UAthenaCharacterItemDefinition* GetCharacterCID(UObject* Outer, const TArray<UNPCCharacterModifier*>& AdditionalModifiers) const;

	UFUNCTION(BlueprintPure, Category="Preview", meta=(CallInEditor="true"))
	void GetPreviewMesh(UObject* Outer, const TArray<UNPCCharacterModifier*>& AdditionalModifiers, TArray<FCharacterPreviewMesh>& OutCharacterPreviewMeshes, APawn*& OutDefaultPawn) const;

	UFUNCTION(BlueprintPure, Category="Preview")
	virtual void GetRequiredAssets(TArray<FSoftObjectPath>& OutAssets) const;

protected:
	UPROPERTY(BlueprintAssignable, Category="NPC Character Modifiers")
	FCharacterModifierModifiedDelegate OnCharacterModifierModified;

	UPROPERTY(BlueprintAssignable, Category="NPC Character Type")
	FCharacterTypeModifiedDelegate OnCharacterTypeModified;

private:
	UPROPERTY(EditDefaultsOnly, NoClear, EditFixedSize, Instanced, Category="NPC Character Type")
	TObjectPtr<UNPCCharacterType> Type;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="NPC Character Behavior")
	TObjectPtr<UNPCCharacterModifier_Behavior> Behavior;

	UPROPERTY(EditDefaultsOnly, NoClear, Instanced, Category="NPC Character Modifiers")
	TArray<TObjectPtr<UNPCCharacterModifier>> Modifiers;

};

