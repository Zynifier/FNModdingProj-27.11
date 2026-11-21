// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "Building/BuildingProp.h"
#include "FortTrack.generated.h"

class AFortTrack;
class UBoxComponent;
class UPrimitiveComponent;
class USceneComponent;
class USplineComponent;
class UStaticMesh;
class UStaticMeshComponent;

UENUM()
enum class ETrackDirection : uint8
{
	YNegative = 0,
	XPositive = 1,
	YPositive = 2,
	XNegative = 3,
	Max_None = 4 UMETA(Hidden),
};

UENUM()
enum class ETrackIncline : uint8
{
	NoNeighbor = 0,
	Flat = 1,
	Up = 2,
	Down = 3,
	GradualUp = 4,
	GradualDown = 5,
	Max_None = 6 UMETA(Hidden),
};

UENUM()
enum class ETrackPieceType : uint8
{
	None = 0,
	Straight = 1,
	Turn = 2,
	TShape = 3,
	Cross = 4,
	Max_None = 5 UMETA(Hidden),
};

UENUM()
enum class ETrackVerticality : uint8
{
	Floor = 0,
	Ramp = 1,
	GradualRamp = 2,
	// for the 'gradual' slope that takes two tiles to go up/down one tile.

	Max_None = 3 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortTrackGraphChanged);

USTRUCT(BlueprintType)
struct FFortTrackActorClassData : public FBuildingPropActorClassData
{
	GENERATED_BODY()

};

USTRUCT()
struct FTrackPieceConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Track")
	ETrackPieceType Type;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	FRotator Rotation;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	FVector Scale;

};

USTRUCT()
struct FTrackSplineConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Track")
	bool bUseSpline;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	ETrackDirection Start;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	ETrackDirection End;

};

USTRUCT()
struct FTrackSwitchStateConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Track")
	FTrackPieceConfig TrackPiece;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	FTrackSplineConfig SplineConfig1;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	FTrackSplineConfig SplineConfig2;

};

USTRUCT()
struct FTrackConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Track")
	TArray<bool> NeighborsByDirection;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	TArray<FTrackSwitchStateConfig> SwitchStates;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	FRotator SwitchRotation;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	FVector SwitchOffset;

};

USTRUCT()
struct FTrackConnectorMeshConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Track")
	ETrackIncline InclineSideA;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	ETrackIncline InclineSideB;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	TObjectPtr<UStaticMesh> Mesh;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=FortTrackActorClassData)
class AFortTrack : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Track")
	virtual void GetOutgoingNeighborFromSpline(USplineComponent* InSpline, bool InReverseDirection, AFortTrack*& OutNeighbor);

	UFUNCTION(BlueprintCallable, Category="Track")
	float GetPathDistanceToTrack(AFortTrack* TargetTrack, USplineComponent* InCurrentSpline, float CurrentDistanceAlongSpline, bool InReverseDirection);

	UFUNCTION(BlueprintCallable, Category="Track")
	virtual void GetSplineFromIncomingNeighbor(AFortTrack* InNeighbor, USplineComponent*& OutSpline, bool& OutReverseDirection);

	UFUNCTION(BlueprintCallable, Category="Track")
	virtual void GetSplineFromPositionAndOrientation(const FVector& InLocation, const FRotator& InRotation, USplineComponent*& OutSpline, float& OutDistanceAlongSpline, bool& OutReverseDirection);

	UFUNCTION(BlueprintCallable, Category="Track")
	void InitializeTrack(UPrimitiveComponent* InSwitchComp);

	UFUNCTION(BlueprintCallable, Category="Track")
	bool IsConnectedToTrack(AFortTrack* TargetTrack);

	UFUNCTION(BlueprintCallable, Category="Track")
	bool IsConnectedToTrackList(const TArray<AFortTrack*>& TargetTracks);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnConfigurationChanged(int32 NewConfigurationIdx, int32 OldConfigurationIdx);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnSwitchStateChanged(int32 NewSwitchState, int32 OldSwitchState, int32 NumSwitchStates);

	UPROPERTY(BlueprintAssignable, Category="Track")
	FFortTrackGraphChanged OnTrackGraphChanged;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	FText ToggleSwitchText;

	UPROPERTY(EditDefaultsOnly, Category="Track")
	float ToggleInteractTime;

	UPROPERTY(EditDefaultsOnly, Category="Track", meta=(ArraySizeEnum="/Script/FortniteGame.ETrackPieceType"))
	TObjectPtr<UStaticMesh> TrackPieceMeshesByType[5];

	UPROPERTY(EditDefaultsOnly, Category="Track")
	bool bUseFloorMesh;

	UPROPERTY(EditDefaultsOnly, Category="Track", meta=(ArraySizeEnum="/Script/FortniteGame.ETrackVerticality"))
	TObjectPtr<UStaticMesh> TrackFloorMeshesByVerticality[3];

	UPROPERTY(EditDefaultsOnly, Category="Track")
	TArray<FTrackConnectorMeshConfig> ConnectorMeshConfigs;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_NeighborsByDirection, meta=(ArraySizeEnum="/Script/FortniteGame.ETrackDirection"))
	TObjectPtr<AFortTrack> NeighborsByDirection[4];

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SwitchState)
	int32 SwitchState;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ConfigurationIdx)
	int32 ConfigurationIdx;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Track")
	int32 EditorTrackConfigurationIdx;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Track")
	int32 EditorSwitchState;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Track|Collision")
	FCollisionResponseContainer FloorCollisionResponseContainer;

protected:
	UFUNCTION()
	virtual void OnRep_ConfigurationIdx();

	UFUNCTION()
	virtual void OnRep_NeighborsByDirection();

	UFUNCTION()
	virtual void OnRep_SwitchState();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> TrackMeshComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> TrackFloorMeshComp;

	UPROPERTY(Transient, Export, meta=(ArraySizeEnum="/Script/FortniteGame.ETrackDirection", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> ConnectorMeshCompsByDirection[4];

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> PlacementCollision1;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> PlacementCollision2;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> SplineComp1;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> SplineComp2;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> SwitchCompBase;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> SwitchComp;

};

