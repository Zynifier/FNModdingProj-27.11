// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Variants/FortCosmeticVarianceFlowTypes.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Customization/CustomCharacterPart.h"
#include "FortCustomBodyTypeEnum.h"
#include "FortGender.h"
#include "Stats/FortStatManagerTag.h"
#include "FortCosmeticFunctionLibrary.generated.h"

class AFortPlayerPawn;
class UAthenaCharacterItemDefinition;
class UAthenaCosmeticItemDefinition;
class UMaterialInstanceDynamic;
class UObject;
class UPrimitiveComponent;
class USkeletalMeshComponent;
enum class EAthenaCustomizationCategory : uint8;

UCLASS()
class UFortCosmeticFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="Params", ExpandBoolAsExecs="ReturnValue"))
	static bool ApplyVariantsToComponent(const AFortPlayerPawn* PlayerPawn, EAthenaCustomizationCategory ItemType, UPrimitiveComponent* Component, const FApplyVariantsAdditionalParams& Params);

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="Params", ExpandBoolAsExecs="ReturnValue"))
	static bool ApplyVariantsToMaterial(const AFortPlayerPawn* PlayerPawn, EAthenaCustomizationCategory ItemType, UMaterialInstanceDynamic* Material, const FApplyVariantsAdditionalParams& Params);

	UFUNCTION(BlueprintPure)
	static bool DoMinimalVariantSelectionsMatch(const TArray<FCosmeticVariantInfo>& VariantChannelsA, const TArray<FCosmeticVariantInfo>& VariantChannelsB);

	UFUNCTION(BlueprintPure)
	static bool DoVariantSelectionsMatch(const TArray<FMcpVariantChannelInfo>& VariantChannelsA, const TArray<FMcpVariantChannelInfo>& VariantChannelsB, bool bCompareOwnedTags = false);

	UFUNCTION(BlueprintCallable)
	static TArray<USkeletalMeshComponent*> FilterPartMeshComponentsByTag(const TArray<FAppliedCharacterPartInfo>& CharacterPartInfo, FGameplayTag RequiredTag);

	UFUNCTION(BlueprintCallable)
	static TArray<FAppliedCharacterPartInfo> FilterPartsByTag(const TArray<FAppliedCharacterPartInfo>& CharacterPartInfo, FGameplayTag RequiredTag);

	UFUNCTION(BlueprintCallable, meta=(ExpandBoolAsExecs="ReturnValue"))
	static bool FindBodyType(const UObject* Object, TEnumAsByte<EFortCustomBodyType::Type>& OutBodyType);

	UFUNCTION(BlueprintCallable, meta=(ExpandBoolAsExecs="ReturnValue"))
	static bool FindGender(const UObject* Object, TEnumAsByte<EFortCustomGender::Type>& OutGender);

	UFUNCTION(BlueprintPure)
	static void GetActiveMinimalVariantsForItem(const UAthenaCosmeticItemDefinition* Item, const FFortAthenaLoadout& Loadout, TArray<FCosmeticVariantInfo>& OutVariantChannels);

	UFUNCTION(BlueprintPure)
	static FGameplayTag GetActiveVariantForItemAndChannel(const FFortAthenaLoadout& Loadout, const UAthenaCosmeticItemDefinition* Item, FGameplayTag VariantChannelTag);

	UFUNCTION(BlueprintPure)
	static FGameplayTag GetActiveVariantForSoftItemAndChannel(const FFortAthenaLoadout& Loadout, TSoftObjectPtr<UAthenaCosmeticItemDefinition> Item, FGameplayTag VariantChannelTag);

	UFUNCTION(BlueprintPure)
	static void GetActiveVariantsForItem(const UAthenaCosmeticItemDefinition* Item, const FFortAthenaLoadout& Loadout, TArray<FMcpVariantChannelInfo>& OutVariantChannels);

	UFUNCTION(BlueprintPure)
	static float GetCosmeticStatDelay(FFortStatManagerTag StatTag);

	UFUNCTION(BlueprintCallable)
	static int32 GetCosmeticStatValue(const AFortPlayerPawn* PlayerPawn, FFortStatManagerTag StatTag, int32 DefaultValue = 0);

	UFUNCTION(BlueprintPure)
	static FGameplayTagContainer GetLoadoutMetaTagsForItem(const FFortAthenaLoadout& Loadout, TSoftObjectPtr<UAthenaCosmeticItemDefinition> SoftItem);

	UFUNCTION(BlueprintCallable, meta=(CallableWithoutWorldContext, WorldContext="WorldContextObject"))
	static void GetVariantChannelActiveIndexForItem(UObject* WorldContextObject, const UAthenaCosmeticItemDefinition* Item, const FFortAthenaLoadout& Loadout, FGameplayTag Channel, const TArray<FGameplayTag>& VariantList, int32& Index, bool& bIndexIsValid, bool& bFoundChannel, bool bErrorIfChannelMissing = true, bool bErrorIfTagNotInArray = true);

	UFUNCTION(BlueprintCallable, meta=(CallableWithoutWorldContext, WorldContext="WorldContextObject"))
	static void GetVariantChannelActiveIndexForSlot(UObject* WorldContextObject, EAthenaCustomizationCategory Slot, int32 SubslotIndex, const FFortAthenaLoadout& Loadout, FGameplayTag Channel, const TArray<FGameplayTag>& VariantList, int32& Index, bool& bIndexIsValid, bool& bFoundChannel, bool bErrorIfChannelMissing = true, bool bErrorIfTagNotInArray = true);

	UFUNCTION(BlueprintPure)
	static bool IsItemInLoadout(const FFortAthenaLoadout& Loadout, TSoftObjectPtr<UAthenaCosmeticItemDefinition> Item);

	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="ChannelInfoList"))
	static FFortSwapItemAndVariantData MakeSwapDataForCosmetic(const UAthenaCharacterItemDefinition* Definition, TArray<FMcpVariantChannelInfo> ChannelInfoList);

	UFUNCTION(BlueprintCallable)
	static bool RequestPresetCosmeticSwap(AFortPlayerPawn* PlayerPawn, TSoftObjectPtr<UAthenaCosmeticItemDefinition> SoftItemDefinition, int32 SwapIndex);

};

