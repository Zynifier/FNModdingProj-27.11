// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameItemListComponent.h"
#include "Net/UnrealNetwork.h"

int32 UFortMinigameItemListComponent::AddItem(UFortWorldItemDefinition* ItemDefinition, int32 ItemQuantity)
{
	return int32();
}

bool UFortMinigameItemListComponent::AddItemEntry(const FFortItemEntry& ItemEntry)
{
	return false;
}

void UFortMinigameItemListComponent::AddItemsFromSpawnParams(const TArray<FMinigameSpawnerSpawnParams>& ItemSpawnParams)
{
}

bool UFortMinigameItemListComponent::CanEditItemListComponent(AFortPlayerController* PlayerController) const
{
	return false;
}

void UFortMinigameItemListComponent::ClearItems()
{
}

TArray<UFortWorldItemDefinition*> UFortMinigameItemListComponent::GetContainedItems() const
{
	return TArray<UFortWorldItemDefinition*>();
}

TArray<FItemVariantHandle> UFortMinigameItemListComponent::GetContainedItemVariants() const
{
	return TArray<FItemVariantHandle>();
}

int32 UFortMinigameItemListComponent::GetNumItems() const
{
	return int32();
}

bool UFortMinigameItemListComponent::GetPropertyOverridesForItem(TMap<FString, FString>& CurrentOptions, int32 ItemIndex) const
{
	return false;
}

FMinigameSpawnerSpawnParams UFortMinigameItemListComponent::MakeSpawnParams(const int32 Index, const FTransform& SpawnTransform) const
{
	return FMinigameSpawnerSpawnParams();
}

TArray<FMinigameSpawnerSpawnParams> UFortMinigameItemListComponent::MakeSpawnParamsList(const FTransform& SpawnTransform) const
{
	return TArray<FMinigameSpawnerSpawnParams>();
}

void UFortMinigameItemListComponent::OnRep_ItemListData()
{
}

bool UFortMinigameItemListComponent::RemoveItem(int32 ItemIndex)
{
	return false;
}

void UFortMinigameItemListComponent::RequestItemTemplateUpdate(FOnUpdateItemTemplate UpdateItemTemplateDelegate, int32 ItemIndex)
{
}

bool UFortMinigameItemListComponent::SetBaseInstigatorData(const FPickupInstigatorData& InstigatorData)
{
	return false;
}

void UFortMinigameItemListComponent::SetEnableItemTemplates(const bool bValue)
{
}

bool UFortMinigameItemListComponent::SetPropertyOverridesForItem(const TMap<FString, FString>& NewOptions, int32 ItemIndex)
{
	return false;
}

void UFortMinigameItemListComponent::SetShouldRegisterNewItemVariants(const bool bValue)
{
}

#if WITH_EDITOR
bool UFortMinigameItemListComponent::ShouldFilterAsset(const FAssetData& AssetData) const
{
	return false;
}
#endif

bool UFortMinigameItemListComponent::ShouldRegisterNewItemVariants() const
{
	return false;
}

void UFortMinigameItemListComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMinigameItemListComponent, ItemListData);
}
