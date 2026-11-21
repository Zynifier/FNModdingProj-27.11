// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EpicStreamMediaSource.h"
#include "FortStreamMediaSource.generated.h"

class UFortDownloadLocalizedOverlays;
class UFortMediaRegionLockComponent;

UCLASS(Config=Game, MinimalAPI, BlueprintType, HideCategories=("Object", "Object"))
class UFortStreamMediaSource : public UEpicStreamMediaSource
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetLocalizedOverlays(UFortDownloadLocalizedOverlays* InOverlays);

	UPROPERTY(EditDefaultsOnly, Category="Player")
	TObjectPtr<UFortDownloadLocalizedOverlays> FortDownloadLocalizedOverlays;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMediaRegionLockComponent> RegionLock;

};

