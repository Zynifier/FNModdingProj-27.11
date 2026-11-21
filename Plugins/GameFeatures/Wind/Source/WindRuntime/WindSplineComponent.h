// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Pawns/FortPawnTypes.h"
#include "Physics/FortAsyncObjectManager.h"
#include "Physics/FortPhysicsObjectPreset.h"
#include "Physics/FortPhysicsSimSize.h"
#include "WindSplineComponent.generated.h"

class AActor;
class UAnimInstance;
class UBoxFalloff;
class UFXSystemComponent;
class UFieldSystemComponent;
class UGameplayEffect;
class UMaterialInstanceDynamic;
class UOperatorField;
class UStaticMesh;
class UUniformVector;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWindSplineSimpleEvent);

USTRUCT()
struct FPhysicsWindSplineAsyncInPersistent
{
	GENERATED_BODY()

};

USTRUCT()
struct FPhysicsWindSplineAsyncOutContinuous
{
	GENERATED_BODY()

};

USTRUCT()
struct FWindSplineBlockageID
{
	GENERATED_BODY()

private:
	UPROPERTY()
	uint32 ID;

};

USTRUCT()
struct FWindSplineSubDivBlockage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 SubDivIdx;

	UPROPERTY()
	float StartSectionLength;

};

USTRUCT()
struct FWindSplineBlockage : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FWindSplineBlockageID ID;

	UPROPERTY()
	TArray<FWindSplineSubDivBlockage> SubDivBlockages;

	UPROPERTY()
	float ActivationTime;

	UPROPERTY()
	float DeactivationTime;

};

USTRUCT()
struct FWindSplineBlockageArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FWindSplineBlockage> Items;

};

USTRUCT()
struct FWindSplineForceModifiers
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat ForwardForceMagnitudeMultiplier;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat ReverseForceMagnitudeMultiplier;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat InwardForceOuterRadiusAccelerationMultiplier;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat InwardForceInnerRadiusDecelerationMultiplier;

};

USTRUCT()
struct FWindSplineMeshData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<UMaterialInstanceDynamic*> MeshMaterials;

};

USTRUCT()
struct FWindSplineTagBasedForceModifiers
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Forces")
	FGameplayTagQuery Query;

	UPROPERTY(EditAnywhere, Category="Forces")
	FWindSplineForceModifiers Modifier;

};

USTRUCT()
struct FWindSplineTargetDatum : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> Target;

};

USTRUCT()
struct FWindSplineTargetData : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FWindSplineTargetDatum> Items;

};

USTRUCT()
struct FWindSplineTargetEffects
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Effects")
	FGameplayTagQuery Filter;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(Categories="GameplayCue"))
	FGameplayTag Cue;

	UPROPERTY(EditAnywhere, Category="Effects")
	TArray<TSubclassOf<UGameplayEffect>> GameplayEffects;

};

UCLASS(HideCategories=("Physics", "Collision", "Lighting", "Rendering", "Mobile", "Trigger", "VirtualTexture"), meta=(BlueprintSpawnableComponent))
class UWindSplineComponent : public USplineComponent, public IWindVolumeInterface, public IFortAsyncObjectInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void GetClosestActiveLocations(const FVector& InTargetLocation, bool& bIsClosestPointActive, FVector& ClosestPointOnSpline, TArray<FVector>& ClosestActiveLocations) const;

	UFUNCTION(BlueprintPure)
	float GetTargetingRadius() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void GetWindDataAtLocation(const FVector& InTargetLocation, FVector& OutDirection, float& OutAttenuation) const;

protected:
	UFUNCTION()
	void Disable();

	UFUNCTION()
	void Enable();

	UFUNCTION()
	void OnRep_Blockages();

	UFUNCTION()
	void OnRep_TargetData();

