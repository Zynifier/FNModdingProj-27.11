// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortValkyrieSentryAssets.generated.h"

class UObject;

UCLASS()
class UFortValkyrieSentryAssets : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Assets", meta=(AssetBundles="Client,Server"))
	TArray<TSoftObjectPtr<UObject>> Assets;

};

