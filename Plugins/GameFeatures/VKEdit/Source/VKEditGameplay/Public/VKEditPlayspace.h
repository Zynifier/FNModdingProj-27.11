// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "DownloadOnDemand/DownloadOnDemandEventContexts.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "Playspaces/FortPlayspace.h"
#include "VKEditPlayspace.generated.h"

class AFortMinigameSettingsBuilding;
class AFortWorldManager;
class UFortCreativeDynamicXpComponent;
class UFortLevelStreamComponent;
class UFortPlayspaceComponent_NaniteSettingsOverride;
class UFortPlayspaceComponent_WorldTimeOfDayOverride;
class UFortProjectEditComponent;
class UFortVolumeObjectTrackingComponent;
class UPlayspaceComponent_ActorMemoryTracker;
class UPlayspaceComponent_CreativeInventory;
class UPlayspaceComponent_CreativeLoadingStateProxy;
class UPlayspaceComponent_CreativeModifyEmotes;
class UPlayspaceComponent_DeviceTracking;
class UPlayspaceComponent_EditConnectionManager;
class UPlayspaceComponent_LiveEdit;
class UPlayspaceComponent_PlayStopPauseManager;
class UPlayspaceComponent_PlayerPawnOverrides;
class UPlayspaceComponent_PlaysetRootSpawner;
class UPlayspaceComponent_SpatialGameplay;
class UPlayspaceComponent_VKEditCreativeToolsPermission;

UCLASS(Config=Game, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class VKEDITGAMEPLAY_API AVKEditPlayspace : public AFortPlayspace
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnClientActivatedContent(const FUniqueNetIdRepl& ClientNetId) const;

	UPROPERTY(EditDefaultsOnly, Category="VKEditPlayspace")
	TSoftClassPtr<AFortMinigameSettingsBuilding> EditorOnlyMinigameSettingsMachineClassToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="VKEditPlayspace")
	TSoftClassPtr<AFortWorldManager> EditorOnlyWorldManagerClassToSpawn;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortLevelStreamComponent> LevelStreamComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortProjectEditComponent> ProjectEditComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_PlayStopPauseManager> PlayStopPauseManager;

	UPROPERTY(EditDefaultsOnly, Export, Category="VKEditPlayspace", meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_EditConnectionManager> EditConnectionManager;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_LiveEdit> LiveEditComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_VKEditCreativeToolsPermission> CreativeToolsPermission;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_CreativeLoadingStateProxy> CreativeLoadingStateProxy;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_SpatialGameplay> SpatialGameplayComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortVolumeObjectTrackingComponent> ObjectTrackingComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_DeviceTracking> DeviceTrackerComponent;

	UPROPERTY(EditDefaultsOnly, Export, Category="VKEditPlayspace", meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_CreativeInventory> CreativeInventoryComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_ActorMemoryTracker> ActorMemoryTrackerComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortCreativeDynamicXpComponent> FortCreativeDynamicXp;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_CreativeModifyEmotes> CreativeModifyEmotesComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayspaceComponent_WorldTimeOfDayOverride> WorldTimeOfDayOverrideComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayspaceComponent_NaniteSettingsOverride> NaniteSettingsOverrideComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_PlaysetRootSpawner> PlaysetRootSpawnerComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceComponent_PlayerPawnOverrides> PlayerPawnOverridesComponent;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class VKEDITGAMEPLAY_API UPlayspaceComponent_EditConnectionManager : public UFortPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_EditConnections() const;

	UFUNCTION()
	void OnRep_VkEditStatus() const;

	UPROPERTY(ReplicatedUsing=OnRep_EditConnections)
	int32 EditConnections;

	UPROPERTY(ReplicatedUsing=OnRep_VkEditStatus)
	EVkEditStatus VkEditStatus;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlayspaceComponent_EditConnectionManager")
	FGameplayTagContainer UITagsToHide;

};

