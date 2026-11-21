// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Building/BuildingContainer.h"
#include "FortRarityEnum.h"
#include "FortTypes.h"
#include "Items/FortItemTypeEnum.h"
#include "KeepItemContainer.generated.h"

class AFortPlayerController;
class AFortPlayerState;
class UDataTable;
class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FFortKeepAmmoStash : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Max1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Cooldown1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Max2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Cooldown2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Max3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Cooldown3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Max4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Cooldown4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 PickupTier;

};

USTRUCT(BlueprintType)
struct FFortKeepItemGroup : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Items;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 MaxTier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 BaseLevel;

};

USTRUCT(BlueprintType)
struct FFortKeepResourceGroup : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	FName Container;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 ItemCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	FString ResourceName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	TSoftObjectPtr<UFortItemDefinition> FullPath;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("ForKismetOnly", "ForKismetOnly", "Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTimeOfDayLightsActorClassData)
class AKeepItemContainer : public ABuildingContainer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Keep")
	FName GetContainerNameAndLevelKey();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Keep")
	int32 GetLootTierOverride() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Keep")
	void InitializeContainer(int32 InitUpgradeLevel);

	UFUNCTION()
	void OnRep_HostUpgradeLevel();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Keep")
	void ResetContainer(AFortPlayerController* FortPC);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Keep")
	virtual void RestoreLoot();

protected:
	UFUNCTION()
	void OnRep_SearchedBy();

	UPROPERTY(ReplicatedUsing=OnRep_HostUpgradeLevel)
	int32 HostUpgradeLevel;

	UPROPERTY(ReplicatedUsing=OnRep_SearchedBy)
	TArray<TWeakObjectPtr<AFortPlayerState>> SearchedBy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keep")
	EKeepContainerType ContainerType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keep")
	bool bUseDefaultLootLogic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keep")
	bool bResetThisWhenKeepResets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keep", meta=(EditCondition="!bUseDefaultLootLogic"))
	FName ContainerNameKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keep", meta=(EditCondition="!bUseDefaultLootLogic"))
	TObjectPtr<UDataTable> ContainerDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keep", meta=(EditCondition="!bUseDefaultLootLogic"))
	bool bShowChoiceUI;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keep", meta=(EditCondition="bShowChoiceUI"))
	TArray<EFortItemType> ItemsInChoiceUI;

	UPROPERTY(Replicated)
	EFortRarity BestAvailableRarity;

	UPROPERTY(Replicated)
	int32 MaxItems;

};

