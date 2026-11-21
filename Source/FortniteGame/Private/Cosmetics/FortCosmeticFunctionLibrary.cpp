// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/FortCosmeticFunctionLibrary.h"

bool UFortCosmeticFunctionLibrary::ApplyVariantsToComponent(const AFortPlayerPawn* PlayerPawn, EAthenaCustomizationCategory ItemType, UPrimitiveComponent* Component, const FApplyVariantsAdditionalParams& Params)
{
	return false;
}

bool UFortCosmeticFunctionLibrary::ApplyVariantsToMaterial(const AFortPlayerPawn* PlayerPawn, EAthenaCustomizationCategory ItemType, UMaterialInstanceDynamic* Material, const FApplyVariantsAdditionalParams& Params)
{
	return false;
}

bool UFortCosmeticFunctionLibrary::DoMinimalVariantSelectionsMatch(const TArray<FCosmeticVariantInfo>& VariantChannelsA, const TArray<FCosmeticVariantInfo>& VariantChannelsB)
{
	return false;
}

bool UFortCosmeticFunctionLibrary::DoVariantSelectionsMatch(const TArray<FMcpVariantChannelInfo>& VariantChannelsA, const TArray<FMcpVariantChannelInfo>& VariantChannelsB, bool bCompareOwnedTags)
{
	return false;
}

TArray<USkeletalMeshComponent*> UFortCosmeticFunctionLibrary::FilterPartMeshComponentsByTag(const TArray<FAppliedCharacterPartInfo>& CharacterPartInfo, FGameplayTag RequiredTag)
{
	return TArray<USkeletalMeshComponent*>();
}

TArray<FAppliedCharacterPartInfo> UFortCosmeticFunctionLibrary::FilterPartsByTag(const TArray<FAppliedCharacterPartInfo>& CharacterPartInfo, FGameplayTag RequiredTag)
{
	return TArray<FAppliedCharacterPartInfo>();
}

bool UFortCosmeticFunctionLibrary::FindBodyType(const UObject* Object, TEnumAsByte<EFortCustomBodyType::Type>& OutBodyType)
{
	return false;
}

bool UFortCosmeticFunctionLibrary::FindGender(const UObject* Object, TEnumAsByte<EFortCustomGender::Type>& OutGender)
{
	return false;
}

void UFortCosmeticFunctionLibrary::GetActiveMinimalVariantsForItem(const UAthenaCosmeticItemDefinition* Item, const FFortAthenaLoadout& Loadout, TArray<FCosmeticVariantInfo>& OutVariantChannels)
{
}

FGameplayTag UFortCosmeticFunctionLibrary::GetActiveVariantForItemAndChannel(const FFortAthenaLoadout& Loadout, const UAthenaCosmeticItemDefinition* Item, FGameplayTag VariantChannelTag)
{
	return FGameplayTag();
}

FGameplayTag UFortCosmeticFunctionLibrary::GetActiveVariantForSoftItemAndChannel(const FFortAthenaLoadout& Loadout, TSoftObjectPtr<UAthenaCosmeticItemDefinition> Item, FGameplayTag VariantChannelTag)
{
	return FGameplayTag();
}

void UFortCosmeticFunctionLibrary::GetActiveVariantsForItem(const UAthenaCosmeticItemDefinition* Item, const FFortAthenaLoadout& Loadout, TArray<FMcpVariantChannelInfo>& OutVariantChannels)
{
}

float UFortCosmeticFunctionLibrary::GetCosmeticStatDelay(FFortStatManagerTag StatTag)
{
	return float();
}

int32 UFortCosmeticFunctionLibrary::GetCosmeticStatValue(const AFortPlayerPawn* PlayerPawn, FFortStatManagerTag StatTag, int32 DefaultValue)
{
	return int32();
}

FGameplayTagContainer UFortCosmeticFunctionLibrary::GetLoadoutMetaTagsForItem(const FFortAthenaLoadout& Loadout, TSoftObjectPtr<UAthenaCosmeticItemDefinition> SoftItem)
{
	return FGameplayTagContainer();
}

void UFortCosmeticFunctionLibrary::GetVariantChannelActiveIndexForItem(UObject* WorldContextObject, const UAthenaCosmeticItemDefinition* Item, const FFortAthenaLoadout& Loadout, FGameplayTag Channel, const TArray<FGameplayTag>& VariantList, int32& Index, bool& bIndexIsValid, bool& bFoundChannel, bool bErrorIfChannelMissing, bool bErrorIfTagNotInArray)
{
}

void UFortCosmeticFunctionLibrary::GetVariantChannelActiveIndexForSlot(UObject* WorldContextObject, EAthenaCustomizationCategory Slot, int32 SubslotIndex, const FFortAthenaLoadout& Loadout, FGameplayTag Channel, const TArray<FGameplayTag>& VariantList, int32& Index, bool& bIndexIsValid, bool& bFoundChannel, bool bErrorIfChannelMissing, bool bErrorIfTagNotInArray)
{
}

bool UFortCosmeticFunctionLibrary::IsItemInLoadout(const FFortAthenaLoadout& Loadout, TSoftObjectPtr<UAthenaCosmeticItemDefinition> Item)
{
	return false;
}

FFortSwapItemAndVariantData UFortCosmeticFunctionLibrary::MakeSwapDataForCosmetic(const UAthenaCharacterItemDefinition* Definition, TArray<FMcpVariantChannelInfo> ChannelInfoList)
{
	return FFortSwapItemAndVariantData();
}

bool UFortCosmeticFunctionLibrary::RequestPresetCosmeticSwap(AFortPlayerPawn* PlayerPawn, TSoftObjectPtr<UAthenaCosmeticItemDefinition> SoftItemDefinition, int32 SwapIndex)
{
	return false;
}
