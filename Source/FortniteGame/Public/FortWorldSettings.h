// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Fonts/SlateFontInfo.h"
#include "GameFramework/WorldSettings.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "UObject/SoftObjectPath.h"
#include "WorldPartition/HLOD/HLODProviderInterface.h"
#include "Building/BuildingFoundationStreamingData.h"
#include "FortTimeOfDayEditorViewSettings.h"
#include "Items/FortPlaysetSettings.h"
#include "FortWorldSettings.generated.h"

class AActor;
class AFortAsyncObjectManager;
class AFortLightweightProjectileManager;
class AFortMusicManager;
class AFortPhysicsObjectManager;
class AFortVehicleManager;
class AInfo;
class IFortTimeOfDayManagerInterface;
class UCurveTable;
class UDEPRECATED_FortBudgetGrid;
class UDataTable;
class UFortFoliageSpawnerSet;
class UFortLevelOverlayManager;
class UFortMusicManagerBank;
class UFortProceduralFoliageComponent;
class UHLODLayer;
class UMaterialInterface;
class UObject;
class USoundBase;
class UTexture2D;
class UValkyrieEditorActorTemplateIdManager;
class UWorld;

USTRUCT()
struct FFortWorldSettingsOverride : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortWorldSettingsOverride")
	TSoftObjectPtr<UWorld> World;

	UPROPERTY(EditDefaultsOnly, Category="FortWorldSettingsOverride", meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TSoftClassPtr<AInfo> TimeOfDayManagerClass;

};

USTRUCT()
struct FMapLocation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Location")
	FText Text;

	UPROPERTY(EditAnywhere, Category="Location", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	FVector2D Position;

	UPROPERTY(EditAnywhere, Category="Location")
	FSlateFontInfo Font;

	UPROPERTY(EditAnywhere, Category="Location")
	FLinearColor Color;

	UPROPERTY(EditAnywhere, Category="Location")
	FGameplayTag LocationTag;

};

USTRUCT()
struct FMapLocationRenderData
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EMapLocationStateType"))
	FSlateFontInfo Font[3];

};

USTRUCT()
struct FPlaysetPropSettings
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TMap<TSoftObjectPtr<AActor>, uint32> ActorsPlaysetPropHash;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="PlaysetPropItemDefinitions", meta=(DisplayName="Actors Playset Prop Hash"))
	TMap<TWeakObjectPtr<AActor>, uint32> ActorsPlaysetPropHashV2;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="PlaysetPropItemDefinitions", meta=(AllowedClasses="/Script/FortniteGame.FortPlaysetPropItemDefinition"))
	TMap<uint32, FSoftObjectPath> PlaysetProps;
#endif

};

