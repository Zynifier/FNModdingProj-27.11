// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPoolableWidgetInterface.h"
#include "CommonUserWidget.h"
#include "FortItemQuantityPair.h"
#include "FortTypes.h"
#include "FortItemQuantityListBase.generated.h"

class UFortItem;
class UFortItemDefinition;
class UFortItemQuantityListEntryBase;
class UObject;
enum class EFortItemInspectionMode : uint8;

USTRUCT(BlueprintType)
struct FFortItemEntryPreviewData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortItemEntryPreviewData")
	int32 Quantity;

	UPROPERTY(BlueprintReadOnly, Category="FortItemEntryPreviewData")
	EFortItemInspectionMode InspectMode;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemQuantityListBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Quantity List")
	TArray<UFortItemDefinition*> GetItemDefinitions();

	UFUNCTION(BlueprintPure, Category="Item Quantity List")
	bool IsEmptyList() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemInspectModeChanged();

	UFUNCTION(BlueprintCallable, Category="Item Quantity List")
	void SetItemDefinitionsAndQuantities(const TArray<FFortItemQuantityPair>& ItemQuantityPairs, const bool ShouldResetWidgets);

	UFUNCTION(BlueprintCallable, Category="Item Quantity List")
	void SetItemInspectMode(EFortItemInspectionMode InspectMode);

	UFUNCTION(BlueprintCallable, Category="Item Quantity List")
	void SetItemInstancesAndQuantities(const TArray<FFortItemInstanceQuantityPair>& ItemQuantityPairs, const bool ShouldResetWidgets);

	UFUNCTION(BlueprintCallable, Category="Item Quantity List")
	void SetItemToCompareDefinitionsAndQuantities(const TArray<FFortItemQuantityPair>& ItemToCompareQuantityPairs);

	UPROPERTY(BlueprintReadOnly, Category="Item Quantity List")
	EFortItemInspectionMode CurrentInspectMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Quantity List")
	bool bListenToInventoryChanges;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Quantity List")
	void AddListEntry(UFortItemQuantityListEntryBase* ListEntry);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Quantity List")
	TSubclassOf<UFortItemQuantityListEntryBase> ListEntryWidgetType;

	UPROPERTY()
	TArray<TObjectPtr<UObject>> ItemObjectsToKeepAlive;

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortItemDefinition>> FortItemDefinitions;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemQuantityListEntryBase : public UCommonUserWidget, public ICommonPoolableWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Quantity List Entry")
	void ClearPreviewData();

	UFUNCTION(BlueprintPure, Category="Item Quantity List Entry")
	UFortItemDefinition* GetItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="Item Quantity List Entry")
	UFortItem* GetItemInstance() const;

	UFUNCTION(BlueprintPure, Category="Item Quantity List Entry")
	void GetPreviewData(FFortItemEntryPreviewData& OutPreviewData) const;

	UFUNCTION(BlueprintPure, Category="Item Quantity List Entry")
	bool IsBeingPreviewed() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Item Quantity List Entry")
	void RefreshListEntry();

	UFUNCTION(BlueprintCallable, Category="Item Quantity List Entry")
	void SetItemDefinitionAndQuantity(const FFortItemQuantityPair& ItemQuantityPair, const bool ShouldTreatAsReset);

	UFUNCTION(BlueprintCallable, Category="Item Quantity List Entry")
	void SetItemInstanceAndQuantity(const FFortItemInstanceQuantityPair& ItemQuantityPair, const bool ShouldTreatAsReset);

	UFUNCTION(BlueprintCallable, Category="Item Quantity List Entry")
	void SetPreviewData(const FFortItemEntryPreviewData& PreviewData);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Quantity List Entry")
	void HandleDifferentItemOrQuantitySetBP(const bool IsBeingReset);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Quantity List Entry")
	void PreviewEnded();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Quantity List Entry")
	void PreviewStarted();

	UPROPERTY(BlueprintReadOnly, Category="Item Quantity List Entry")
	int32 Quantity;

};