private:
	UPROPERTY(EditAnywhere, Category="Lifetime")
	FScalableFloat DisableSafeZonePhaseIndex;

	UPROPERTY(EditAnywhere, Category="Visualization")
	TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditAnywhere, Category="Visualization", meta=(EditCondition="!bClosedLoop"))
	TObjectPtr<UStaticMesh> StartStaticMesh;

	UPROPERTY(EditAnywhere, Category="Visualization", meta=(EditCondition="!bClosedLoop"))
	TObjectPtr<UStaticMesh> EndStaticMesh;

	UPROPERTY(EditAnywhere, Category="Visualization")
	TEnumAsByte<ESplineMeshAxis::Type> MeshForwardAxis;

	UPROPERTY(EditAnywhere, Category="Visualization")
	FScalableFloat MeshRollVariance;

	UPROPERTY(EditAnywhere, Category="Visualization")
	FName ActiveSectionStartMaterialParamName;

	UPROPERTY(EditAnywhere, Category="Visualization")
	FName ActiveSectionEndMaterialParamName;

	UPROPERTY(EditAnywhere, Category="Targeting")
	FScalableFloat TargetingRefreshRate;

	UPROPERTY(EditAnywhere, Category="Targeting")
	FScalableFloat TargetingRadius;

	UPROPERTY(EditAnywhere, Category="Targeting")
	TArray<TEnumAsByte<EObjectTypeQuery>> TargetObjectTypes;

	UPROPERTY(EditAnywhere, Category="Targeting")
	FGameplayTagQuery TargetTagQuery;

	UPROPERTY(EditAnywhere, Category="Targeting")
	FGameplayTagQuery BlockageTagQuery;

	UPROPERTY(EditAnywhere, Category="Targeting")
	FScalableFloat BlockageSubdivisions;

	UPROPERTY(EditAnywhere, Category="Targeting")
	TArray<FWindSplineTargetEffects> TargetEffects;

	UPROPERTY(EditAnywhere, Category="Targeting")
	TMap<EFortPhysicsObjectType, FScalableFloat> ObjectTypeToMaxTargetCount;

	UPROPERTY(EditAnywhere, Category="Targeting")
	FScalableFloat MaxTargetCountReachedExpelDuration;

	UPROPERTY(EditAnywhere, Category="Movement")
	FScalableFloat SkydivingLandingAngle;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat RampUpSpeed;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat RampDownSpeed;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat ForwardForceFallOffStartDistance;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat ForwardForceMagnitude;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat ReverseForceMagnitude;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat ForwardForceDistanceFallOffExponent;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat InwardForceInnerRadius;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat InwardForceOuterRadiusAcceleration;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat InwardForceInnerRadiusDeceleration;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat InwardForceInnerRadiusSpeedThreshold;

	UPROPERTY(EditAnywhere, Category="Forces")
	FScalableFloat InwardForceOuterRadiusSpeedThreshold;

	UPROPERTY(EditAnywhere, Category="Forces", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat InwardForceMaxReductionFromSteering;

	UPROPERTY(EditAnywhere, Category="Forces", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat InwardForceMaxMultiplierWhenSteering;

	UPROPERTY(EditAnywhere, Category="Forces", meta=(ClampMax="90.000000", ClampMin="0.000000", UIMax="90.000000", UIMin="0.000000"))
	FScalableFloat InwardForceMaxSteerAngle;

	UPROPERTY(EditAnywhere, Category="Forces", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat InwardForceLowVelocityThreshold;

	UPROPERTY(EditAnywhere, Category="Forces", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat InwardForceLowVelocityMinValue;

	UPROPERTY(EditAnywhere, Category="Forces", meta=(ClampMin="1.000000", UIMin="1.000000"))
	FScalableFloat InwardForceSteeringReduceAccelerationPower;

	UPROPERTY(EditAnywhere, Category="Forces", meta=(ClampMin="1.000000", UIMin="1.000000"))
	FScalableFloat InwardForceSteeringReduceDecelerationPower;

	UPROPERTY(EditAnywhere, Category="Forces")
	TMap<EFortPhysicsSimSize, FWindSplineForceModifiers> SizeForceModifiers;

	UPROPERTY(EditAnywhere, Category="Forces")
	TMap<EFortPhysicsObjectType, FWindSplineForceModifiers> ObjectTypeForceModifiers;

	UPROPERTY(EditAnywhere, Category="Forces")
	TArray<FWindSplineTagBasedForceModifiers> QueryBasedForceModifiers;

	UPROPERTY(EditAnywhere, Category="Forces|Pawns")
	FGameplayTagQuery PawnSkydivingTimeLimitQuery;

	UPROPERTY(EditAnywhere, Category="Forces|Pawns")
	FScalableFloat PawnSkydivingTimeLimit;

	UPROPERTY(EditAnywhere, Category="Forces|Pawns")
	FScalableFloat PawnSkydivingMinDistanceAboveGround;

	UPROPERTY(EditAnywhere, Category="Forces|PhysicsObjects")
	FScalableFloat AutoWakeUpPhysicsObjects;

	UPROPERTY(EditAnywhere, Category="Forces|Fields")
	FScalableFloat FieldMagnitudeBase;

	UPROPERTY(EditAnywhere, Category="Forces|Fields")
	FScalableFloat FieldMinMagnitudeAfterFalloff;

	UPROPERTY(EditAnywhere, Category="Forces|Fields")
	FScalableFloat FieldMaxMagnitudeAfterFalloff;

	UPROPERTY(EditAnywhere, Category="Animation")
	TSubclassOf<UAnimInstance> PlayerWindAnimationLayer;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="true"))
	FWindSplineSimpleEvent OnWindSplineDisabled;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="true"))
	FWindSplineSimpleEvent OnWindSplineEnabled;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TargetData)
	FWindSplineTargetData TargetData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Blockages)
	FWindSplineBlockageArray Blockages;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFieldSystemComponent> FieldSystemComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUniformVector> UniformVector;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBoxFalloff> BoxFalloff;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UOperatorField> BoxOperatorField;

	UPROPERTY(Transient)
	TArray<FWindSplineMeshData> MeshDataArray;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFXSystemComponent>> FXComponents;

};

