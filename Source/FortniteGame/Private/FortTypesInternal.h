// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Athena/AthenaPickerTypeEnum.h"
#include "FortItemQuantityPair.h"
#include "FortTypes.h"
#include "FortTypesInternal.generated.h"

class ABuildingActor;
class AFortPlayerPawnAthena;
class UFortAccountItemDefinition;
class UFortCardPackItemDefinition;
enum class EChangeInStructDetected : uint8;
enum class EInventoryContentSortType : uint8;

USTRUCT()
struct FAthenaPickResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAthenaPickerType PickType;

	UPROPERTY()
	TObjectPtr<ABuildingActor> FoundBuildingActor;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawnAthena> FoundPlayer;

};

USTRUCT(BlueprintType)
struct FCostOnlyRecipe : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	TArray<FFortItemQuantityPair> RecipeCosts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	FGameplayTagContainer RequiredCatalysts;

};

USTRUCT(BlueprintType)
struct FFortCatalogMetaPreload
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCatalogInfo")
	TArray<TSoftObjectPtr<UFortAccountItemDefinition>> ChaseItems;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCatalogInfo")
	TSoftObjectPtr<UFortCardPackItemDefinition> PackDefinition;

};

USTRUCT()
struct FFortGameAnalyticsSessionResponse
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SessionID;

	UPROPERTY()
	FString AppID;

	UPROPERTY()
	FString AppVersion;

	UPROPERTY()
	FString DeviceType;

	UPROPERTY()
	FString DeviceModel;

	UPROPERTY()
	FString OS;

};

UCLASS()
class UFortChangeMonitoringStructHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(CustomThunk, BlueprintCallable, meta=(CustomStructureParam="CheckStruct", ExpandEnumAsExecs="ChangeState"))
	static void CheckIsDirty(const FFortChangeMonitoringStruct& CheckStruct, EChangeInStructDetected& ChangeState);
	DECLARE_FUNCTION(execCheckIsDirty);

	UFUNCTION(CustomThunk, BlueprintCallable, meta=(CustomStructureParam="CheckStruct", ExpandEnumAsExecs="ChangeState"))
	static void ClearDirty(UPARAM(ref) FFortChangeMonitoringStruct& CheckStruct, EChangeInStructDetected& ChangeState);
	DECLARE_FUNCTION(execClearDirty);

};

UCLASS()
class UFortInventorySortFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Inventory|Sorting")
	static FText GetCriterionDisplayNameOfSortType(EInventoryContentSortType SortType);

};