UCLASS(MinimalAPI, HideCategories=("Actor", "Advanced", "Display", "Events", "Object", "Attachment", "Info", "Input", "Blueprint", "Layers", "Tags", "Replication", "LevelInstance", "Input", "Movement", "Collision", "Transformation", "HLOD", "DataLayers"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortWorldSettings : public AWorldSettings, public IWorldPartitionHLODProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	void DisableAllTimeOfDayManagers(bool bState);

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="EditorOnly")
	TScriptInterface<IFortTimeOfDayManagerInterface> GetTimeOfDayManager();
#endif

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> ActorsNeedingWorldReady;

	UPROPERTY()
	TArray<int32> WorldCells;

	UPROPERTY()
	FVector WorldCellsOrigin;

	UPROPERTY()
	int32 WorldCellsFlags;

	UPROPERTY(EditAnywhere, Transient, Category="Mission Saving")
	uint8 bGenerateTestLevelSaves : 1;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Editor")
	uint8 bDisableEditorCellSnap : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AI")
	uint8 bFixUpAllActorsAndFoundations : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AI")
	uint8 bGenerateNavGraph : 1;
#endif

	UPROPERTY(EditAnywhere, Category="Editor")
	uint8 bDisableCullDistance : 1;

	UPROPERTY(EditAnywhere, Category="Editor")
	uint8 bUseWorldSpecificCullDistanceOverride : 1;

	UPROPERTY(EditAnywhere, Category="Map")
	uint8 bOverrideMainMapSettings : 1;

	UPROPERTY(EditAnywhere, Transient, Category="AI")
	uint8 bValidateNavGraphConnectivity : 1;

	UPROPERTY(EditAnywhere, Category="AI")
	uint8 bLimitNavGraphSkyCells : 1;

	UPROPERTY(EditAnywhere, Category="ProceduralFoliage")
	uint8 bUseProceduralFoliage : 1;

	UPROPERTY(EditAnywhere, Category="Map")
	uint8 bUseConditionalBuildingFoundations : 1;

	UPROPERTY(EditAnywhere, Category="HLOD")
	uint8 bAllowBuildingStreamingData : 1;

	UPROPERTY(EditAnywhere, Category="HLOD")
	int32 SplineHLODIndex;

	UPROPERTY(EditAnywhere, Category="SimpleDestructiblePropGroups", meta=(ClampMax="100000", ClampMin="1000", UIMax="100000", UIMin="1000"))
	int32 SimpleDestructiblePropGroupCellSize;

	UPROPERTY(EditAnywhere, Category="SimpleDestructiblePropGroups")
	TArray<TSubclassOf<AActor>> AdditionalSimpleDestructiblePropClasses;

	UPROPERTY(EditAnywhere, Transient, Category="TimeOfDay")
	uint8 bEditableTimeOfDayManager : 1;

	UPROPERTY(EditAnywhere, Category="Editor")
	float MinCullObjectSize;

	UPROPERTY(EditAnywhere, Category="Editor")
	float MinCullDistance;

	UPROPERTY(EditAnywhere, Category="Editor")
	float MaxCullObjectSize;

	UPROPERTY(EditAnywhere, Category="Editor")
	float MaxCullDistance;

	UPROPERTY(EditAnywhere, Category="Map")
	TObjectPtr<UMaterialInterface> OverrideMinimapMaterial;

	UPROPERTY(EditAnywhere, Category="Map")
	FVector2D PvPMapWorldCenter;

	UPROPERTY(EditAnywhere, Category="Map")
	float MapZOffset;

	UPROPERTY(EditAnywhere, Category="Map")
	FRotator MapRotation;

	UPROPERTY(EditAnywhere, Category="Map")
	TObjectPtr<UTexture2D> MapInitialMask;

	UPROPERTY(EditAnywhere, Category="Map")
	uint8 bSpawnAsyncObjectManager : 1;

	UPROPERTY(EditAnywhere, Category="Map")
	float MapWorldScale;

	UPROPERTY(EditAnywhere, Category="Map")
	float MiniMapZoom;

	UPROPERTY(EditAnywhere, Category="Map")
	FSlateBrush AircraftPathBrush;

	UPROPERTY(EditAnywhere, Category="Map")
	FSlateBrush AircraftMidlinePathBrush;

	UPROPERTY(EditAnywhere, Category="Map")
	FSlateBrush AircraftPathTeamIndicatorBrush;

	UPROPERTY(EditAnywhere, Category="Map")
	FSlateBrush SafeZoneFinalPosBrush;

	UPROPERTY(EditAnywhere, Category="Simulation|Vehicle")
	uint8 bSpawnVehicleManager : 1;

	UPROPERTY(EditAnywhere, Category="Simulation|Physics")
	uint8 bSpawnPhysicsObjectManager : 1;

	UPROPERTY(EditAnywhere, Category="Simulation|Physics")
	uint8 bDeferPhysicsObjectSetup : 1;

	UPROPERTY(EditAnywhere, Category="AI", meta=(EditCondition="bLimitNavGraphSkyCells"))
	TArray<FIntPoint> NavGraphSkyCells;

	UPROPERTY(EditAnywhere, Category="Balance")
	TObjectPtr<UCurveTable> SearchSpeedOverride;

	UPROPERTY(EditAnywhere, Category="Balance")
	TObjectPtr<UCurveTable> ResourceRateOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> SoundBodyHeadshotRequired;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Creative Playset")
	bool bIsPlayset;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Creative Playset", meta=(EditCondition="bIsPlayset"))
	FPlaysetSettings PlaysetSettings;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, AdvancedDisplay, Category="Creative Playset")
	TMap<TSubclassOf<UObject>, FPlaysetPropSettings> PlaysetPropSettingsByClass;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Creative Playset")
	bool bResetPlaysetPropSettings;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Plugin")
	TArray<FName> PluginLandscapeLayers;
