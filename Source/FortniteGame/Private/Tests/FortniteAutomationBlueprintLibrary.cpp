// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tests/FortniteAutomationBlueprintLibrary.h"

void UFortniteAutomationBlueprintLibrary::ApplyItemWrapToActor(UAthenaItemWrapDefinition* Wrap, AActor* Actor, EItemWrapMaterialType MaterialType)
{
}

void UFortniteAutomationBlueprintLibrary::ClearAllAnimInstances(AActor* Actor)
{
}

void UFortniteAutomationBlueprintLibrary::ClearAllCharacterPartAnimations(AFortPlayerMannequin* Mannequin)
{
}

bool UFortniteAutomationBlueprintLibrary::DumpFPSChartsData(const FString& EntryName)
{
	return false;
}

TSet<UClass*> UFortniteAutomationBlueprintLibrary::FindDerivedBlueprintClasses(const FName& BaseClassName, const FString& SearchString, const FString& SearchPath)
{
	return TSet<UClass*>();
}

TSet<UClass*> UFortniteAutomationBlueprintLibrary::FindDerivedBlueprintClassesByAssetNames(const FName& BaseClassName, const TArray<FString>& AssetNames, const FString& SearchPath)
{
	return TSet<UClass*>();
}

bool UFortniteAutomationBlueprintLibrary::ForceAthenaCosmetic(const UAthenaCosmeticItemDefinition* ItemDefinition)
{
	return false;
}

TArray<UAthenaCosmeticItemDefinition*> UFortniteAutomationBlueprintLibrary::GetAllAthenaCosmetics(const EFortItemType Type)
{
	return TArray<UAthenaCosmeticItemDefinition*>();
}

TArray<UAthenaCosmeticItemDefinition*> UFortniteAutomationBlueprintLibrary::GetAllAthenaCosmetics_MultipleType(const TArray<EFortItemType> Types)
{
	return TArray<UAthenaCosmeticItemDefinition*>();
}

TArray<UFortVariantTokenType*> UFortniteAutomationBlueprintLibrary::GetAllFortVariantTokens()
{
	return TArray<UFortVariantTokenType*>();
}

TArray<TSubclassOf<AActor>> UFortniteAutomationBlueprintLibrary::GetAllItemWrapCompatibleActors(ESubGame SubGame, bool OnePerType)
{
	return TArray<TSubclassOf<AActor>>();
}

TArray<UFortPlaysetItemDefinition*> UFortniteAutomationBlueprintLibrary::GetAllPlaysetItemDefinitions()
{
	return TArray<UFortPlaysetItemDefinition*>();
}

TArray<UFortCreativeRealEstatePlotItemDefinition*> UFortniteAutomationBlueprintLibrary::GetAllRealEstatePlotItemDefinitions(bool bOnlyPlayerFacing)
{
	return TArray<UFortCreativeRealEstatePlotItemDefinition*>();
}

TArray<FGameplayTagContainer> UFortniteAutomationBlueprintLibrary::GetAllVariantCombinations(UAthenaCosmeticItemDefinition* ItemDefinition, const TArray<FString> IgnoredChannels, bool UnlockableOnly)
{
	return TArray<FGameplayTagContainer>();
}

void UFortniteAutomationBlueprintLibrary::GetAssets(const FARFilter& Filter, TArray<FAssetData>& OutAssetData, bool bSkipARFilteredAssets)
{
}

int32 UFortniteAutomationBlueprintLibrary::GetItemWrapperLockerSlotIndex(UFortItemDefinition* ItemDefinition)
{
	return int32();
}

TArray<FGameplayTag> UFortniteAutomationBlueprintLibrary::GetVariantChannels(const UAthenaCosmeticItemDefinition* ItemDefinition, bool UnlockableOnly)
{
	return TArray<FGameplayTag>();
}

TArray<FGameplayTag> UFortniteAutomationBlueprintLibrary::GetVariantNames(const UAthenaCosmeticItemDefinition* ItemDefinition, FGameplayTag VariantChannel, bool UnlockableOnly)
{
	return TArray<FGameplayTag>();
}

TArray<TSoftObjectPtr<UObject>> UFortniteAutomationBlueprintLibrary::GetWrapPreviewObjects(ESubGame SubGame)
{
	return TArray<TSoftObjectPtr<UObject>>();
}

FFortAthenaLoadout UFortniteAutomationBlueprintLibrary::MakeLoadoutFromVariantChannelInfos(TArray<FMcpVariantChannelInfo> VariantInfo)
{
	return FFortAthenaLoadout();
}

FMcpVariantChannelInfo UFortniteAutomationBlueprintLibrary::MakeVariantChannelInfo(UAthenaCosmeticItemDefinition* ItemDefinition, FGameplayTag Channel, FGameplayTag ActiveVariant, const FString& CustomData)
{
	return FMcpVariantChannelInfo();
}

TArray<FMcpVariantChannelInfo> UFortniteAutomationBlueprintLibrary::MakeVariantChannelInfosFromVariantTagContainer(UAthenaCosmeticItemDefinition* ItemDefinition, FGameplayTagContainer VariantTags)
{
	return TArray<FMcpVariantChannelInfo>();
}

bool UFortniteAutomationBlueprintLibrary::ResetForcedAthenaCosmetics()
{
	return false;
}

bool UFortniteAutomationBlueprintLibrary::ResetFPSChartsData()
{
	return false;
}

TArray<AActor*> UFortniteAutomationBlueprintLibrary::SpawnAthenaBackpack(UAthenaBackpackItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations)
{
	return TArray<AActor*>();
}

TArray<AActor*> UFortniteAutomationBlueprintLibrary::SpawnAthenaBackpackPawn(UAthenaBackpackItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations)
{
	return TArray<AActor*>();
}

AFortPlayerMannequin* UFortniteAutomationBlueprintLibrary::SpawnAthenaCharacterSkin(UAthenaCharacterItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations, UClass* MannequinClass)
{
	return nullptr;
}

TArray<AActor*> UFortniteAutomationBlueprintLibrary::SpawnAthenaCharacterSkinPawn(UAthenaCharacterItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations, UClass* MannequinClass)
{
	return TArray<AActor*>();
}

TArray<AFortPlayerParachute*> UFortniteAutomationBlueprintLibrary::SpawnAthenaGlider(UAthenaGliderItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations)
{
	return TArray<AFortPlayerParachute*>();
}

TArray<AFortWeapon*> UFortniteAutomationBlueprintLibrary::SpawnAthenaPickaxe(UAthenaPickaxeItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations)
{
	return TArray<AFortWeapon*>();
}

AFortPlayerController* UFortniteAutomationBlueprintLibrary::SpawnCosmeticPlayerPawn(const FTransform SpawnTransform)
{
	return nullptr;
}

void UFortniteAutomationBlueprintLibrary::StopAllParticles(AActor* Actor)
{
}

void UFortniteAutomationBlueprintLibrary::SyncLoadCharacterParts(UAthenaCharacterItemDefinition* ItemDefinition)
{
}
