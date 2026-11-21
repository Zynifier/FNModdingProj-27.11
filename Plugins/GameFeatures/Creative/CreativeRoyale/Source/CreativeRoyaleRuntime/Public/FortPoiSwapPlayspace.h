// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AsyncTaskQueue.h"
#include "OnlineLinkId.h"
#include "Playspaces/FortPlayspace.h"
#include "FortPoiSwapPlayspace.generated.h"

class AActor;
class AFortPoiSwapPlayspace;
class AFortPoiVolume;
class UFortCreativeRealEstatePlotItem;
class UFortLevelSaveComponent;
class UPlaysetLevelStreamComponent;
class USceneComponent;
enum class EFortPoiSwapUserContentState : uint8;

UENUM(BlueprintType)
enum class EFortPoiSwapUserContentState : uint8
{
	Unloaded = 0,
	// No content is loaded or in the process of loading

	Loading = 1,
	// Content is in the process of loading

	Loaded = 2,
	// Content has fully loaded

	Unloading = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContentStateChanged, AFortPoiSwapPlayspace*, PoiSwapPlayspace, const EFortPoiSwapUserContentState&, ContentLoadingState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPreContentUnload, AFortPoiSwapPlayspace*, PoiSwapPlayspace);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPoiSwapPlayspace : public AFortPlayspace
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnContentStateChanged OnContentStateChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnPreContentUnload OnPreContentUnloadDelegate;

protected:
	UFUNCTION()
	void OnUserContentLoaded();

	UFUNCTION()
	void OnUserContentUnloaded(const FAsyncTaskResult& Result);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortLevelSaveComponent> LevelSaveComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlaysetLevelStreamComponent> PlaysetLevelStreamComponent;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPoiVolume> PoiToReplace;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortCreativeRealEstatePlotItem> PlotToLoad;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortCreativeRealEstatePlotItem> LoadedPlot;

	UPROPERTY(Transient)
	FOnlineLinkId LinkCodeToLoad;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> SpawnedActors;

};

