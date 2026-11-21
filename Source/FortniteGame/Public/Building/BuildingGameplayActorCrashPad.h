// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorCrashPad.generated.h"

class AActor;
class AFortPawn;
class UCurveFloat;
class UGameplayEffect;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FCrashpadDynamicParams
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	TObjectPtr<AActor> CollidingActor;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	TMap<TObjectPtr<AFortPawn>, float> TrackedPlayers;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	bool bHitAnotherCrashpad;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	int32 CrashpadsBouncedOffOf;

};

USTRUCT(BlueprintType)
struct FCrashpadStaticParams
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	FGameplayTag HoverTag;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float PawnLaunchMultiplierXY;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float PawnLaunchHorzClamp;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float PawnLaunchVertOffset;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float VerticalVelocityMultiplier;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MinLaunch;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MaxLaunch;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MinLaunchCrashpadPlus;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MaxLaunchCrashpadPlus;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float GrowthStart;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float GrowthEnd;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	TObjectPtr<UCurveFloat> LaunchCurve;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	TObjectPtr<UCurveFloat> LaunchAngleWeight;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float PlacedLaunchMod;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float VehicleLaunchMultiplierXY;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float VehicleLaunchMultiplierZ;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float VehicleImpactRadius;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float PawnOrVehicleBounceIntensity;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float CrashpadLaunchVertOffset;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float CrashpadBounceIntensity;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	TArray<float> CrashpadBounceScales;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MovingWithHeldObjectThreshold;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float ProjectileLaunchMultiplierXY;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float ProjectileLaunchMultiplierZ;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float ProjectileBounceIntensity;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	TSubclassOf<UGameplayEffect> FallImmunityGameplayEffect;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	TSubclassOf<UGameplayEffect> WebLaunchGameplayEffect;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	FGameplayTag SharkTag;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	bool bDestroyByShark;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	FGameplayTag KnockbackImmunityTag;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	FGameplayTag TagBuildingPhysics;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float PhysicsObjectMassMultiplier;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float PhysicsObjectImpulseMultiplier;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MinPhysicsObjectMass;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MaxPhysicsObjectMass;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MaxPhysicsObjectLaunch;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MinPhysicsObjectStartVelZ;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MaxPhysicsObjectStartVelZ;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float PhysicsObjectBounceIntensity;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float NonPawnLaunchScaleXY;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float NonPawnLaunchScaleZ;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float NonPawnLaunchOffsetZ;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MinNonPawnVelocity;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float MaxNonPawnVelocity;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	FGameplayTag TagEventUsedLaunchPad;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	float BuildingActorBounceIntensity;

	UPROPERTY(BlueprintReadWrite, Export, Category="Crashpad", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> CrashpadMesh;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	FGameplayTagContainer TagCrashpadPlus;

	UPROPERTY(BlueprintReadWrite, Category="Crashpad")
	FGameplayTagContainer QuestCrashpadUseTag;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorCrashpad : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Crashpad")
	void DestroyCrashpad();

	UFUNCTION(BlueprintImplementableEvent, Category="Crashpad")
	void DoBounceMulticast(const FVector BounceLocation, const float BounceIntensity, const AActor* BouncingActor);

	UFUNCTION(BlueprintCallable, Category="Crashpad")
	void HandleCollision(UPARAM(ref) FCrashpadDynamicParams& DynamicParams);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Crashpad")
	FScalableFloat UseNativeCollisionHandling;

protected:
	UPROPERTY(BlueprintReadWrite, Category="BuildingGameplayActorCrashpad")
	FCrashpadStaticParams StaticParams;

};

