// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortItemDefinition.h"

void UFortItemDefinition::ClearPrmValues()
{
}

void UFortItemDefinition::CopyTemplateIdToClipboard()
{
}

UFortItem* UFortItemDefinition::CreateTemporaryInstanceFromExistingItemBP(UFortItem* ExistingItem, int32 Count, int32 Level) const
{
	return nullptr;
}

UFortItem* UFortItemDefinition::CreateTemporaryItemInstanceBP(int32 Count, int32 Level) const
{
	return nullptr;
}

void UFortItemDefinition::CustomizePreviewMesh(UMeshComponent* Mesh) const
{
}

void UFortItemDefinition::CustomizePreviewPrefab(AActor* PrefabInstance)
{
}

TArray<FText> UFortItemDefinition::GetDescription() const
{
	return TArray<FText>();
}

FSoftObjectPath UFortItemDefinition::GetDisplayAssetPath() const
{
	return FSoftObjectPath();
}

FText UFortItemDefinition::GetDisplayName(bool bBaseName) const
{
	return FText();
}

UFortTooltipDisplayStatsList* UFortItemDefinition::GetDisplayStats() const
{
	return nullptr;
}

FSoftObjectPath UFortItemDefinition::GetHiResDisplayAssetPath() const
{
	return FSoftObjectPath();
}

TSoftObjectPtr<UTexture2D> UFortItemDefinition::GetInactivePreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

EFortItemType UFortItemDefinition::GetItemType() const
{
	return EFortItemType();
}

FText UFortItemDefinition::GetItemTypeName(bool bUsePlural) const
{
	return FText();
}

TSoftObjectPtr<UTexture2D> UFortItemDefinition::GetLargePreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

int32 UFortItemDefinition::GetMaxNumStacks() const
{
	return int32();
}

int32 UFortItemDefinition::GetMaxStackSize(UAbilitySystemComponent* AbilityComp) const
{
	return int32();
}

FString UFortItemDefinition::GetPersistentName() const
{
	return FString();
}

void UFortItemDefinition::GetPreviewAssets(TArray<TSoftObjectPtr<UObject>>& Assets) const
{
}

FTransform UFortItemDefinition::GetPreviewMeshOffset() const
{
	return FTransform();
}

bool UFortItemDefinition::GetPreviewPrefabAsset(TSoftClassPtr<AActor>& Asset) const
{
	return false;
}

bool UFortItemDefinition::GetPreviewPrefabAssetAtSubSlot(TSoftClassPtr<AActor>& Asset, const int32 InSubSlot) const
{
	return false;
}

bool UFortItemDefinition::GetPreviewSkeletalMeshAsset(TSoftObjectPtr<USkeletalMesh>& Asset) const
{
	return false;
}

bool UFortItemDefinition::GetPreviewStaticMeshAsset(TSoftObjectPtr<UStaticMesh>& Asset) const
{
	return false;
}

FString UFortItemDefinition::GetPrmParameterName() const
{
	return FString();
}

FText UFortItemDefinition::GetQuantityDisplayName(const int32 Quantity) const
{
	return FText();
}

EFortRarity UFortItemDefinition::GetRarity() const
{
	return EFortRarity();
}

FFortColorPalette UFortItemDefinition::GetRarityOrSeriesColors() const
{
	return FFortColorPalette();
}

FText UFortItemDefinition::GetRichDescription() const
{
	return FText();
}

FText UFortItemDefinition::GetShortDescription() const
{
	return FText();
}

FText UFortItemDefinition::GetSingleLineDescription() const
{
	return FText();
}

TSoftObjectPtr<UTexture2D> UFortItemDefinition::GetSmallPreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

FSlateBrush UFortItemDefinition::GetSmallPreviewImageBrush() const
{
	return FSlateBrush();
}

EFortItemTier UFortItemDefinition::GetTier() const
{
	return EFortItemTier();
}

TSubclassOf<UFortTooltip> UFortItemDefinition::GetTooltip(bool bSummaryTooltip) const
{
	return TSubclassOf<UFortTooltip>();
}

TSoftObjectPtr<UTexture2D> UFortItemDefinition::GetWidePreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

bool UFortItemDefinition::IsInventorySizeLimited() const
{
	return false;
}

bool UFortItemDefinition::IsItemSyncShareable() const
{
	return false;
}

bool UFortItemDefinition::IsPrmValid() const
{
	return false;
}

bool UFortItemDefinition::IsStackable() const
{
	return false;
}

#if WITH_EDITOR
bool UFortItemDefinition::SeasonPostCopyFixup(const int32 SeasonNum, const FFortReleaseVersion& ReleaseVersion, const FString& NewSeasonPluginRoot)
{
	return false;
}
#endif

#if WITH_EDITOR
void UFortItemDefinition::SetRawLargePreviewImage(TSoftObjectPtr<UTexture2D> InLargePreviewImage)
{
}
#endif

#if WITH_EDITOR
void UFortItemDefinition::SetRawSmallPreviewImage(TSoftObjectPtr<UTexture2D> InSmallPreviewImage)
{
}
#endif

bool UFortItemDefinition::ShouldShowPreviewOnCurrentHero(const int32 InSubSlot) const
{
	return false;
}

bool UFortItemDefinition::ShouldTrackInPRM() const
{
	return false;
}

void UFortItemDefinition::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}
