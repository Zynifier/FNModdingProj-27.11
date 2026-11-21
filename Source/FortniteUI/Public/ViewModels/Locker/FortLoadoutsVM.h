// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "ViewModels/FortPerUserViewModel.h"
#include "FortLoadoutsVM.generated.h"

class UFortCosmeticLockerItem;
class UFortItemVM;
class UFortLoadoutVM;
class UFortLoadoutsVM;
class UFortLockerCategoryConfig;
class UUserWidget;

UCLASS()
class UFortLoadoutListVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortLoadoutListVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortLoadoutVM>> Loadouts;

	UPROPERTY(BlueprintReadWrite, Category="FortLoadoutListVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortLoadoutsVM> LoadoutSystem;

};

UCLASS()
class UFortLoadoutVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FText GetDefaultName() const;

	UFUNCTION(BlueprintPure, meta=(WorldContext="ContextWidget"))
	UFortItemVM* GetFirstValidItem(UUserWidget* ContextWidget, const UFortLockerCategoryConfig* Category) const;

	UFUNCTION(BlueprintPure, meta=(WorldContext="ContextWidget"))
	UFortItemVM* GetItem(UUserWidget* ContextWidget, const UFortLockerCategoryConfig* Category, int32 SlotIndex) const;

	UFUNCTION(BlueprintPure)
	const UFortCosmeticLockerItem* GetLockerItem();

	UFUNCTION(BlueprintPure)
	bool IsValid() const;

private:
	UPROPERTY(BlueprintReadOnly, Category="FortLoadoutVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortItemVM>> Items;

	UPROPERTY(BlueprintReadOnly, Category="FortLoadoutVM", meta=(AllowPrivateAccess))
	FText Name;

	UPROPERTY(BlueprintReadOnly, Category="FortLoadoutVM", meta=(AllowPrivateAccess))
	int32 NumArchived;

	UPROPERTY(Transient)
	UFortCosmeticLockerItem* LockerItem;

};

UCLASS()
class UFortLoadoutsVM : public UFortPerUserViewModel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetCanEnableRandomization() const;

	UFUNCTION(BlueprintPure)
	bool GetHasLoadouts() const;

	UFUNCTION(BlueprintCallable)
	void ToggleRandomEnabled();

private:
	UPROPERTY(BlueprintReadOnly, Category="FortLoadoutsVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortLoadoutVM> ActiveLoadout;

	UPROPERTY(BlueprintReadOnly, Category="FortLoadoutsVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortLoadoutVM> LastAppliedLoadout;

	UPROPERTY(BlueprintReadOnly, Category="FortLoadoutsVM", meta=(AllowPrivateAccess))
	bool bIsModified;

	UPROPERTY(BlueprintReadOnly, Category="FortLoadoutsVM", meta=(AllowPrivateAccess))
	bool bIsRandomEnabled;

};

