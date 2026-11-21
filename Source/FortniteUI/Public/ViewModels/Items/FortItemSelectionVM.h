// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortItemSelectionVM.generated.h"

class UFortItemVM;
class UFortLockerCategoryItemVM;

UCLASS(Config=Game)
class UFortItemSelectionVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearHoveredCategory(const UFortLockerCategoryItemVM* CurrentHoveredCategory);

	UFUNCTION(BlueprintCallable)
	void ClearHoveredItem(const UFortItemVM* CurrentHoveredItem);

	UFUNCTION(BlueprintCallable)
	void ClearSelectedCategory(const UFortLockerCategoryItemVM* CurrentSelectedCategory);

	UFUNCTION(BlueprintCallable)
	void ClearSelectedItem(const UFortItemVM* CurrentSelectedItem);

	UFUNCTION(BlueprintPure)
	UFortLockerCategoryItemVM* GetPreviewCategory() const;

	UFUNCTION(BlueprintPure)
	UFortItemVM* GetPreviewItem() const;

	UFUNCTION(BlueprintCallable)
	void Reset();

	UPROPERTY(EditAnywhere, Config, Category="FortItemSelectionVM")
	float PendingCategoryPreviewDelay;

	UPROPERTY(EditAnywhere, Config, Category="FortItemSelectionVM")
	float PendingItemPreviewDelay;

private:
	UPROPERTY(BlueprintReadWrite, Category="FortItemSelectionVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortLockerCategoryItemVM> HoveredCategory;

	UPROPERTY(BlueprintReadWrite, Category="FortItemSelectionVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortItemVM> HoveredItem;

	UPROPERTY(BlueprintReadWrite, Category="FortItemSelectionVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortLockerCategoryItemVM> SelectedCategory;

	UPROPERTY(BlueprintReadWrite, Category="FortItemSelectionVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortItemVM> SelectedItem;

	UPROPERTY(BlueprintReadWrite, Category="FortItemSelectionVM", meta=(AllowPrivateAccess))
	bool bPreviewCategoryOnHover;

	UPROPERTY(BlueprintReadWrite, Category="FortItemSelectionVM", meta=(AllowPrivateAccess))
	bool bPreviewItemOnHover;

};

