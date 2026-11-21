// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ViewModels/Items/FortItemVM.h"
#include "AthenaItemVM.generated.h"

class UFortItem;
class UFortItemDefinition;

UCLASS()
class UAthenaItemVM : public UFortItemVM
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="AthenaItemVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortItem> ItemInstance;

	UPROPERTY(BlueprintReadOnly, Category="AthenaItemVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortItemDefinition> ItemDefinition;

};

