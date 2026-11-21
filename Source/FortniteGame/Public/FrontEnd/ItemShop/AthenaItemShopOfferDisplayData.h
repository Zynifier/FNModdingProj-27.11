// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AthenaItemShopOfferDisplayData.generated.h"

class UMaterialInterface;

UCLASS(MinimalAPI, BlueprintType)
class UAthenaItemShopOfferDisplayData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Utility")
	void AddPresentation(UMaterialInterface* PresentationToAdd);

	UFUNCTION(BlueprintPure, Category="Utility")
	bool HasNoPresentations() const;

	UPROPERTY(EditAnywhere, Category="Presentation Swapping")
	TArray<TSoftObjectPtr<UMaterialInterface>> Presentations;

};

