// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortValkyrieData.generated.h"

class UObject;

UCLASS()
class UFortValkyrieData : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Assets", meta=(AssetBundles="Client,Server"))
	TArray<TSoftObjectPtr<UObject>> Assets;

};

