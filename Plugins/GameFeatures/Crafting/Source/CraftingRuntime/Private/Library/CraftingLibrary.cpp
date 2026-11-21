// Copyright Epic Games, Inc. All Rights Reserved.

#include "Library/CraftingLibrary.h"

#if WITH_EDITOR
void UCraftingLibrary::AddCraftingIngredientUIDataRow(UDataTable* DataTable, const FName& RowName, const FCraftingIngredientUIData& NewRowStruct)
{
}
#endif

void UCraftingLibrary::CancelCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, FCraftingMultiKey Key)
{
}

bool UCraftingLibrary::CanCraftFormula(const AFortPlayerController* FortPC, const AActor* CraftingObject, const FName CraftingFormulaRow, TArray<FCraftingIngredientQueryState>& OutIngredientStates, const int32 NumberToCraft)
{
	return false;
}

bool UCraftingLibrary::CanCraftFormulaWithAdditionalItems(const AFortPlayerController* FortPC, const AActor* CraftingObject, const FName CraftingFormulaRow, const TArray<FItemAndCount>& AdditionalItems, TArray<FCraftingIngredientQueryState>& OutIngredientStates, const int32 NumberToCraft)
{
	return false;
}

void UCraftingLibrary::ClaimCraftingResults(AFortPlayerController* Instigator, AActor* CraftingObject, FCraftingMultiKey Key)
{
}

void UCraftingLibrary::EjectItems(AFortPlayerController* Instigator, AActor* CraftingObject)
{
}

void UCraftingLibrary::GetAllCraftableFormulas(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<FName>& OutFormulas)
{
}

void UCraftingLibrary::GetAllCraftingFormulas(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<FName>& OutFormulas)
{
}

void UCraftingLibrary::GetAllValidIngredients(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<FGameplayTagContainer>& OutIngredients)
{
}

TArray<UFortWorldItem*> UCraftingLibrary::GetCraftedResults_TempItems(AActor* CraftingObject, FCraftingMultiKey Key)
{
	return TArray<UFortWorldItem*>();
}

bool UCraftingLibrary::GetCraftingFormulaIngredientRequirements(UObject* WorldContextObject, const FName& CraftingFormulaRow, TArray<FCraftingIngredientRequirement>& OutIngredientRequirements)
{
	return false;
}

FName UCraftingLibrary::GetCraftingFormulaNameBeingCrafted(AActor* CraftingObject, FCraftingMultiKey Key)
{
	return FName();
}

TArray<UFortWorldItem*> UCraftingLibrary::GetCraftingIngredients_TempItems(AActor* CraftingObject, FCraftingMultiKey Key)
{
	return TArray<UFortWorldItem*>();
}

UCraftingObjectComponent* UCraftingLibrary::GetCraftingObjectComponent(const AActor* CraftingObject)
{
	return nullptr;
}

ECraftingObjectState UCraftingLibrary::GetCraftingObjectCraftingState(AActor* CraftingObject, FCraftingMultiKey Key)
{
	return ECraftingObjectState();
}

float UCraftingLibrary::GetCraftingObjectCurrentCraftingStateEndTime(const AActor* CraftingObject, FCraftingMultiKey Key)
{
	return float();
}

float UCraftingLibrary::GetCraftingObjectCurrentCraftingStateStartTime(const AActor* CraftingObject, FCraftingMultiKey Key)
{
	return float();
}

float UCraftingLibrary::GetCraftingObjectCurrentCraftingStateTimeLeft(const AActor* CraftingObject, FCraftingMultiKey Key)
{
	return float();
}

float UCraftingLibrary::GetCraftingObjectPausedTime(const AActor* CraftingObject, FCraftingMultiKey Key)
{
	return float();
}

FGameplayTagContainer UCraftingLibrary::GetCraftingObjectTags(const AActor* CraftingObject)
{
	return FGameplayTagContainer();
}

void UCraftingLibrary::GetCraftingResultsForRowName(const UObject* WorldContextObject, const FName& CraftingFormulaRow, TArray<FItemAndCount>& OutResults, int32 NumToCraft)
{
}

TArray<UFortWorldItem*> UCraftingLibrary::GetIngredientsInCraftingObject(AActor* CraftingObject)
{
	return TArray<UFortWorldItem*>();
}

void UCraftingLibrary::GetKnownCraftingFormulas(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<FName>& OutFormulas)
{
}

FName UCraftingLibrary::GetLastCraftedItemFormulaName(AActor* CraftingObject)
{
	return FName();
}

float UCraftingLibrary::GetTimeToCraftRecipe(const AActor* CraftingObject, const FName& CraftingFormulaName)
{
	return float();
}

void UCraftingLibrary::GetUIDataForCraftingIngredientTags(UObject* WorldContextObject, const FGameplayTagContainer& IngredientTags, TArray<TSoftObjectPtr<UFortItemDefinition>>& OutItemDefs, TArray<TSoftObjectPtr<UObject>>& OutIcons)
{
}

void UCraftingLibrary::GetValidIngredientsInInventory(const AFortPlayerController* FortPC, const AActor* CraftingObject, TArray<UFortWorldItem*>& OutIngredients)
{
}

void UCraftingLibrary::GiveItemToCraftingObject(AFortPlayerController* Instigator, AActor* CraftingObject, const FFortItemEntry& ItemEntryToGrant)
{
}

bool UCraftingLibrary::IsValidIngredient(const AFortPlayerController* FortPC, const AActor* CraftingObject, const UFortItemDefinition* ItemDef)
{
	return false;
}

void UCraftingLibrary::PauseCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, bool bDecayPausedTime, FCraftingMultiKey Key)
{
}

void UCraftingLibrary::PickupItemAndStartCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, AFortPickup* Pickup, const FName& CraftingFormulaName, FCraftingMultiKey Key)
{
}

void UCraftingLibrary::ReportCraftingSuccess(AFortPlayerController* Instigator, AActor* CraftingObject, FCraftingMultiKey Key)
{
}

void UCraftingLibrary::ResumeCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, FCraftingMultiKey Key)
{
}

void UCraftingLibrary::StartCrafting(AFortPlayerController* Instigator, AActor* CraftingObject, const FName& CraftingFormulaName, const int32 NumberToCraft, FCraftingMultiKey Key)
{
}
