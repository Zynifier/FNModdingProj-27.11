// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "FortGrindRail.generated.h"

class AFortGameStateAthena;
class AFortGrindRail;
class AFortPlayerPawn;
class UFortPlaylist;
class USceneComponent;
class USplineComponent;
class USplineMeshComponent;
enum class EGrindRailBoosterMode : uint8;

UENUM(BlueprintType)
enum class EGrindRailBoosterMode : uint8
{
	SpeedUp = 0,
	SlowDown = 1,
	NoEffect = 2,
};

USTRUCT(BlueprintType)
struct FFortRailPointSnapData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortRailPointSnapData")
	TObjectPtr<AFortGrindRail> RailToSnapTo;

	UPROPERTY(BlueprintReadOnly, Category="FortRailPointSnapData")
	int32 PointToSnapTo;

};

USTRUCT(BlueprintType)
struct FGrindRailBoosterInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="GrindRailBoosterInfo")
	float MinDistanceAlongSpline;

	UPROPERTY(BlueprintReadWrite, Category="GrindRailBoosterInfo")
	float MaxDistanceAlongSpline;

	UPROPERTY(BlueprintReadWrite, Category="GrindRailBoosterInfo")
	EGrindRailBoosterMode PositiveMode;

	UPROPERTY(BlueprintReadWrite, Category="GrindRailBoosterInfo")
	EGrindRailBoosterMode NegativeMode;

};

USTRUCT(BlueprintType)
struct FGrindRailSpeedSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="GrindRailSpeedSettings")
	float SprintAcceleration;

	UPROPERTY(BlueprintReadWrite, Category="GrindRailSpeedSettings")
	float MaxLeanAcceleration;

	UPROPERTY(BlueprintReadWrite, Category="GrindRailSpeedSettings")
	float MinLeanAcceleration;

	UPROPERTY(BlueprintReadWrite, Category="GrindRailSpeedSettings")
	float ShootingSpeedMultiplier;

	UPROPERTY(BlueprintReadWrite, Category="GrindRailSpeedSettings")
	float GravityForceWhenGoingUp;

	UPROPERTY(BlueprintReadWrite, Category="GrindRailSpeedSettings")
	float GravityForceWhenGoingDown;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortGrindRail : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool AllowSprinting() const;

	UFUNCTION(BlueprintCallable)
	void BPRerunConstructionScript();

	UFUNCTION(BlueprintImplementableEvent)
	void GenerateMeshesAlongSpline();

	UFUNCTION(BlueprintNativeEvent)
	bool GetSpeedSettingsOverride(FGrindRailSpeedSettings& SpeedSettingsOverride) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool IsGrindRailEnabled() const;

	UFUNCTION(BlueprintImplementableEvent)
	bool IsTipCapped(const bool bStartTip);

	UFUNCTION(BlueprintCallable)
	void NativeGetNextPositionToGrind(const float DistanceToTravel, const float CurrentDistanceAlongSpline, const float RightLeanValue, FVector& OutNextLocation, bool& bGotToEnd, float& NextLocationOnRail, EGrindRailBoosterMode& BoosterMode, bool& bHitObstacle, bool& bNewRail, float& DistanceAlongNewRail, AFortGrindRail*& TheNewRail, bool& bNewRailReverseDirection);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerBeganGrinding(AFortPlayerPawn* GrindingPawn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerEndedGrinding(AFortPlayerPawn* Pawn);

	UFUNCTION(BlueprintCallable)
	void SetupMeshInfo(USplineMeshComponent* SplineMeshComponent);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FScalableFloat SpeedHardCap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FScalableFloat BaseMaxSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FScalableFloat MaxSpeedIncreaseFromDownwardSlope;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FScalableFloat MaxBaseAcceleration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FScalableFloat MinBaseAcceleration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FScalableFloat MaxStartSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FScalableFloat MinStartSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FScalableFloat SprintingAcceleration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FScalableFloat SprintingMaxSpeed;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ForceClearBoosters();

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	FFortRailPointSnapData GetBestPointToSnapTo(int32 PointToSnap, const TArray<AFortGrindRail*>& SnapAllowedRails);
#endif

	UFUNCTION(BlueprintPure)
	bool HasHeadConnection() const;

	UFUNCTION(BlueprintPure)
	bool HasTailConnection() const;

	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnRep_DisableBooster();

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	void SnapPoint(int32 PointIndex, const FFortRailPointSnapData& SnapData);
#endif

	UFUNCTION(BlueprintCallable)
	void UpdateTransientComponentTransforms(TArray<USceneComponent*> TransientSceneComponents);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortGrindRail", meta=(EditInline="true"))
	TArray<TObjectPtr<USplineMeshComponent>> GrindRailMeshes;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortGrindRail")
	TArray<FGrindRailBoosterInfo> BoosterInfos;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> SplineComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGrindRail")
	FScalableFloat EnableBoosters;

	UPROPERTY(EditDefaultsOnly, Category="FortGrindRail")
	FScalableFloat EnableGrinding;

	UPROPERTY(EditDefaultsOnly, Category="FortGrindRail")
	FScalableFloat EnableProjectileCollision;

	UPROPERTY(EditAnywhere, Category="Spline Gravity")
	bool bSimulateSplineGravity;

	UPROPERTY(EditAnywhere, Category="Spline Gravity", meta=(EditCondition="bSimulateSplineGravity"))
	float SimulatedSplineGravityAcceleration;

	UPROPERTY(EditAnywhere, Category="Spline Gravity", meta=(ClampMin="1", EditCondition="bSimulateSplineGravity", ForceUnits="cm/spline point count", UIMin="1"))
	float TargetDistanceBetweenSplinePointsForGravitySimulation;

	UPROPERTY(EditAnywhere, Category="Spline Gravity", meta=(EditCondition="bSimulateSplineGravity"))
	int32 SplineGravitySimulationIterationCount;

	UPROPERTY(EditAnywhere, Category="Spline Gravity", meta=(EditCondition="bSimulateSplineGravity", ForceUnits="sec"))
	float SplineGravitySimulationTime;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DisableBooster)
	bool bDisableBooster;

	UPROPERTY(VisibleAnywhere, Category="Optimization")
	TSoftObjectPtr<AFortGrindRail> HeadConnectedRail;

	UPROPERTY(VisibleAnywhere, Category="Optimization")
	TSoftObjectPtr<AFortGrindRail> TailConnectedRail;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Optimization")
	bool bUseCustomSplitIndex;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Optimization", meta=(EditCondition="bUseCustomSplitIndex", EditConditionHides, HideEditConditionToggle))
	int32 CustomSplitIndex;
#endif

private:
#if WITH_EDITOR
	UFUNCTION(Category="Optimization", meta=(CallInEditor="true"))
	void ConnectSelectedRails();
#endif

#if WITH_EDITOR
	UFUNCTION(Category="Optimization", meta=(CallInEditor="true"))
	void RemoveConnectionsFromSelectedRails();
#endif

#if WITH_EDITOR
	UFUNCTION(Category="Optimization", meta=(CallInEditor="true"))
	void SplitRail();
#endif

};

