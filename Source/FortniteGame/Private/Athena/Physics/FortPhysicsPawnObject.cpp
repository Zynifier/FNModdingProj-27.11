// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Physics/FortPhysicsPawnObject.h"
#include "Net/UnrealNetwork.h"

void AFortPhysicsPawnObject::ApplyImpulse(AActor* ImpulseInstigator, const FVector& ImpulseToApply)
{
}

void AFortPhysicsPawnObject::ApplyImpulseFromPawnHit(const FVector& VelocityOfHitter, const FVector& NormalTowardObject, APawn* HittingPawn)
{
}

void AFortPhysicsPawnObject::ApplyPredictedImpulseFromPawnHitClient(const FVector& VelocityOfHitter, const FVector& NormalTowardObject, APawn* HittingPawn)
{
}

bool AFortPhysicsPawnObject::CanCorrectOrientation(AFortPawn* FP) const
{
	return false;
}

bool AFortPhysicsPawnObject::CanTeleport() const
{
	return false;
}

void AFortPhysicsPawnObject::DebugDrawImpactBucket_Implementation(FVector Location, FVector ImpactVector, FColor Color)
{
}

void AFortPhysicsPawnObject::DestroyPhysicsObject()
{
}

void AFortPhysicsPawnObject::DrawServerAndClientBallPosition_Implementation(const FVector ServerPosition)
{
}

void AFortPhysicsPawnObject::GameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

FString AFortPhysicsPawnObject::GetDisplayName() const
{
	return FString();
}

float AFortPhysicsPawnObject::GetForwardSpeedKmh() const
{
	return float();
}

float AFortPhysicsPawnObject::GetHealth() const
{
	return float();
}

float AFortPhysicsPawnObject::GetMaxHealth() const
{
	return float();
}

FVector AFortPhysicsPawnObject::GetPhysicsObjectVelocity() const
{
	return FVector();
}

float AFortPhysicsPawnObject::GetPreviousForwardSpeedKmh() const
{
	return float();
}

FVector AFortPhysicsPawnObject::GetPreviousLinearAcceleration() const
{
	return FVector();
}

FVector AFortPhysicsPawnObject::GetPreviousLinearVelocity() const
{
	return FVector();
}

bool AFortPhysicsPawnObject::HasPermissionToAlterBuildings() const
{
	return false;
}

bool AFortPhysicsPawnObject::IsAsleep() const
{
	return false;
}

bool AFortPhysicsPawnObject::IsCorrectingOrientation() const
{
	return false;
}

bool AFortPhysicsPawnObject::IsInAir() const
{
	return false;
}

bool AFortPhysicsPawnObject::IsInWater() const
{
	return false;
}

bool AFortPhysicsPawnObject::IsScrapingSidesOrTop() const
{
	return false;
}

float AFortPhysicsPawnObject::ModifyIncomingDamage(float Damage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser)
{
	return float();
}

void AFortPhysicsPawnObject::OnPxComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName)
{
}

void AFortPhysicsPawnObject::OnRep_AbilitySystemComponent()
{
}

void AFortPhysicsPawnObject::OnRep_CorrectTargetOrientation()
{
}

void AFortPhysicsPawnObject::OnRep_CurrentServerPhysicsState()
{
}

void AFortPhysicsPawnObject::OnRep_HealthSet()
{
}

void AFortPhysicsPawnObject::OnRep_InitialParameters()
{
}

void AFortPhysicsPawnObject::OnRep_LastServerConfirmedHit()
{
}

void AFortPhysicsPawnObject::OnRep_PendingDeath()
{
}

void AFortPhysicsPawnObject::OnRep_SurfaceTypePhysicsObjectOn(EPhysicalSurface PreviousSurfaceOn)
{
}

void AFortPhysicsPawnObject::SendClientStateToServer_Helper()
{
}

void AFortPhysicsPawnObject::ServerBroadcastHit_Implementation(APawn* ImpulseInstigator, const FVector ImpactPoint, const FVector ImpulseValue)
{
}

void AFortPhysicsPawnObject::ServerBroadcastHitFromClient_Implementation(APlayerController* HittingController, APawn* HittingPawn, const FVector& VelocityOfHitter, const FVector& HitNormal, const FTimeStampedPhysicsPawnState& ClientBallState)
{
}

void AFortPhysicsPawnObject::SetDyingPhysics()
{
}

void AFortPhysicsPawnObject::SetHealthPercent(float Percent)
{
}

void AFortPhysicsPawnObject::SetImpulseResponseMultiplier(const float Multiplier)
{
}

void AFortPhysicsPawnObject::SetImpulseResponseZBias(const float ZBias)
{
}

void AFortPhysicsPawnObject::SetPropDestructionParams(TArray<TSubclassOf<ABuildingActor>> InBuildingPropClassesPhysicsObjectCanDestroy, TArray<UBuildingEditModeMetadata*> InWallsPhysicsObjectCanDestroy)
{
}

AFortPhysicsPawnObject* AFortPhysicsPawnObject::SpawnPhysicsPawnObject(const UObject* WorldContextObject, TSubclassOf<AFortPhysicsPawnObject> ActorClass, const FTransform& Transform, const FPhysicsPawnObjectInitialParameters& InitialParameters)
{
	return nullptr;
}

void AFortPhysicsPawnObject::TurnOffClientPrediction()
{
}

void AFortPhysicsPawnObject::UpdateClientWithPhysicsObjectTestInput_Implementation(FVector LinearVelocity, FVector AngularVelocity)
{
}

void AFortPhysicsPawnObject::WakeUp()
{
}

void AFortPhysicsPawnObject::WakeUpOnGroundDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortPhysicsPawnObject::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPhysicsPawnObject, CorrectTargetOrientation);
	DOREPLIFETIME(AFortPhysicsPawnObject, AbilitySystemComponent);
	DOREPLIFETIME(AFortPhysicsPawnObject, HealthSet);
	DOREPLIFETIME(AFortPhysicsPawnObject, bPendingDeath);
	DOREPLIFETIME(AFortPhysicsPawnObject, SurfaceTypePhysicsObjectOn);
	DOREPLIFETIME(AFortPhysicsPawnObject, CurrentServerPhysicsState);
	DOREPLIFETIME(AFortPhysicsPawnObject, LastServerConfirmedHit);
	DOREPLIFETIME(AFortPhysicsPawnObject, InitialParameters);
}

UAbilitySystemComponent* AFortPhysicsPawnObject::GetAbilitySystemComponent() const
{
	return nullptr;
}

void AFortPhysicsPawnObject::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}
