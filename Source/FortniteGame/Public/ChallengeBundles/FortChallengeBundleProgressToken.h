// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortChallengeBundleProgressToken.generated.h"

class UFortChallengeBundleItemDefinition;

UCLASS()
class UFortChallengeBundleProgressToken : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FString bundle_template;

	UPROPERTY()
	TObjectPtr<UFortChallengeBundleItemDefinition> BundleItemDef;

	UPROPERTY()
	TArray<int32> completion_bits;

	UPROPERTY()
	TArray<int32> completion_times;

};

