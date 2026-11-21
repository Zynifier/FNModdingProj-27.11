// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ViewModels/FortPerUserViewModel.h"
#include "FortLockerVM.generated.h"

class UFortLockerCategoryGroupVM;

UCLASS()
class UFortLockerVM : public UFortPerUserViewModel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearAllNewItemFlags();

	UFUNCTION(BlueprintCallable)
	void ClearAllSlots();

	UFUNCTION(BlueprintCallable)
	void RandomizeAllSlots();

private:
	UPROPERTY(BlueprintReadOnly, Category="FortLockerVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortLockerCategoryGroupVM>> CategoryGroups;

	UPROPERTY(BlueprintReadOnly, Category="FortLockerVM", meta=(AllowPrivateAccess))
	bool bAreAnyItemsNew;

};

