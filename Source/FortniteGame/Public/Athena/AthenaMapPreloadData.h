// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AthenaMapPreloadData.generated.h"

class UObject;

UCLASS(MinimalAPI)
class UAthenaMapPreloadData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly, Category="Results")
	TArray<FName> PackageNames;

	UPROPERTY(VisibleAnywhere, Category="Results")
	TArray<int32> PackageCountToMemLookup;

	UPROPERTY(EditAnywhere, Category="Settings")
	int32 PackageCountStepSize;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Settings")
	TArray<FName> LevelsToSearch;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Settings")
	TArray<TSubclassOf<UObject>> AllowedClasses;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Settings")
	int32 MaxPackageCount;
#endif

};

