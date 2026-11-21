// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortTemporaryItemsRewardVM.generated.h"

class UFortAccountItemDefinition;

UCLASS()
class UFortTemporaryItemsRewardVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FortTemporaryItemsRewardVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortAccountItemDefinition> ItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="FortTemporaryItemsRewardVM", meta=(AllowPrivateAccess))
	bool bIsOwned;

};

