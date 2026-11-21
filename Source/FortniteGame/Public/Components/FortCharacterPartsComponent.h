// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Customization/BoneSetVisibilityInterface.h"
#include "Customization/CustomCharacterPartOwnerInterface.h"
#include "FortCustomPartTypeEnum.h"
#include "FortCharacterPartsComponent.generated.h"

class UCustomCharacterPart;
class UFortCustomizationAssetLoader;
class USkeletalMeshComponent;
class USkeletalMeshComponentBudgeted;

USTRUCT()
struct FPartStackEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UCustomCharacterPart>> PartList;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCharacterPartsComponent : public UActorComponent, public ICustomCharacterPartOwnerInterface, public IBoneSetVisibilityInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Customization")
	bool ApplyParts(const TArray<UCustomCharacterPart*>& Parts);

	UFUNCTION(BlueprintCallable, Category="Customization")
	TArray<USkeletalMeshComponent*> GetSkeletalMeshesForAllParts();

	UFUNCTION(BlueprintCallable, Category="Customization")
	USkeletalMeshComponent* GetSkeletalMeshForPartTag(FGameplayTag PartTag);

	UFUNCTION(BlueprintCallable, Category="Customization")
	USkeletalMeshComponent* GetSkeletalMeshForPartType(EFortCustomPartType::Type PartType);

	UFUNCTION(BlueprintCallable, Category="Customization")
	void RemoveAllParts();

	UFUNCTION(BlueprintCallable, Category="Customization")
	bool RemovePart(EFortCustomPartType::Type PartType);

	UFUNCTION(BlueprintCallable, Category="Customization")
	bool RemovePartByGameplayTag(FGameplayTag PartTag);

	UFUNCTION(BlueprintCallable, Category="Customization")
	bool RestoreParts();

private:
	UFUNCTION()
	void OnRep_CharacterParts(TArray<UCustomCharacterPart*> PreviousParts);

	UPROPERTY(Transient)
	TObjectPtr<UFortCustomizationAssetLoader> CustomizationAssetLoader;

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_CharacterParts, Category="CharacterParts")
	TArray<TObjectPtr<UCustomCharacterPart>> CharacterPartList;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<USkeletalMeshComponentBudgeted>> SkeletalMeshComponents;

	UPROPERTY(Transient)
	TArray<FPartStackEntry> CharacterPartStack;

};