#endif

	virtual bool BuildHLODActor(const FBuildHLODActorParams& BuildHLODActorParams) override;

protected:
	UPROPERTY(EditAnywhere, Category="TimeOfDay")
	uint8 bShowTimeOfDayManager : 1;

	UPROPERTY(EditAnywhere, Category="TimeOfDay")
	uint8 bSpawnTimeOfDayManager : 1;

	UPROPERTY(EditAnywhere, Replicated, Category="TimeOfDay")
	uint8 bDisableAllTimeOfDayManagers : 1;

	UPROPERTY(EditAnywhere, Category="TimeOfDay")
	uint8 bDisableGlobalWeatherEvents : 1;

	UPROPERTY(EditAnywhere, Category="TimeOfDay", meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TSoftClassPtr<AInfo> WorldTimeOfDayManager;

	UPROPERTY(EditAnywhere, Category="TimeOfDay", meta=(ClampMax="360.000000", ClampMin="0.000000", UIMax="360.000000", UIMin="0.000000"))
	float WorldTimeOfDayManagerRotationZ;

	UPROPERTY(EditAnywhere, Category="Music")
	TSoftClassPtr<AFortMusicManager> WorldMusicManager;

	UPROPERTY(EditAnywhere, Category="Music")
	TObjectPtr<UFortMusicManagerBank> WorldMusicManagerBank;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDay")
	FTimeOfDayEditorViewSettings TimeOfDayEditorSettings;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="TimeOfDay")
	FTimeOfDayEditorWeatherSettings TimeOfDayEditorWeatherSettings;
#endif

	UPROPERTY(Config, meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TSoftClassPtr<AInfo> DefaultWorldTimeOfDayManager;

	UPROPERTY()
	TSoftClassPtr<AInfo> ZoneThemeTimeOfDayManager;

	UPROPERTY()
	TSoftClassPtr<AInfo> MissionTimeOfDayManager;

	UPROPERTY()
	TSoftClassPtr<AFortMusicManager> ZoneThemeMusicManager;

	UPROPERTY()
	TObjectPtr<UFortMusicManagerBank> ZoneThemeMusicManagerBank;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="ProceduralFoliage")
	TObjectPtr<UFortFoliageSpawnerSet> OverrideFoliageSpawnerSet;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortProceduralFoliageComponent> ProceduralComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(meta=(DeprecatedProperty, DeprecationMessage="Use ValkyrieEditorActorTemplateIdManager instead."))
	TObjectPtr<UDEPRECATED_FortBudgetGrid> BudgetGrid_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<UValkyrieEditorActorTemplateIdManager> ValkyrieEditorActorTemplateIdManager;
#endif

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Streaming")
	TArray<FBuildingFoundationStreamingData> BuildingFoundationStreamingData;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bGeneratePlaysetDeprecated;
#endif

	UPROPERTY(Transient, DuplicateTransient, NonTransactional)
	TScriptInterface<IFortTimeOfDayManagerInterface> TimeOfDayManager;

	UPROPERTY(Transient)
	TObjectPtr<AFortVehicleManager> VehicleManager;

	UPROPERTY(Transient)
	TObjectPtr<AFortPhysicsObjectManager> PhysicsObjectManager;

	UPROPERTY(Transient)
	TObjectPtr<AFortLightweightProjectileManager> LightweightProjectileManager;

	UPROPERTY(Transient)
	TObjectPtr<AFortAsyncObjectManager> AsyncObjectManager;

	UPROPERTY(Transient, DuplicateTransient, TextExportTransient)
	TObjectPtr<UFortLevelOverlayManager> LevelOverlayManager;

	UPROPERTY(Transient)
	TObjectPtr<UDataTable> OverrideDataTable;

	UPROPERTY(Transient)
	TMap<FName, FFortWorldSettingsOverride> WorldSettingsOverrides;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="UEFN")
	bool bShouldFixUpCreativeDevicesDescriptors;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Level HLOD")
	bool bEnableLevelHLOD;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Level HLOD", meta=(DisplayName="Level HLOD Layer", EditCondition="bEnableLevelHLOD", EditConditionHides))
	UHLODLayer* LevelHLODLayer;
#endif

};

