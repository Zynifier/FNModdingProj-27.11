// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AircraftFlightInfo.h"
#include "Athena/FortAmmoBoxSpawnInfo.h"
#include "Athena/FortPlaylistAthena.h"
#include "Athena/FortSafeZoneIndicator.h"
#include "Athena/FortSafeZoneVolumeDefinition.h"
#include "Athena/FortTreasureChestSpawnInfo.h"
#include "FortAthenaMapInfo.generated.h"

class AActor;
class ABuildingFoundation;
class ABuildingGameplayActor;
class ABuildingItemCollectorActor;
class ABuildingItemWeaponUpgradeActor;
class AFortAthenaAircraft;
class AFortAthenaSupplyDrop;
class AFortAthenaWarmupActor;
class AFortGameModeAthena;
class AFortSafeZoneStorm;
class AVolume;
class UArrowComponent;
class UBillboardComponent;
class UBoxComponent;
class UFortPlaylistAthena;
class UFortSupplyDropInfo;

UENUM()
enum class EBuildingGameplayActorAircraftSpawnSide : uint8
{
	None = 0,
	// indicates a side wasn't picked

	Side1 = 1,
	// indicates we spawned the last BGA on side 1

	Side2 = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBuildingContainersUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCustomHandleActorStreamedInEditor, AActor*, SourceActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPrepareMapSpawns);

USTRUCT(BlueprintType)
struct FAircraftFlightConstructionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightConstructionInfo")
	EAirCraftBehavior AirCraftBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(ClampMin="0", UIMin="0"))
	int32 AircraftCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightConstructionInfo")
	bool bUseCustomPathSelection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(EditCondition="bUseCustomPathSelection"))
	float CustomAircraftOffsetFromMidLine;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(EditCondition="bUseCustomPathSelection"))
	float CustomMinMidlineAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(EditCondition="bUseCustomPathSelection"))
	float CustomMaxMidlineAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo")
	bool bUseSameDirectionForOpposingAircraft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo")
	bool bDropOnlyWithinSafeZone;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(ClampMin="0", UIMin="0"))
	int32 DropAreaSafeZonePhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(ClampMin="0.0", UIMin="0.0"))
	float SafetyMarginPct;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(ClampMin="0.0", EditCondition="bUseCustomPathSelection", UIMin="0.0"))
	float PathOffsetFromMapCenterMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(ClampMin="0.0", EditCondition="bUseCustomPathSelection", UIMin="0.0"))
	float PathOffsetFromMapCenterMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(ClampMin="0.0", EditCondition="bUseCustomPathSelection", UIMin="0.0"))
	float PathMidpointSelectionRadiusMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(ClampMin="0.0", EditCondition="bUseCustomPathSelection", UIMin="0.0"))
	float PathMidpointSelectionRadiusMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(ClampMin="0.0", EditCondition="bUseCustomPathSelection", UIMin="0.0"))
	float LastStepPushCenterLine_Magnitude;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(ClampMin="0.0", EditCondition="bUseCustomPathSelection", UIMin="0.0"))
	float LastStepPushCenterLine_Direction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo")
	bool bSystematicFlightPath;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(EditCondition="bSystematicFlightPath"))
	float SystematicPathStartDegrees;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(EditCondition="bSystematicFlightPath"))
	float SystematicPathOffsetFactor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo")
	bool bForceDropCenterToFirstSafeZone;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo")
	bool bUseCustomDropZone;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AircraftFlightConstructionInfo", meta=(EditCondition="bUseCustomDropZone"))
	FBox2D CustomDropZoneBox2D;

};

USTRUCT(BlueprintType)
struct FBuildingGameplayActorSpawnDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	TSubclassOf<ABuildingGameplayActor> BuildingGameplayActorClass;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	TSubclassOf<AActor> TargetActorClass;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat SpawnHeight;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat GlobalMaxBGAs;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat MinNumToSpawnPerPhase;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat MaxNumToSpawnPerPhase;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat MinTimeToStartSpawnningBGAs;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat MaxTimeToStartSpawnningBGAs;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat MinTimeBetweenBGASpawns;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat MaxTimeBetweenBGASpawns;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat MinTimeToRepeatSpawningBGAs;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSpawnDetails")
	FScalableFloat MaxTimeToRepeatSpawningBGAs;

};

USTRUCT(BlueprintType)
struct FSafeZoneLocationParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams")
	int32 SafeZoneIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams")
	FVector AnchorLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams", meta=(ClampMin="0.0", UIMin="0.0"))
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams", meta=(ClampMin="0.0", UIMin="0.0"))
	float MaxRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams", meta=(ClampMin="0.0", UIMin="0.0"))
	float ForceDistanceMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams")
	float ForceDistanceMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams", meta=(ClampMin="0.0", EditCondition="ForceDistanceMin == 0.0", UIMin="0.0"))
	float RejectRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams", meta=(ClampMin="0.0", UIMin="0.0"))
	float RejectOuterDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams")
	FVector MapCenter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams", meta=(ClampMin="0.0", UIMin="0.0"))
	float MaxMapRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams")
	bool bIsEndingLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SafeZoneLocationParams", meta=(ClampMin="0.0", UIMin="0.0"))
	float MegaStormGridCellThickness;

};

USTRUCT(BlueprintType)
struct FSafeZoneRoundData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SafeZoneRoundData")
	TSoftObjectPtr<UFortPlaylistAthena> CurrentPlaylist;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoundData")
	int32 PhaseIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoundData")
	int32 LivingPlayers;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Actor", "Input", "Rendering", "Replication"))
