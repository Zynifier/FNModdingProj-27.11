// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortGameFeatureData.h"
#include "StoreSelectionData.generated.h"

class UFortStoreSelectionScreen;

UCLASS()
class UFortStoreSelectionData : public UFortGameFeatureData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortStoreSelectionData")
	TSoftClassPtr<UFortStoreSelectionScreen> StoreSelectionScreenClass;

	UPROPERTY(EditAnywhere, Category="FortStoreSelectionData")
	FText RegularStoreSelectedText;

	UPROPERTY(EditAnywhere, Category="FortStoreSelectionData")
	FText NonRegularStoreSelectedText;

};

