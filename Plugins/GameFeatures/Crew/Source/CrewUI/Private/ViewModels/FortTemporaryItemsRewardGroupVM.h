// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortTemporaryItemsRewardGroupVM.generated.h"

class UFortTemporaryItemsRewardVM;

UCLASS()
class UFortTemporaryItemsRewardGroupVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FortTemporaryItemsRewardGroupVM", meta=(AllowPrivateAccess))
	EAthenaCustomizationCategory Category;

	UPROPERTY(BlueprintReadOnly, Category="FortTemporaryItemsRewardGroupVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortTemporaryItemsRewardVM>> Rewards;

};

