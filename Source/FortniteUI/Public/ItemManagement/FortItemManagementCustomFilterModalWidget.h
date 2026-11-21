// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInventoryFilterEnum.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortItemManagementCustomFilterModalWidget.generated.h"

class UFortItemManagementScreen;
enum class EFortInventoryCustomFilter : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemManagementCustomFilterModalWidget : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Item Management|Custom Filter")
	void CommitCustomFilters();

	UFUNCTION(BlueprintCallable, Category="Item Management|Custom Filter")
	void DisableAllFilters();

	UFUNCTION(BlueprintCallable, Category="Item Management|Custom Filter")
	void EnableAllFilters();

	UFUNCTION(BlueprintPure, Category="Item Management|Custom Filter")
	bool IsCustomFilterEnabled(EFortInventoryCustomFilter Filter) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Custom Filter")
	void OnBeginCommitCustomFilter();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Custom Filter")
	void OnCustomFilterSetUpdated();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Custom Filter")
	void OnEndCommitCustomFilter(bool bWasSuccessful);

	UFUNCTION(BlueprintCallable, Category="Item Management|Custom Filter")
	void ToggleFilter(EFortInventoryCustomFilter Filter);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementCustomFilterModalWidget")
	TWeakObjectPtr<UFortItemManagementScreen> HostItemManagementScreen;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Custom Filter")
	TArray<EFortInventoryCustomFilter> AvailableFilters;

private:
	UPROPERTY(Transient)
	TSet<EFortInventoryCustomFilter> LocalCustomFilterSet;

};

