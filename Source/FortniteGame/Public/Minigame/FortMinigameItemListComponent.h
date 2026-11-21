// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "FortItemVariantHandle.h"
#include "FortLevelDuplicatableInterface.h"
#include "FortPickupInstigatorInterface.h"
#include "FortPropertyOverrideData.h"
#include "FortPropertyOverrideReplication.h"
#include "Items/FortItemEntry.h"
#include "Minigame/FortMinigameItemContainerComponent.h"
#include "Minigame/FortMinigameSpawnerComponent.h"
#include "FortMinigameItemListComponent.generated.h"

class AFortPlayerController;
class UFortCreativeItemTemplate;
class UFortWorldItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnUpdateItemTemplate, UFortCreativeItemTemplate*, ItemTemplate);

USTRUCT()
struct FMinigameItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, SaveGame, NoClear, Category="Item Data", meta=(GetAssetFilter="ShouldFilterAsset"))
	TSoftObjectPtr<UFortWorldItemDefinition> ItemDefinition;

	UPROPERTY(EditInstanceOnly, SaveGame, Category="Item Data")
	int32 ItemQuantity;

	UPROPERTY(EditInstanceOnly, SaveGame, Category="Item Data")
	UFortCreativeItemTemplate* TemplateObjectData;

	UPROPERTY(SaveGame, NotReplicated)
	FPropertyOverrideData ItemOptionData;

	UPROPERTY(Transient)
	int32 TrackedIndex;

	UPROPERTY(EditInstanceOnly, SaveGame, Category="Item Data")
	FGuid ItemVariantGuid;

	UPROPERTY(EditInstanceOnly, SaveGame, Category="Item Data")
	FGuid SourceItemVariantGuid;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UFortMinigameItemListComponent : public UFortMinigameItemContainerComponent, public IFortPickupInstigator, public IFortPropertyOverrideReplProvider, public ILevelDuplicatable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Item Data")
	int32 AddItem(UFortWorldItemDefinition* ItemDefinition, int32 ItemQuantity = 1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Item Data")
	bool AddItemEntry(const FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Item Data")
	void AddItemsFromSpawnParams(const TArray<FMinigameSpawnerSpawnParams>& ItemSpawnParams);

	UFUNCTION(BlueprintPure, Category="Item Data")
	bool CanEditItemListComponent(AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Item Data")
	void ClearItems();

	UFUNCTION(BlueprintPure, Category="Item Data")
	TArray<UFortWorldItemDefinition*> GetContainedItems() const;

	UFUNCTION(BlueprintPure, Category="Item Data")
	TArray<FItemVariantHandle> GetContainedItemVariants() const;

	UFUNCTION(BlueprintPure, Category="Item Data")
	int32 GetNumItems() const;

	UFUNCTION(BlueprintPure, Category="Item Data")
	bool GetPropertyOverridesForItem(TMap<FString, FString>& CurrentOptions, int32 ItemIndex = 0) const;

	UFUNCTION(BlueprintPure, Category="Item Data")
	FMinigameSpawnerSpawnParams MakeSpawnParams(const int32 Index, const FTransform& SpawnTransform) const;

	UFUNCTION(BlueprintPure, Category="Item Data")
	TArray<FMinigameSpawnerSpawnParams> MakeSpawnParamsList(const FTransform& SpawnTransform) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Item Data")
	bool RemoveItem(int32 ItemIndex);

	UFUNCTION(BlueprintCallable, Category="Item Data")
	void RequestItemTemplateUpdate(FOnUpdateItemTemplate UpdateItemTemplateDelegate, int32 ItemIndex = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Item Data")
	bool SetBaseInstigatorData(const FPickupInstigatorData& InstigatorData);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Item Data")
	bool SetPropertyOverridesForItem(const TMap<FString, FString>& NewOptions, int32 ItemIndex = 0);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Data", meta=(DisplayName="Notify Item List Changed"))
	void K2_NotifyItemListChanged();

	UFUNCTION()
	void OnRep_ItemListData();

	UFUNCTION(BlueprintCallable, Category="Item Data")
	void SetEnableItemTemplates(const bool bValue);

	UFUNCTION(BlueprintCallable, Category="Item Data")
	void SetShouldRegisterNewItemVariants(const bool bValue);

#if WITH_EDITOR
	UFUNCTION(Category="Item Data")
	bool ShouldFilterAsset(const FAssetData& AssetData) const;
#endif

	UFUNCTION(BlueprintPure, Category="Item Data")
	bool ShouldRegisterNewItemVariants() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item Data")
	FPickupInstigatorData BaseInstigatorData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Data")
	bool bAllowItemTracking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Data", meta=(EditCondition="bAllowItemTracking"))
	bool bAllowItemCustomization;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Data", meta=(EditCondition="bAllowItemCustomization"))
	bool bAllowNewItemVariants;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, SaveGame, Category="Item Data", meta=(EditCondition="bAllowItemCustomization && bAllowNewItemVariants"))
	bool bShouldRegisterNewItemVariants;

	UPROPERTY(EditDefaultsOnly, BlueprintSetter=SetEnableItemTemplates, Category="Item Data", meta=(EditCondition="bAllowItemCustomization"))
	bool bEnableItemTemplates;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Item Data")
	bool FilterAssetsWithoutMetaDataTags;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Item Data", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer MandatoryTags;

	UPROPERTY(EditAnywhere, Category="FortMinigameItemListComponent")
	bool bUseEditorOverrideData;

private:
	UPROPERTY(EditInstanceOnly, SaveGame, ReplicatedUsing=OnRep_ItemListData, Category="Item Data", meta=(AllowPrivateAccess="TRUE"))
	TArray<FMinigameItemData> ItemListData;

};

