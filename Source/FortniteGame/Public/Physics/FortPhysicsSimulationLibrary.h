// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayEffectTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Physics/FortPhysicsSimSize.h"
#include "FortPhysicsSimulationLibrary.generated.h"

class AActor;
class ABuildingActor;
class UObject;
class UPhysicsConstraintComponent;
class UPrimitiveComponent;
enum class EFortPhysicsObjectType : uint8;
enum class EFortPhysicsSimSize : uint8;

USTRUCT(BlueprintType)
struct FPhysicsSimValidateObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PhysicsSimValidateObject")
	EFortPhysicsSimSize MaxSimSizeAllowed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PhysicsSimValidateObject")
	bool bRejectEmbeddedInLandscape;

};

UCLASS(MinimalAPI, meta=(ScriptName="FortPhysicsSimulationLibrary"))
class UFortPhysicsSimulationLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_BoneName="None", CPP_Default_bVelChange="false", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void AddPhysicsAngularImpulse(AActor* PhysicsObject, FVector AngularImpulse, FName BoneName, bool bVelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_BoneName="None", CPP_Default_bAccelChange="false", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void AddPhysicsForce(AActor* PhysicsObject, FVector Force, FName BoneName, bool bAccelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_BoneName="None", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void AddPhysicsForceAtLocation(AActor* PhysicsObject, FVector Force, FVector Location, FName BoneName, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_BoneName="None", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void AddPhysicsForceAtLocationWithPrediction(AActor* PhysicsObject, FVector Force, FVector Location, FName BoneName, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_BoneName="None", CPP_Default_bAccelChange="false", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void AddPhysicsForceWithPrediction(AActor* PhysicsObject, FVector Force, FName BoneName, bool bAccelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_bTempered="true", CPP_Default_BoneName="None", CPP_Default_bVelChange="false", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void AddPhysicsImpulse(AActor* PhysicsObject, FVector Impulse, bool bTempered, FName BoneName, bool bVelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_bTempered="true", CPP_Default_BoneName="None", CPP_Default_bVelChange="false", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void AddPhysicsImpulseAtLocation(AActor* PhysicsObject, FVector Impulse, FVector Location, bool bTempered, FName BoneName, bool bVelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_bTempered="true", CPP_Default_BoneName="None", CPP_Default_bVelChange="false", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void AddPhysicsImpulseAtLocationWithPrediction(AActor* PhysicsObject, FVector Impulse, FVector Location, bool bTempered, FName BoneName, bool bVelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_BoneName="None", CPP_Default_bAccelChange="false", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void AddPhysicsTorque(AActor* PhysicsObject, FVector Torque, FName BoneName, bool bAccelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool CanActorSimulatePhysics(const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static void ClearImpactInstigatorFromPhysicsObject(AActor* PhysicsObject);

	UFUNCTION(Category="Fort Physics Simulation Library")
	static void ClearPhysicsReplicationErrorCorrection(AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static float CmSToKmH(const float CmS);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(WorldContext="WorldContextObject"))
	static FVector ComputeAngularDrag(const FVector& BodyUp, const FVector& BodyRight, const FVector& BodyForward, const FVector& AngularVelocity, const float PitchAngularDrag, const float YawAngularDrag, const float RollAngularDrag, const float DragMultiplier);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(WorldContext="WorldContextObject"))
	static FVector ComputeLinearAccel(const FVector& CurrentLinearVelocity, const FVector& TargetDirection, const float MaxLinearVelocity, const float AccelForce);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(WorldContext="WorldContextObject"))
	static FVector ComputeLinearDrag(const FVector& LinearVelocity, const float MaxDragSpeed, const float FirstOrderDragCoef, const float SecondOrderDragCoef);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(WorldContext="WorldContextObject"))
	static FVector ComputeSpringDampedAngularAccel(const FVector& Target, const FVector& Current, const FVector& AngVelocityWorld, const float Stiffness, const float Damping, const float MaxAccel);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static FVector ComputeTemperedImpulse(AActor* PhysicsObject, FVector Impulse);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static FVector ComputeTorqueForTargetRotation(AActor* PhysicsObject, const FRotator& TargetRotation, float Stiffness = 20.000000f, float Damping = 5.000000f, float MaxAccel = 1000.000000f);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(WorldContext="WorldContextObject"))
	static FVector ComputeTurningAngularAccel(const FVector& TargetForward, const FVector& BodyForward, const FVector& BodyRight, const float YawForce);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(WorldContext="WorldContextObject"))
	static FVector ComputeVelocityFromImpulse(UPrimitiveComponent* PrimitiveComponent, const FVector Impulse);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static UPhysicsConstraintComponent* CreatePhysicsConstraintBetween(AActor* Actor1, FName BoneName1, AActor* Actor2, FName BoneName2, const FVector& WorldLocation);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool DoesPhysicsObjectHaveGravity(const AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool DoesPhysicsObjectMeetSizeRequirement(const AActor* PhysicsObject, const EFortPhysicsSimSize SizeRequirement = EFortPhysicsSimSize::Medium);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool EvaluatePhysicsObjectEmbeddedInLandscape(const ABuildingActor* BuildingActor);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library|Cluster Unions")
	static TArray<AActor*> GetAttachedAndClusterUnionedActorsWithFilter(AActor* SourceActor, FGameplayTagRequirements TagFilter, TSubclassOf<AActor> ActorFilter);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static void GetBodyBounds(UPrimitiveComponent* PrimitiveComponent, FBox& OutBodyBox, FVector& OutBoxExtent);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static FVector GetBoxExtent(UPrimitiveComponent* PrimitiveComponent);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static AActor* GetDamageInstigatorForPhysicsCollision(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(WorldContext="WorldContextObject"))
	static FVector GetDesiredLateralMoveDirectionFromInput(const FVector& DriverCameraForward, const float ForwardAlpha, const float RightAlpha);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static FVector GetImpulseVectorForDirectHit(FVector ImpactNormal, float ImpulseStrength);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static float GetMass(const AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_OptionalVelocityModificationRatio="1.000000", CPP_Default_OptionalVelocity))
	static FVector GetPhysicsBodyCenter(AActor* InActor, const float OptionalVelocityModificationRatio, const FVector OptionalVelocity);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static EFortPhysicsSimSize GetPhysicsObjectSimSize(const AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static EFortPhysicsObjectType GetPhysicsObjectType(const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static const AActor* GetRootPhysicsObjectForSimulating(const AActor* PhysicsObject);

	UFUNCTION(BlueprintPure, Category="Fort Physics Simulation Library")
	static UPrimitiveComponent* GetSimulatingComponent(const AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static void IgnorePawnForBasingOnPhysicsObject(AActor* PawnToIgnore, AActor* PhysicsObject, bool bIgnore = true, float OptionalIgnoreTime = -1.000000f);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool IsPhysicsObjectActiveInSimulation(const AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool IsPhysicsObjectEmbeddedInLandscape(const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool IsPhysicsObjectIgnoringPawnForBasing(AActor* PotentiallyIgnoredPawn, AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static float KmHToCmS(const float KmH);

	UFUNCTION(Category="Fort Physics Simulation Library")
	static void OverridePhysicsReplicationErrorCorrection(AActor* PhysicsObject, FRigidBodyErrorCorrection NewErrorCorrection);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool PassedCookLandscapeEmbeddingEvaluation(const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool PassedCookSizeValidation(const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool PerformPhysicsObjectValidationChecks(const AActor* PhysicsObject, const FPhysicsSimValidateObject& ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static void PutToSleep(AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static void SetEnableImpulseOnDamageForPhysicsObject(AActor* PhysicsObject, bool bEnable);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static void SetImpactInstigatorForPhysicsObject(AActor* PhysicsObject, AActor* Instigator);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_bAddToCurrent="false", CPP_Default_BoneName="None", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void SetPhysicsAngularVelocity(AActor* PhysicsObject, FVector NewAngVel, bool bAddToCurrent, FName BoneName, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_bAddToCurrent="false", CPP_Default_BoneName="None", CPP_Default_Instigator="None", CPP_Default_ValidationChecks="()"))
	static void SetPhysicsLinearVelocity(AActor* PhysicsObject, FVector NewVel, bool bAddToCurrent, FName BoneName, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool ShouldDeferPhysicsComponentCreation(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static bool ShouldPropDeferPhysicsComponentCreation(const ABuildingActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_ValidationChecks="()"))
	static void StartSimulatingPhysicsObject(AActor* PhysicsObject, const FPhysicsSimValidateObject ValidationChecks);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library")
	static void StopSimulatingPhysicsObject(AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Simulation Library", meta=(CPP_Default_ValidationChecks="()"))
	static bool WakeUp(AActor* PhysicsObject, const FPhysicsSimValidateObject ValidationChecks);

};

