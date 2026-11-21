// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaPetItemDefinition.generated.h"

class AFortPlayerPet;
class UFortPetStimuliBank;
class UFortTaggedSoundBank;

UENUM()
enum class EAthenaPetAttachRule : uint8
{
	// Attaches the pet to the backpack.

	AttachToBackpack = 0,
	// Attaches the pet to the body.

	AttachToBody = 1,
};

USTRUCT()
struct FPetStimuliResponse
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PetStimuliResponse")
	FGameplayTag ResponseTag;

	UPROPERTY(EditAnywhere, Category="PetStimuliResponse")
	float ResponseDuration;

	UPROPERTY(EditAnywhere, Category="PetStimuliResponse")
	float ResponseWeight;

};

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaPetItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Visual")
	TSubclassOf<AFortPlayerPet> GetPetPrefabClass() const;

	UPROPERTY(EditAnywhere, Category="Visual")
	EAthenaPetAttachRule PetAttachRule;

	UPROPERTY(EditAnywhere, Category="Visual")
	FVector PetAttachOffset;

	UPROPERTY(EditAnywhere, Category="Visual")
	FName PetAttachSocket;

	UPROPERTY(EditAnywhere, Category="Visual")
	TArray<TObjectPtr<UFortPetStimuliBank>> StimuliBanks;

private:
	UPROPERTY(EditAnywhere, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<AFortPlayerPet> PetPrefabClass;

	UPROPERTY(EditAnywhere, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UFortTaggedSoundBank> PetSoundBank;

};

