// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortSortFilterVM.generated.h"

class UFortFilterItemVM;
class UFortSortFilterSearchTextVM;
class UFortSortItemVM;

UCLASS(Abstract)
class UFortSortFilterItemVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool DisplayCount() const;

private:
	UPROPERTY(BlueprintReadOnly, Category="FortSortFilterItemVM", meta=(AllowPrivateAccess))
	FText Label;

	UPROPERTY(BlueprintReadOnly, Category="FortSortFilterItemVM", meta=(AllowPrivateAccess))
	int32 Count;

	UPROPERTY(BlueprintReadWrite, Category="FortSortFilterItemVM", meta=(AllowPrivateAccess))
	bool bIsSeparator;

	UPROPERTY(BlueprintReadWrite, Category="FortSortFilterItemVM", meta=(AllowPrivateAccess))
	bool bAutoHide;

	UPROPERTY(BlueprintReadOnly, Category="FortSortFilterItemVM", meta=(AllowPrivateAccess))
	bool bIsActive;

	UPROPERTY(BlueprintReadOnly, Category="FortSortFilterItemVM", meta=(AllowPrivateAccess))
	bool bIsVisible;

};

UCLASS()
class UFortFilterItemVM : public UFortSortFilterItemVM
{
	GENERATED_BODY()

};

UCLASS()
class UFortSortFilterSearchTextVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="FortSortFilterSearchTextVM", meta=(AllowPrivateAccess))
	FText SearchText;

};

UCLASS()
class UFortSortFilterVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasFilterItems() const;

	UFUNCTION(BlueprintPure)
	bool HasSearchText() const;

	UFUNCTION(BlueprintPure)
	bool HasSortItems() const;

private:
	UPROPERTY(BlueprintReadOnly, Category="FortSortFilterVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortSortItemVM>> SortItems;

	UPROPERTY(BlueprintReadOnly, Category="FortSortFilterVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortFilterItemVM>> FilterItems;

	UPROPERTY(BlueprintReadOnly, Category="FortSortFilterVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortSortFilterSearchTextVM> SearchText;

	UPROPERTY(BlueprintReadWrite, Category="FortSortFilterVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortSortItemVM> ActiveSortItem;

	UPROPERTY(BlueprintReadWrite, Category="FortSortFilterVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortFilterItemVM> ActiveFilterItem;

};

UCLASS()
class UFortSortItemVM : public UFortSortFilterItemVM
{
	GENERATED_BODY()

};

