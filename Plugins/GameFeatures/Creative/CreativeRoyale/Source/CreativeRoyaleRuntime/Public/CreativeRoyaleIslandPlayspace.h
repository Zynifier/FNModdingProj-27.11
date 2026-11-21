// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/FortPlayspace.h"
#include "CreativeRoyaleIslandPlayspace.generated.h"

class AActor;
class UCreativeRoyalePlayspaceComponent_LoadingScreen;
class UFortPlayspaceComponent_WorldTimeOfDayOverride;
class UFortPoiSwapManager;
class UFortProjectEditComponent_CreativeRoyale;
class UPlayspaceComponent_ActorMemoryTracker;
class UPlayspaceComponent_CreativeLoadingStateProxy;
class UPlayspaceComponent_CreativeModifyEmotes;
class UPlayspaceComponent_DeviceTracking;
class UPlayspaceComponent_PlayStopPauseManager;
class UPlayspaceComponent_SpatialGameplay;

UCLASS(Config=CreativeRoyalePlayspace, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class CREATIVEROYALERUNTIME_API ACreativeRoyaleIslandPlayspace : public AFortPlayspace
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Export, Category="CreativeRoyaleIslandPlayspace", meta=(EditInline="true"))
	TObjectPtr<UFortProjectEditComponent_CreativeRoyale> ProjectEditComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_PlayStopPauseManager> PlayStopPauseManager;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_CreativeLoadingStateProxy> CreativeLoadingStateProxy;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_SpatialGameplay> SpatialGameplayComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_DeviceTracking> DeviceTrackerComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_CreativeModifyEmotes> CreativeModifyEmotesComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayspaceComponent_WorldTimeOfDayOverride> WorldTimeOfDayOverrideComponent;

	UPROPERTY(EditDefaultsOnly, Export, Category="CreativeRoyaleIslandPlayspace", meta=(EditInline="true"))
	TObjectPtr<UCreativeRoyalePlayspaceComponent_LoadingScreen> LoadingScreenComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_ActorMemoryTracker> ActorMemoryTracker;

	UPROPERTY(EditDefaultsOnly, Export, Category="CreativeRoyaleIslandPlayspace", meta=(EditInline="true"))
	TObjectPtr<UFortPoiSwapManager> FortPoiSwapManager;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> FoundActors;

	UPROPERTY(Config)
	int32 IslandMemoryBudget;

	UPROPERTY(Config)
	float MaxMemorySamplingHeight;

	UPROPERTY(Config)
	float MaxMemorySamplingCellSize;

};

