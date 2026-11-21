// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UI/FrontEnd/FortLockerConfig.h"
#include "FortLockerCategoryVM.generated.h"

class AFortPlayerController;
class UFortItemVM;
class UFortLockerCategoryConfig;
class UFortLockerCategoryGroupConfig;
class UFortLockerCategoryItemVM;
class UFortLockerCategoryVM;

UCLASS()
class UFortLockerCategoryGroupVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetAreAnyItemsArchived() const;

	UFUNCTION(BlueprintPure)
	bool GetAreAnyItemsNew() const;

	UFUNCTION(BlueprintPure)
	const UFortLockerCategoryGroupConfig* GetConfig() const;

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<UFortLockerCategoryGroupConfig> CategoryGroupConfig;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryGroupVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortLockerCategoryVM>> Categories;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryGroupVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortLockerCategoryItemVM>> CategoryItems;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryGroupVM", meta=(AllowPrivateAccess))
	int32 NewItemsInCategoryGroupCount;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryGroupVM", meta=(AllowPrivateAccess))
	int32 ArchivedItemsInCategoryGroupCount;

};

UCLASS()
class UFortLockerCategoryItemVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FString GetAnalyticsName() const;

	UFUNCTION(BlueprintPure)
	const FFortLockerCategorySlotInfo& GetSlotInfo() const;

private:
	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryItemVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortLockerCategoryVM> Category;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryItemVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortItemVM> EquippedItem;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryItemVM", meta=(AllowPrivateAccess))
	int32 SlotIndex;

};

UCLASS(Abstract)
class UFortLockerCategoryVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetAreAnyItemsArchived() const;

	UFUNCTION(BlueprintPure)
	bool GetAreAnyItemsNew() const;

	UFUNCTION(BlueprintPure)
	bool GetAreAnyItemsNotArchived() const;

	UFUNCTION(BlueprintPure)
	const UFortLockerCategoryConfig* GetConfig() const;

	UFUNCTION(BlueprintPure)
	int32 GetItemsInCategoryCount() const;

	UPROPERTY(EditDefaultsOnly, Category="FortLockerCategoryVM")
	int32 Prority;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> PlayerController;

	UPROPERTY(Transient)
	TObjectPtr<UFortLockerCategoryConfig> Config;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryVM", meta=(AllowPrivateAccess))
	int32 NewItemsInCategoryCount;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryVM", meta=(AllowPrivateAccess))
	int32 ArchivedItemsInCategoryCount;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryVM", meta=(AllowPrivateAccess))
	int32 NonArchivedItemsInCategoryCount;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerCategoryVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortItemVM>> AllItemsInCategory;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemVM>> EquippedItems;

};

