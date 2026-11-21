// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortPersistentResourceItemDefinition.h"
#include "FortConditionalResourceItemDefinition.generated.h"

class UFortAccountItemDefinition;

UENUM()
enum class EFortConditionalResourceItemTest : uint8
{
	CanEarnMtx = 0,
};

UCLASS(BlueprintType)
class UFortConditionalResourceItemDefinition : public UFortPersistentResourceItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortConditionalAccountItemDefinition")
	EFortConditionalResourceItemTest Condition;

	UPROPERTY(EditDefaultsOnly, Category="FortConditionalAccountItemDefinition", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortAccountItemDefinition> PassedConditionItem;

	UPROPERTY(EditDefaultsOnly, Category="FortConditionalAccountItemDefinition", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortAccountItemDefinition> FailedConditionItem;

};

