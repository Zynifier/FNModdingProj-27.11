// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortItemAndCount.h"
#include "Items/FortItemEntry.h"
#include "Types/CraftingTypes.h"
#include "CraftingLibrary.generated.h"

class AActor;
class AFortPickup;
class AFortPlayerController;
class UCraftingObjectComponent;
class UDataTable;
class UFortItemDefinition;
class UFortWorldItem;
class UObject;
enum class ECraftingObjectState : uint8;

UCLASS(meta=(ScriptName="CraftingLibrary"))
class CRAFTINGRUNTIME_API UCraftingLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Crafting")
	static void AddCraftingIngredientUIDataRow(UDataTable* DataTable, const FName& RowName, const FCraftingIngredientUIData& NewRowStruct);
#endif

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static void CancelCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static bool CanCraftFormula(const AFortPlayerController* FortPC, const AActor* CraftingObject, const FName CraftingFormulaRow, TArray<FCraftingIngredientQueryState>& OutIngredientStates, const int32 NumberToCraft = 1);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static bool CanCraftFormulaWithAdditionalItems(const AFortPlayerController* FortPC, const AActor* CraftingObject, const FName CraftingFormulaRow, const TArray<FItemAndCount>& AdditionalItems, TArray<FCraftingIngredientQueryState>& OutIngredientStates, const int32 NumberToCraft = 1);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static void ClaimCraftingResults(AFortPlayerController* Instigator, AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static void EjectItems(AFortPlayerController* Instigator, AActor* CraftingObject);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static void GetAllCraftableFormulas(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<FName>& OutFormulas);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static void GetAllCraftingFormulas(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<FName>& OutFormulas);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static void GetAllValidIngredients(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<FGameplayTagContainer>& OutIngredients);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(DisplayName="GetCraftedResults", CPP_Default_Key="()"))
	static TArray<UFortWorldItem*> GetCraftedResults_TempItems(AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool GetCraftingFormulaIngredientRequirements(UObject* WorldContextObject, const FName& CraftingFormulaRow, TArray<FCraftingIngredientRequirement>& OutIngredientRequirements);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static FName GetCraftingFormulaNameBeingCrafted(AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(DisplayName="GetCraftingIngredients", CPP_Default_Key="()"))
	static TArray<UFortWorldItem*> GetCraftingIngredients_TempItems(AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintPure, Category="Crafting")
	static UCraftingObjectComponent* GetCraftingObjectComponent(const AActor* CraftingObject);

	UFUNCTION(BlueprintPure, Category="Crafting", meta=(CPP_Default_Key="()"))
	static ECraftingObjectState GetCraftingObjectCraftingState(AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static float GetCraftingObjectCurrentCraftingStateEndTime(const AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static float GetCraftingObjectCurrentCraftingStateStartTime(const AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static float GetCraftingObjectCurrentCraftingStateTimeLeft(const AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static float GetCraftingObjectPausedTime(const AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintPure, Category="Crafting")
	static FGameplayTagContainer GetCraftingObjectTags(const AActor* CraftingObject);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(DisplayName="GetCraftingResults"))
	static void GetCraftingResultsForRowName(const UObject* WorldContextObject, const FName& CraftingFormulaRow, TArray<FItemAndCount>& OutResults, int32 NumToCraft = 1);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(DisplayName="GetCraftingIngredients"))
	static TArray<UFortWorldItem*> GetIngredientsInCraftingObject(AActor* CraftingObject);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static void GetKnownCraftingFormulas(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<FName>& OutFormulas);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static FName GetLastCraftedItemFormulaName(AActor* CraftingObject);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static float GetTimeToCraftRecipe(const AActor* CraftingObject, const FName& CraftingFormulaName);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static void GetUIDataForCraftingIngredientTags(UObject* WorldContextObject, const FGameplayTagContainer& IngredientTags, TArray<TSoftObjectPtr<UFortItemDefinition>>& OutItemDefs, TArray<TSoftObjectPtr<UObject>>& OutIcons);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static void GetValidIngredientsInInventory(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<UFortWorldItem*>& OutIngredients);

	UFUNCTION(BlueprintPure, Category="Crafting")
	static void GiveItemToCraftingObject(AFortPlayerController* Instigator, AActor* CraftingObject, const FFortItemEntry& ItemEntryToGrant);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	static bool IsValidIngredient(const AFortPlayerController* FortPC, const AActor* CraftingObject, const UFortItemDefinition* ItemDef);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_bDecayPausedTime="false", CPP_Default_Key="()"))
	static void PauseCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, bool bDecayPausedTime, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static void PickupItemAndStartCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, AFortPickup* Pickup, const FName& CraftingFormulaName, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static void ReportCraftingSuccess(AFortPlayerController* Instigator, AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_Key="()"))
	static void ResumeCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(BlueprintCallable, Category="Crafting", meta=(CPP_Default_NumberToCraft="1", CPP_Default_Key="()"))
	static void StartCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, const FName& CraftingFormulaName, const int32 NumberToCraft, FCraftingMultiKey Key);

};

