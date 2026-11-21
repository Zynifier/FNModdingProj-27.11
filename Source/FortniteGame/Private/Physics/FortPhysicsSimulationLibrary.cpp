// Copyright Epic Games, Inc. All Rights Reserved.

#include "Physics/FortPhysicsSimulationLibrary.h"

void UFortPhysicsSimulationLibrary::AddPhysicsAngularImpulse(AActor* PhysicsObject, FVector AngularImpulse, FName BoneName, bool bVelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::AddPhysicsForce(AActor* PhysicsObject, FVector Force, FName BoneName, bool bAccelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::AddPhysicsForceAtLocation(AActor* PhysicsObject, FVector Force, FVector Location, FName BoneName, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::AddPhysicsForceAtLocationWithPrediction(AActor* PhysicsObject, FVector Force, FVector Location, FName BoneName, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::AddPhysicsForceWithPrediction(AActor* PhysicsObject, FVector Force, FName BoneName, bool bAccelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::AddPhysicsImpulse(AActor* PhysicsObject, FVector Impulse, bool bTempered, FName BoneName, bool bVelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::AddPhysicsImpulseAtLocation(AActor* PhysicsObject, FVector Impulse, FVector Location, bool bTempered, FName BoneName, bool bVelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::AddPhysicsImpulseAtLocationWithPrediction(AActor* PhysicsObject, FVector Impulse, FVector Location, bool bTempered, FName BoneName, bool bVelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::AddPhysicsTorque(AActor* PhysicsObject, FVector Torque, FName BoneName, bool bAccelChange, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

bool UFortPhysicsSimulationLibrary::CanActorSimulatePhysics(const AActor* Actor)
{
	return false;
}

void UFortPhysicsSimulationLibrary::ClearImpactInstigatorFromPhysicsObject(AActor* PhysicsObject)
{
}

void UFortPhysicsSimulationLibrary::ClearPhysicsReplicationErrorCorrection(AActor* PhysicsObject)
{
}

float UFortPhysicsSimulationLibrary::CmSToKmH(const float CmS)
{
	return float();
}

FVector UFortPhysicsSimulationLibrary::ComputeAngularDrag(const FVector& BodyUp, const FVector& BodyRight, const FVector& BodyForward, const FVector& AngularVelocity, const float PitchAngularDrag, const float YawAngularDrag, const float RollAngularDrag, const float DragMultiplier)
{
	return FVector();
}

FVector UFortPhysicsSimulationLibrary::ComputeLinearAccel(const FVector& CurrentLinearVelocity, const FVector& TargetDirection, const float MaxLinearVelocity, const float AccelForce)
{
	return FVector();
}

FVector UFortPhysicsSimulationLibrary::ComputeLinearDrag(const FVector& LinearVelocity, const float MaxDragSpeed, const float FirstOrderDragCoef, const float SecondOrderDragCoef)
{
	return FVector();
}

FVector UFortPhysicsSimulationLibrary::ComputeSpringDampedAngularAccel(const FVector& Target, const FVector& Current, const FVector& AngVelocityWorld, const float Stiffness, const float Damping, const float MaxAccel)
{
	return FVector();
}

FVector UFortPhysicsSimulationLibrary::ComputeTemperedImpulse(AActor* PhysicsObject, FVector Impulse)
{
	return FVector();
}

FVector UFortPhysicsSimulationLibrary::ComputeTorqueForTargetRotation(AActor* PhysicsObject, const FRotator& TargetRotation, float Stiffness, float Damping, float MaxAccel)
{
	return FVector();
}

FVector UFortPhysicsSimulationLibrary::ComputeTurningAngularAccel(const FVector& TargetForward, const FVector& BodyForward, const FVector& BodyRight, const float YawForce)
{
	return FVector();
}

FVector UFortPhysicsSimulationLibrary::ComputeVelocityFromImpulse(UPrimitiveComponent* PrimitiveComponent, const FVector Impulse)
{
	return FVector();
}

UPhysicsConstraintComponent* UFortPhysicsSimulationLibrary::CreatePhysicsConstraintBetween(AActor* Actor1, FName BoneName1, AActor* Actor2, FName BoneName2, const FVector& WorldLocation)
{
	return nullptr;
}

bool UFortPhysicsSimulationLibrary::DoesPhysicsObjectHaveGravity(const AActor* PhysicsObject)
{
	return false;
}

bool UFortPhysicsSimulationLibrary::DoesPhysicsObjectMeetSizeRequirement(const AActor* PhysicsObject, const EFortPhysicsSimSize SizeRequirement)
{
	return false;
}

bool UFortPhysicsSimulationLibrary::EvaluatePhysicsObjectEmbeddedInLandscape(const ABuildingActor* BuildingActor)
{
	return false;
}

TArray<AActor*> UFortPhysicsSimulationLibrary::GetAttachedAndClusterUnionedActorsWithFilter(AActor* SourceActor, FGameplayTagRequirements TagFilter, TSubclassOf<AActor> ActorFilter)
{
	return TArray<AActor*>();
}

void UFortPhysicsSimulationLibrary::GetBodyBounds(UPrimitiveComponent* PrimitiveComponent, FBox& OutBodyBox, FVector& OutBoxExtent)
{
}

FVector UFortPhysicsSimulationLibrary::GetBoxExtent(UPrimitiveComponent* PrimitiveComponent)
{
	return FVector();
}

AActor* UFortPhysicsSimulationLibrary::GetDamageInstigatorForPhysicsCollision(AActor* InActor)
{
	return nullptr;
}

FVector UFortPhysicsSimulationLibrary::GetDesiredLateralMoveDirectionFromInput(const FVector& DriverCameraForward, const float ForwardAlpha, const float RightAlpha)
{
	return FVector();
}

FVector UFortPhysicsSimulationLibrary::GetImpulseVectorForDirectHit(FVector ImpactNormal, float ImpulseStrength)
{
	return FVector();
}

float UFortPhysicsSimulationLibrary::GetMass(const AActor* InActor)
{
	return float();
}

FVector UFortPhysicsSimulationLibrary::GetPhysicsBodyCenter(AActor* InActor, const float OptionalVelocityModificationRatio, const FVector OptionalVelocity)
{
	return FVector();
}

EFortPhysicsSimSize UFortPhysicsSimulationLibrary::GetPhysicsObjectSimSize(const AActor* PhysicsObject)
{
	return EFortPhysicsSimSize();
}

EFortPhysicsObjectType UFortPhysicsSimulationLibrary::GetPhysicsObjectType(const AActor* Actor)
{
	return EFortPhysicsObjectType();
}

const AActor* UFortPhysicsSimulationLibrary::GetRootPhysicsObjectForSimulating(const AActor* PhysicsObject)
{
	return nullptr;
}

UPrimitiveComponent* UFortPhysicsSimulationLibrary::GetSimulatingComponent(const AActor* PhysicsObject)
{
	return nullptr;
}

void UFortPhysicsSimulationLibrary::IgnorePawnForBasingOnPhysicsObject(AActor* PawnToIgnore, AActor* PhysicsObject, bool bIgnore, float OptionalIgnoreTime)
{
}

bool UFortPhysicsSimulationLibrary::IsPhysicsObjectActiveInSimulation(const AActor* PhysicsObject)
{
	return false;
}

bool UFortPhysicsSimulationLibrary::IsPhysicsObjectEmbeddedInLandscape(const AActor* Actor)
{
	return false;
}

bool UFortPhysicsSimulationLibrary::IsPhysicsObjectIgnoringPawnForBasing(AActor* PotentiallyIgnoredPawn, AActor* PhysicsObject)
{
	return false;
}

float UFortPhysicsSimulationLibrary::KmHToCmS(const float KmH)
{
	return float();
}

void UFortPhysicsSimulationLibrary::OverridePhysicsReplicationErrorCorrection(AActor* PhysicsObject, FRigidBodyErrorCorrection NewErrorCorrection)
{
}

bool UFortPhysicsSimulationLibrary::PassedCookLandscapeEmbeddingEvaluation(const AActor* Actor)
{
	return false;
}

bool UFortPhysicsSimulationLibrary::PassedCookSizeValidation(const AActor* Actor)
{
	return false;
}

bool UFortPhysicsSimulationLibrary::PerformPhysicsObjectValidationChecks(const AActor* PhysicsObject, const FPhysicsSimValidateObject& ValidationChecks)
{
	return false;
}

void UFortPhysicsSimulationLibrary::PutToSleep(AActor* PhysicsObject)
{
}

void UFortPhysicsSimulationLibrary::SetEnableImpulseOnDamageForPhysicsObject(AActor* PhysicsObject, bool bEnable)
{
}

void UFortPhysicsSimulationLibrary::SetImpactInstigatorForPhysicsObject(AActor* PhysicsObject, AActor* Instigator)
{
}

void UFortPhysicsSimulationLibrary::SetPhysicsAngularVelocity(AActor* PhysicsObject, FVector NewAngVel, bool bAddToCurrent, FName BoneName, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::SetPhysicsLinearVelocity(AActor* PhysicsObject, FVector NewVel, bool bAddToCurrent, FName BoneName, AActor* Instigator, const FPhysicsSimValidateObject ValidationChecks)
{
}

bool UFortPhysicsSimulationLibrary::ShouldDeferPhysicsComponentCreation(const UObject* WorldContextObject)
{
	return false;
}

bool UFortPhysicsSimulationLibrary::ShouldPropDeferPhysicsComponentCreation(const ABuildingActor* PhysicsObject)
{
	return false;
}

void UFortPhysicsSimulationLibrary::StartSimulatingPhysicsObject(AActor* PhysicsObject, const FPhysicsSimValidateObject ValidationChecks)
{
}

void UFortPhysicsSimulationLibrary::StopSimulatingPhysicsObject(AActor* PhysicsObject)
{
}

bool UFortPhysicsSimulationLibrary::WakeUp(AActor* PhysicsObject, const FPhysicsSimValidateObject ValidationChecks)
{
	return false;
}
