// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "ViewModels/Utilities/FortSortFilterVM.h"
#include "FortLockerSortFilterVM.generated.h"

class UFortItemVM;
class UFortLockerCategoryConfig;
class UFortLockerCategoryFilterConfig;
class UFortLockerCategoryItemVM;
class UFortLockerCategorySortConfig;
class UFortLockerCategoryVM;
class UFortLockerFilterItemVM;
class UFortSortFilterVM;

UCLASS()
class UFortLockerCategoryFilterVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanManageArchive(bool& bOutIsArchiving) const;

	UFUNCTION(BlueprintPure)
	const UFortItemVM* GetFirstActualValidItem(bool bGetEquippedItem = true) const;

	UFUNCTION(BlueprintPure)
	const UFortItemVM* GetFirstValidItem(bool bGetEquippedItem = true) const;

	UFUNCTION(BlueprintPure)
	bool IsFiltering() const;

private:
	UPROPERTY(BlueprintReadWrite, Category="FortLockerCategoryFilterVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortLockerCategoryVM> Category;

	UPROPERTY(BlueprintReadWrite, Category="FortLockerCategoryFilterVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortLockerCategoryItemVM> CategoryItem;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryFilterVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortSortFilterVM> SortFilter;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryFilterVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortLockerFilterItemVM> ArchiveFilter;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryFilterVM", meta=(AllowPrivateAccess))
	TArray<UFortItemVM*> FilteredItems;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryFilterVM", meta=(AllowPrivateAccess))
	int32 ArchivedItemsCount;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryFilterVM", meta=(AllowPrivateAccess))
	bool bHasEquippableItems;

	UPROPERTY(BlueprintReadWrite, Category="FortLockerCategoryFilterVM", meta=(AllowPrivateAccess))
	bool bShowArchivedItems;

};

UCLASS(Abstract)
class UFortLockerFilterItemVM : public UFortFilterItemVM
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const UFortLockerCategoryFilterConfig* GetConfig() const;

};

UCLASS(Abstract)
class UFortLockerSearchTextVM : public UFortSortFilterSearchTextVM
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const UFortLockerCategoryConfig* GetConfig() const;

};

UCLASS(Abstract)
class UFortLockerSortItemVM : public UFortSortItemVM
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const UFortLockerCategorySortConfig* GetConfig() const;

};

