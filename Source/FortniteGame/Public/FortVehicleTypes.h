// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortUIExtensionSlot.h"
#include "Vehicles/VehicleSeats.h"
#include "FortVehicleTypes.generated.h"

class UGameplayEffect;
class UInputComponent;
class UMaterialInstanceDynamic;
class USoundBase;
class USoundWave;
class UStaticMesh;
class UStaticMeshComponent;
class UUserWidget;

UENUM(BlueprintType)
enum class ESlotEnvironmentExposure : uint8
{
	/** Slot's environmental exposure is unknown. */
	Unknown = 0,
	/** Slot is exposed. */
	Exposed = 1,
	/** Slot is protected. */
	Protected = 2,
};

UENUM(BlueprintType)
enum class ETireStates : uint8
{
	Default = 0,
	Popped = 1,
};

UENUM(BlueprintType)
enum class ETireSurfaces : uint8
{
	Road = 0,
	Dirt = 1,
	Grass = 2,
	Air = 3,
	Water = 4,
};

UENUM(BlueprintType)
enum class ETryExitVehicleBehavior : uint8
{
	/** If normal checking fails, do not force.  */
	DoNotForce = 0,
	/** If there is a blocking trace/sweep, force and fallback to exit behavior. */
	ForceOnBlocking = 1,
	/** Allow ordinary checks to run, but regardless of which fail we should end up exiting the vehicle. */
	ForceAlways = 2,
};

USTRUCT()
struct FActiveVehicleUI
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> ActiveWidget;

};

USTRUCT()
struct FAthenaCarPlayerSlotUnreplicated
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> Input;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FAthenaVehicleShootingCone
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle", meta=(ClampMax="180", ClampMin="0", UIMax="180", UIMin="0"))
	float YawConstraint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle", meta=(ClampMax="90", ClampMin="0", UIMax="90", UIMin="0"))
	float PitchConstraint;

};

USTRUCT(BlueprintType)
struct FAttachedWheel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="AttachedWheel", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UMaterialInstanceDynamic> MatInstance;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="AttachedWheel")
	float CurrentHealth;

};

USTRUCT()
struct FReplicatedAthenaVehicleAttributes
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float FrontLateralFrictionScale;

	UPROPERTY()
	float RearLateralFrictionScale;

	UPROPERTY()
	float BrakeForceTractionScale;

	UPROPERTY()
	float ForwardForceTractionScale;

	UPROPERTY()
	float SlopeAntigravityScale;

	UPROPERTY()
	float TopSpeedScale;

	UPROPERTY()
	float VehicleGravityScale;

	UPROPERTY()
	bool bBrakeBeforeReverse;

};

USTRUCT(BlueprintType)
struct FRuntimeSpringsInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeSpringsInfo")
	float SpringStiffMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeSpringsInfo")
	float SpringDampMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeSpringsInfo")
	float SpringLengthMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeSpringsInfo")
	float RearSpringLengthMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeSpringsInfo")
	float TireZOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeSpringsInfo")
	float TireZOffset_B;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeSpringsInfo")
	float WheelRadiusF;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeSpringsInfo")
	float WheelRadiusB;

};

USTRUCT(BlueprintType)
struct FRuntimeTerrainHandlingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeTerrainHandlingInfo")
	float PushForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeTerrainHandlingInfo")
	float BrakeForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeTerrainHandlingInfo")
	float TopSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeTerrainHandlingInfo")
	float FrontTireFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RuntimeTerrainHandlingInfo")
	float RearTireFriction;

};

USTRUCT(BlueprintType)
struct FTireInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	TObjectPtr<UStaticMesh> TireStaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TireInfo")
	TObjectPtr<UStaticMesh> UndercarriageCollisionStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FRuntimeSpringsInfo SpringTuning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FRuntimeTerrainHandlingInfo RoadBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FRuntimeTerrainHandlingInfo DirtBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FRuntimeTerrainHandlingInfo GrassBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FRuntimeTerrainHandlingInfo SnowBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FRuntimeTerrainHandlingInfo IceBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FRuntimeTerrainHandlingInfo MudBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float PoppedTireSpringLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float PoppedTireSpringStiff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float PoppedTireSpringDamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float TireMeshYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float TireMeshLateralAdjustment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float TireMeshScaleFront;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float TireMeshScaleRear;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FScalableFloat MaxDriveInclineAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float UprightRollStiff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float UprightRollDamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float UprightPitchStiff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float UprightPitchDamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float UprightYawStiff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float UprightYawDamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	float MidAxleForwardAdjust;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FScalableFloat TireHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FScalableFloat WaterTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FScalableFloat PontoonScaleRadiusPerTick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	TArray<FName> CollisionShapeNames;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TireInfo")
	TArray<FName> DamageablePartShapeNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FName PoppedTireBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	FName CollisionBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	TObjectPtr<USoundWave> TireDirtLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	TObjectPtr<USoundWave> TireGrassLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	TObjectPtr<USoundWave> TireRoadLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	TObjectPtr<USoundBase> SuspensionLight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	TObjectPtr<USoundBase> SuspensionMedium;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TireInfo")
	TObjectPtr<USoundBase> SuspensionHeavy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dagwood|Settings")
	TSubclassOf<UGameplayEffect> AppliedGameplayEffect;

};

USTRUCT()
struct FVehicleSpecificUIDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VehicleSpecificUIDetails")
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(EditAnywhere, Category="VehicleSpecificUIDetails")
	EUIExtensionSlot Slot;

	UPROPERTY(EditAnywhere, Category="VehicleSpecificUIDetails")
	TArray<EVehicleSeats> ValidSeats;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FVehicleSpringInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName SpringStart;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector SpringStartLocalOffset;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName ForceApplicationPoint;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float SpringLength;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(editcondition="!bIsLookAhead"))
	float SpringStiff;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float SpringDamp;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float SpringRadius;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float MaxAccelChange;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	int8 SeatSocketIndex;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	uint8 bIsLookAhead : 1;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	uint8 bNormalToGroundTriangle : 1;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	uint8 bForceAlongSpringGroundNormal : 1;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(editcondition="bIsLookAhead"))
	float LookAheadMinSpeed;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(editcondition="bIsLookAhead"))
	float LookAheadMaxSpeed;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(editcondition="bIsLookAhead"))
	float LookAheadMinStiff;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(editcondition="bIsLookAhead"))
	float LookAheadMaxStiff;

	UPROPERTY()
	FTransform LocalStartTM;

	UPROPERTY()
	FTransform LocalApplyTM;

	UPROPERTY()
	FHitResult Hit;

	UPROPERTY()
	FPlane GroundPlane;

	UPROPERTY()
	float SprungMass;

	UPROPERTY()
	bool bEnabled;

	UPROPERTY()
	FVector Start;

	UPROPERTY()
	FVector End;

	UPROPERTY()
	FVector RayDir;

	UPROPERTY()
	FVector ForcePt;

	UPROPERTY()
	FVector ForceDir;

};

