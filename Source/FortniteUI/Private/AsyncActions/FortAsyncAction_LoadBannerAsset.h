// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_LoadBannerAsset.generated.h"

class UFortAsyncAction_LoadBannerAsset;
class UMaterialInstanceDynamic;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBannerAssetLoadComplete, UObject*, LoadedAsset, UMaterialInstanceDynamic*, MIDRef, FName, BannerColorName);

UCLASS()
class UFortAsyncAction_LoadBannerAsset : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Banner Async Load Asset", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_LoadBannerAsset* AsyncLoadBannerAsset(UObject* WorldContextObject, TSoftObjectPtr<UObject> AssetToLoad, UMaterialInstanceDynamic* MIDRef, FName BannerColorName);

	UPROPERTY(BlueprintAssignable)
	FBannerAssetLoadComplete BannerAssetLoadComplete;

};

