// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "ViewModels/FortPerUserViewModel.h"
#include "FortTemporaryItemsVM.generated.h"

class UFortTemporaryItemsManager;
class UFortTemporaryItemsRewardGroupVM;

UCLASS()
class UFortTemporaryItemsVM : public UFortPerUserViewModel
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FortTemporaryItemsVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortTemporaryItemsRewardGroupVM>> RewardGroups;

	UPROPERTY(BlueprintReadOnly, Category="FortTemporaryItemsVM", meta=(AllowPrivateAccess))
	FDateTime ExpirationDate;

	UPROPERTY(Transient)
	TObjectPtr<UFortTemporaryItemsManager> TemporaryItemsManager;

};

