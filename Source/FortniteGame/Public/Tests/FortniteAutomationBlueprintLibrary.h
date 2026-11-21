// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/ARFilter.h"
#include "AssetRegistry/AssetData.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortSubGameTypes.h"
#include "FortniteAutomationBlueprintLibrary.generated.h"

class AActor;
class AFortPlayerController;
class AFortPlayerMannequin;
class AFortPlayerParachute;
class AFortWeapon;
class UAthenaBackpackItemDefinition;
class UAthenaCharacterItemDefinition;
class UAthenaCosmeticItemDefinition;
class UAthenaGliderItemDefinition;
class UAthenaItemWrapDefinition;
class UAthenaPickaxeItemDefinition;
class UFortCreativeRealEstatePlotItemDefinition;
class UFortItemDefinition;
class UFortPlaysetItemDefinition;
class UFortVariantTokenType;
class UObject;
enum class EFortItemType : uint8;
enum class EItemWrapMaterialType : uint8;
enum class ESubGame : uint8;

UCLASS()
class UFortniteAutomationBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static void ApplyItemWrapToActor(UAthenaItemWrapDefinition* Wrap, AActor* Actor, EItemWrapMaterialType MaterialType);

	UFUNCTION(BlueprintCallable, Category="Animation")
	static void ClearAllAnimInstances(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Particles")
	static void ClearAllCharacterPartAnimations(AFortPlayerMannequin* Mannequin);

	UFUNCTION(BlueprintCallable, Category="Perf")
	static bool DumpFPSChartsData(const FString& EntryName);

	UFUNCTION(BlueprintCallable, Category="Assets")
	static TSet<UClass*> FindDerivedBlueprintClasses(const FName& BaseClassName, const FString& SearchString, const FString& SearchPath);

	UFUNCTION(BlueprintCallable, Category="Assets")
	static TSet<UClass*> FindDerivedBlueprintClassesByAssetNames(const FName& BaseClassName, const TArray<FString>& AssetNames, const FString& SearchPath);

	UFUNCTION(BlueprintCallable, Category="Items")
	static bool ForceAthenaCosmetic(const UAthenaCosmeticItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, Category="Items")
	static TArray<UAthenaCosmeticItemDefinition*> GetAllAthenaCosmetics(const EFortItemType Type);

	UFUNCTION(BlueprintCallable, Category="Items")
	static TArray<UAthenaCosmeticItemDefinition*> GetAllAthenaCosmetics_MultipleType(const TArray<EFortItemType> Types);

	UFUNCTION(BlueprintCallable, Category="Items")
	static TArray<UFortVariantTokenType*> GetAllFortVariantTokens();

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<TSubclassOf<AActor>> GetAllItemWrapCompatibleActors(ESubGame SubGame = ESubGame::Athena, bool OnePerType = false);

	UFUNCTION(BlueprintCallable, Category="Creative")
	static TArray<UFortPlaysetItemDefinition*> GetAllPlaysetItemDefinitions();

	UFUNCTION(BlueprintCallable, Category="Creative")
	static TArray<UFortCreativeRealEstatePlotItemDefinition*> GetAllRealEstatePlotItemDefinitions(bool bOnlyPlayerFacing = true);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<FGameplayTagContainer> GetAllVariantCombinations(UAthenaCosmeticItemDefinition* ItemDefinition, const TArray<FString> IgnoredChannels, bool UnlockableOnly = true);

	UFUNCTION()
	static void GetAssets(const FARFilter& Filter, TArray<FAssetData>& OutAssetData, bool bSkipARFilteredAssets);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static int32 GetItemWrapperLockerSlotIndex(UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<FGameplayTag> GetVariantChannels(const UAthenaCosmeticItemDefinition* ItemDefinition, bool UnlockableOnly = true);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<FGameplayTag> GetVariantNames(const UAthenaCosmeticItemDefinition* ItemDefinition, FGameplayTag VariantChannel, bool UnlockableOnly = true);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<TSoftObjectPtr<UObject>> GetWrapPreviewObjects(ESubGame SubGame = ESubGame::Athena);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static FFortAthenaLoadout MakeLoadoutFromVariantChannelInfos(TArray<FMcpVariantChannelInfo> VariantInfo);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static FMcpVariantChannelInfo MakeVariantChannelInfo(UAthenaCosmeticItemDefinition* ItemDefinition, FGameplayTag Channel, FGameplayTag ActiveVariant, const FString& CustomData = TEXT(""));

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<FMcpVariantChannelInfo> MakeVariantChannelInfosFromVariantTagContainer(UAthenaCosmeticItemDefinition* ItemDefinition, FGameplayTagContainer VariantTags);

	UFUNCTION(BlueprintCallable, Category="Items")
	static bool ResetForcedAthenaCosmetics();

	UFUNCTION(BlueprintCallable, Category="Perf")
	static bool ResetFPSChartsData();

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<AActor*> SpawnAthenaBackpack(UAthenaBackpackItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations = true);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<AActor*> SpawnAthenaBackpackPawn(UAthenaBackpackItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations = true);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static AFortPlayerMannequin* SpawnAthenaCharacterSkin(UAthenaCharacterItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations = true, UClass* MannequinClass = nullptr);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<AActor*> SpawnAthenaCharacterSkinPawn(UAthenaCharacterItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations, UClass* MannequinClass);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<AFortPlayerParachute*> SpawnAthenaGlider(UAthenaGliderItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations = true);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static TArray<AFortWeapon*> SpawnAthenaPickaxe(UAthenaPickaxeItemDefinition* ItemDefinition, const FTransform SpawnTransform, const TArray<FMcpVariantChannelInfo> VariantChannelInfos, const bool ClearAnimations = true);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static AFortPlayerController* SpawnCosmeticPlayerPawn(const FTransform SpawnTransform);

	UFUNCTION(BlueprintCallable, Category="Particles")
	static void StopAllParticles(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Cosmetic")
	static void SyncLoadCharacterParts(UAthenaCharacterItemDefinition* ItemDefinition);

};