class AFortAthenaMapInfo : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FAircraftFlightInfo CalcAircraftFlightPath(AFortGameModeAthena* GameModeAthena, const FAircraftFlightConstructionInfo& FlightConstructionInfo, const FVector2D& PathPoint1, const FVector2D& PathPoint2, const FVector2D& RotationAnchorPoint, const float DropZoneHeight, const FBox2D& SpawnZone, const FBox2D& DropZone, const float AircraftOffsetFromMidLine, const float AngleOffset) const;

	UFUNCTION(BlueprintPure)
	FVector GetMapCenter() const;

	UFUNCTION(BlueprintPure)
	FVector PickSupplyDropLocation(const FVector& CenterLocation, const float MaxRadius, const bool bAvoidWater = false, const float TraceStartZ = -1.000000f, const float TraceEndZ = -1.000000f, const bool bAvoidUnwalkableTerrain = false) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetAircraftSpeed(const FScalableFloat& InAircraftSpeed);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat GoldenPoiPercents;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat GoldenPoiPercentOfSelectedAtBusPathEnd;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat GoldenPoiDistanceAroundBusPathEnd;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat GoldenPoiDistanceMustBeAwayFromBusPath;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	TArray<FFortTreasureChestSpawnInfo> TreasureChestSpawnInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	TArray<FFortAmmoBoxSpawnInfo> AmmoBoxSpawnInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	TArray<FBuildingGameplayActorSpawnDetails> BuildingGameplayActorSpawnDetails;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	TSubclassOf<ABuildingItemCollectorActor> VendingMachineClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat VendingMachineRarityCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	TSubclassOf<ABuildingItemWeaponUpgradeActor> WeaponUpgradeMachineClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat WeaponUpgradeMachineSpawnChance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	TSubclassOf<AFortAthenaSupplyDrop> LlamaClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat LlamaQuantityMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat LlamaQuantityMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	TArray<TObjectPtr<UFortSupplyDropInfo>> SupplyDropInfoList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat SupplyDropMinPlacementHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat SupplyDropMaxPlacementHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat SupplyDropAvoidWaterTraceMinZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat bShouldLlamaAvoidUnwalkableTerrain;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot")
	FScalableFloat bShouldSupplyDropAvoidUnwalkableTerrain;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	TSubclassOf<AFortAthenaAircraft> AircraftClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	FBox2D AircraftSpawnZone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	FBox2D AircraftDropZone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	TObjectPtr<AVolume> AircraftDropVolume;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	FScalableFloat AircraftDropVolumeProjectionFailsafeExtent_X;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	FScalableFloat AircraftDropVolumeProjectionFailsafeExtent_Y;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat SkydivingScanForImpactWorldZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat SkydivingForceDeployParachuteWorldZ;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaMapInfo")
	TArray<FAircraftFlightInfo> FlightInfos;

	UPROPERTY()
	FBoxSphereBounds CachedPlayableBoundsForClients;

protected:
	UFUNCTION(BlueprintPure, Category="SafeZones")
	FSafeZoneLocationParams ConstructSafeZoneLocationParams(const int32 SafeZoneIndex, const FVector& CenterLocation, const FVector& NextLocation, const bool bFinalPhase, const int32 BaseSafeZoneIndex = 0) const;

	UFUNCTION(Category="SafeZonesDebugging", meta=(CallInEditor="true"))
	void DrawSafeZoneVolumeDefinitions();

	UFUNCTION(BlueprintPure, Category="SafeZones")
	FVector PickSafeZoneLocation(const FSafeZoneLocationParams& Params, const TArray<FVector4>& BlacklistLocations) const;

	UFUNCTION(BlueprintImplementableEvent, Category="DynamicStormCircles")
	void TryDynamicStormCircleModification(const FSafeZoneRoundData& RoundData, const float NewSafeZoneWaitTime, const float NewSafeZoneShrinkTime, const float NewSafeZoneRadius, float& OutWaitTime, float& OutShrinkTime, float& OutRadius) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft", meta=(ClampMax="90.0", ClampMin="0.0", UIMax="90.0", UIMin="0.0"))
	FScalableFloat AircraftDeviationAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	FScalableFloat AircraftDistanceFromMidLine;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	FScalableFloat AircraftHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft", meta=(ClampMin="1.0", UIMin="1.0"))
	FScalableFloat AircraftSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	FScalableFloat AircraftDesiredDoorOpenTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZones")
	TObjectPtr<AVolume> PlayableBoundsVolume;

	UPROPERTY(EditAnywhere, Category="SafeZones")
	FScalableFloat SafeZoneStartDelay;

	UPROPERTY(EditAnywhere, Category="SafeZones")
	FScalableFloat SafeZoneStartingRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZones")
	TArray<FFortSafeZoneVolumeDefinition> SafeZoneVolumeDefinitions;

	UPROPERTY(EditInstanceOnly, Transient, Category="SafeZonesDebugging")
	int32 SafeZoneVolumeDefinitionIndexToDraw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZones")
	FFortSafeZoneDefinition SafeZoneDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZones")
	TObjectPtr<AFortSafeZoneStorm> SafeZoneStorm;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Warmup")
	TSoftObjectPtr<ABuildingFoundation> WarmupBuildingFoundation;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Warmup")
	TSoftObjectPtr<AFortAthenaWarmupActor> WarmupActor;

private:
	UFUNCTION()
	void HandleStormEffectsPlayerOptionEnabledChanged(bool bInEnabled);

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UArrowComponent> ArrowComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> AircraftSpawnZoneComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> AircraftDropZoneComponent;
#endif

};

