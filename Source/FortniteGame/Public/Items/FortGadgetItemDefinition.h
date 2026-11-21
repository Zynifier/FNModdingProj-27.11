// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "FortDamageSourceInterface.h"
#include "Items/FortItemDefinitionAbilitySetInterface.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortGadgetItemDefinition.generated.h"

class UAttributeSet;
class UCustomCharacterPart;
class UFortAbilitySet;
class UFortAnimInstance;
class UFortFootstepAudioBank;
class UFortGameplayAbility;
class UFortItemDefinition;
class UFortWeaponItemDefinition;
class UParticleSystem;
class USoundBase;

USTRUCT()
struct FCharacterPartsExtraSpecial
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CharacterPartsExtraSpecial")
	TArray<TObjectPtr<UCustomCharacterPart>> CharacterPartsForExtraSpecial;

	UPROPERTY(EditDefaultsOnly, Category="CharacterPartsExtraSpecial")
	FGameplayTagContainer SkinMetaTagsForExtraSpecial;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortGadgetItemDefinition : public UFortWorldItemDefinition, public IFortDamageSourceInterface, public IFortItemDefinitionAbilitySetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="GadgetItemDefinition")
	TSubclassOf<UFortGameplayAbility> GetGameplayAbility() const;

	UFUNCTION(BlueprintPure, Category="GadgetItemDefinition")
	FGameplayAttribute GetLevelAttribute() const;

	UFUNCTION(BlueprintPure, Category="GadgetItemDefinition")
	UFortWeaponItemDefinition* GetWeaponItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="GadgetItemDefinition")
	bool HasChargeUp() const;

	UFUNCTION(BlueprintPure, Category="GadgetItemDefinition")
	bool HasTrackedAttributes() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Gadget Data")
	bool bApplyGadgetDataManually;

	UPROPERTY(EditDefaultsOnly, Category="Gadget Priority")
	int32 GadgetPriority;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Ability Sets", meta=(DisplayAfter="TrackedAttributes"))
	uint8 bDestroyGadgetWhenTrackedAttributesIsZero : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Deco Ability", meta=(DisplayAfter="GameplayAbility"))
	uint8 bHasChargeUp : 1;

	UPROPERTY(EditDefaultsOnly, Category="Functionality")
	uint8 bDropAllOnEquip : 1;

	UPROPERTY(EditAnywhere, Category="Gadget - Deco Ability", meta=(DisplayAfter="DamageStatHandle"))
	uint8 bCanChangePreviewImageDuringGame : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Ability Sets", meta=(DisplayAfter="TrackedAttributes"))
	uint8 bAlwaysInitAttributeSet : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Cosmetic")
	TArray<TObjectPtr<UCustomCharacterPart>> CharacterParts;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Cosmetic")
	FGameplayTagContainer SkinMetaTagsToSkip;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Cosmetic", meta=(Categories="Cosmetics.MetaTags.Theme"))
	FGameplayTag PartSwapTag;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Cosmetic")
	TArray<FCharacterPartsExtraSpecial> CharacterPartsExtraSpecial;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Animation", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails"))
	TSoftClassPtr<UFortAnimInstance> AnimBPOverride;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Sound", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails"))
	TSoftObjectPtr<UFortFootstepAudioBank> FootstepBankOverride;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Ability Sets", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails,ClientAthenaPreload"))
	TSoftObjectPtr<UFortAbilitySet> AbilitySet;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Ability Sets", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails"))
	TSoftClassPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Ability Sets")
	FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Ability Sets")
	TArray<FGameplayAttribute> TrackedAttributes;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Tracked Attributes - Destroy FX", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails,ClientAthenaPreload", EditCondition="bDestroyGadgetWhenTrackedAttributesIsZero"))
	TSoftObjectPtr<UParticleSystem> OnDestroyParticleSystem;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Tracked Attributes - Destroy FX", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails,ClientAthenaPreload", EditCondition="bDestroyGadgetWhenTrackedAttributesIsZero"))
	TSoftObjectPtr<USoundBase> OnDestroySound;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Tracked Attributes - Destroy FX", meta=(EditCondition="bDestroyGadgetWhenTrackedAttributesIsZero"))
	FName OnDestroyAttachToSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Deco Ability", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails"))
	TSoftClassPtr<UFortGameplayAbility> GameplayAbility;

	UPROPERTY(EditDefaultsOnly, Category="Functionality")
	FGameplayTagContainer HUDVisibilityTags;

	UPROPERTY(EditAnywhere, Category="Gadget - Deco Ability", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails,ItemsInInventoryInZone,ClientAthenaPreload,ServerAthenaPreload"))
	TSoftObjectPtr<UFortWeaponItemDefinition> WeaponItemDefinition;

	UPROPERTY(EditAnywhere, Category="Gadget - Deco Ability")
	TArray<TSoftObjectPtr<UFortItemDefinition>> AdditionalItemsToLoadWhenEquipped;

	UPROPERTY(EditAnywhere, Category="Gadget - Deco Ability")
	bool bValidForLastEquipped;

	UPROPERTY(EditDefaultsOnly, Category="Gadget - Deco Ability")
	FGameplayAttribute LevelAttribute;

	UPROPERTY(EditAnywhere, Category="Gadget - Deco Ability")
	FDataTableRowHandle DamageStatHandle;

	UPROPERTY(EditAnywhere, Category="Gadget - Homebase Node")
	FString NodeId;

};

