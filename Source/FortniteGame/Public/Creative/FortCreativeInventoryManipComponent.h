// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/Guid.h"
#include "FortItemVariantHandle.h"
#include "Items/FortItemTypeEnum.h"
#include "FortCreativeInventoryManipComponent.generated.h"

class AController;
class UFortWorldItemDefinition;
enum class EFortItemType : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EFortCreativeItemDropAmount : uint8
{
	All = 0,
	FlatAmount = 1,
	Percentage = 2,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortCreativeItemDropParams
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortCreativeItemDropParams")
	EFortCreativeItemDropAmount AmountRule;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeItemDropParams")
	int32 AmountToRemove;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeItemDropParams")
	float PercentageToRemove;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeItemDropParams")
	bool bSpawnPickups;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeItemDropParams")
	bool bSpawnPickupsAtPreviousGround;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortCreativeInventoryManipComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void DropAllItems(AController* Controller, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void DropItemsByItemType(AController* Controller, const TArray<FName>& MatchCreativeTags, const TArray<FName>& IgnoreCreativeTags, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount, EFortItemType ItemType = EFortItemType::Max_None);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void DropSpecificItem(AController* Controller, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void DropSpecificItemVariant(AController* Controller, const FItemVariantHandle& VariantHandle, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void DropSpecificWeaponClass(AController* Controller, const UFortWorldItemDefinition* ItemDefinition, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount);

};

