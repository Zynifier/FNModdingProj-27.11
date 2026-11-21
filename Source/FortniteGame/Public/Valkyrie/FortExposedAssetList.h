// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortExposedAssetList.generated.h"

class UFortExposedAssetRule;

UCLASS(MinimalAPI)
class UFortExposedAssetList : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(meta=(CallInEditor="true"))
	void RefreshAllRules();
#endif

protected:
	UPROPERTY(EditAnywhere, Export, Category="Assets", meta=(EditInline="true", ShowOnlyInnerProperties, TitleProperty="RuleName"))
	TArray<UFortExposedAssetRule*> ExposedAssetRules;

};

