// Copyright Epic Games, Inc. All Rights Reserved.

#include "Physics/FortPhysicsObjectComponent.h"
#include "Net/UnrealNetwork.h"

UFortPhysicsObjectComponent::UFortPhysicsObjectComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortPhysicsObjectComponent::ActivatePhysicsObject(UFortPhysicsObjectComponent* PhysicsObjectComponent, EFortPhysicsObjectActivationType InActivationType)
{
}

void UFortPhysicsObjectComponent::AddToIgnoredDamageActors(const AActor* InActor)
{
}

bool UFortPhysicsObjectComponent::BP_HasSetupPhysicsObject(AActor* PhysicsObject)
{
	return false;
}

void UFortPhysicsObjectComponent::CacheLastPlayerHit(AFortPlayerPawn* Player)
{
}

void UFortPhysicsObjectComponent::ClearIgnoredDamageActors()
{
}

void UFortPhysicsObjectComponent::DecrementNeverSleep()
{
}

void UFortPhysicsObjectComponent::DeferredSetupPhysicsObject()
{
}

void UFortPhysicsObjectComponent::DisableMovementStateUpdates(AActor* PhysicsObject)
{
}

void UFortPhysicsObjectComponent::DisableOverlapEvents(AActor* PhysicsObject)
{
}

void UFortPhysicsObjectComponent::EnableMovementStateUpdates(AActor* PhysicsObject)
{
}

void UFortPhysicsObjectComponent::EnableOverlapEvents(AActor* PhysicsObject)
{
}

void UFortPhysicsObjectComponent::GetCachedRidingPlayersInfo(int32& NumberOfCachedPlayer, TArray<FVector>& OnBoardLocation, TArray<FVector>& OffBoardLocation, TArray<float>& SessionLength, bool bCleanAfterCopy)
{
}

float UFortPhysicsObjectComponent::GetGravity(bool bUseGravityMultiplier) const
{
	return float();
}

const float UFortPhysicsObjectComponent::GetMaxLinearVelocityOverride() const
{
	return float();
}

void UFortPhysicsObjectComponent::GetMovingStateData(AActor*& OutInstigator, FHitResult& OutHitResult, float& OutLinearSpeed, EFortPhysicsObjectMovementState& OutMovementState) const
{
}

UPrimitiveComponent* UFortPhysicsObjectComponent::GetSimulatingComponent() const
{
	return nullptr;
}

void UFortPhysicsObjectComponent::HandleBasingChange(AFortPawn* BasedPawn)
{
}

void UFortPhysicsObjectComponent::HandleBuildingAbilitySystemComponentInitialized()
{
}

void UFortPhysicsObjectComponent::HandleConnectedActorDestroyed(AActor* DamageCauser)
{
}

void UFortPhysicsObjectComponent::HandleConnectedPhysicsActorWake(AActor* PhysicsActor)
{
}

void UFortPhysicsObjectComponent::HandleEnteredWaterBody(const FSphericalPontoon& FXPoint)
{
}

void UFortPhysicsObjectComponent::HandleLinkedActorDisconnected()
{
}

void UFortPhysicsObjectComponent::HandlePreAbilitySystemComponentInitialized()
{
}

void UFortPhysicsObjectComponent::HandleSimulatingComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& InHit)
{
}

void UFortPhysicsObjectComponent::HandleSimulatingComponentSleep(UPrimitiveComponent* SleepingComponent, FName BoneName)
{
}

void UFortPhysicsObjectComponent::HandleSimulatingComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName)
{
}

void UFortPhysicsObjectComponent::IgnorePawnForBasing(AFortPawn* Pawn, bool bIgnoreBasing, float OptionalIgnoreTime)
{
}

void UFortPhysicsObjectComponent::IgnorePawnForCollision(AFortPawn* Pawn, bool bIgnore, bool bIgnoreQueryCollision)
{
}

void UFortPhysicsObjectComponent::IncrementNeverSleep()
{
}

bool UFortPhysicsObjectComponent::IsAwake() const
{
	return false;
}

void UFortPhysicsObjectComponent::OnRep_ActivationType()
{
}

void UFortPhysicsObjectComponent::OnRep_AwakeState()
{
}

void UFortPhysicsObjectComponent::OnRep_DeactivationSnapshotData()
{
}

void UFortPhysicsObjectComponent::OnRep_DisableMovementStateUpdates()
{
}

void UFortPhysicsObjectComponent::OnRep_DisableOverlapEvents()
{
}

void UFortPhysicsObjectComponent::OnRep_PhysicsObjectSetupTags(const FPhysicsObjectSetupTags& PrevPhysicsObjectSetupTags)
{
}

void UFortPhysicsObjectComponent::OnRep_ServerHasSetupPhysicsObject()
{
}

void UFortPhysicsObjectComponent::PutToSleep()
{
}

void UFortPhysicsObjectComponent::PutToSleepPhysicsObject(AActor* PhysicsObject)
{
}

void UFortPhysicsObjectComponent::RemoveFromIgnoredDamageActors(const AActor* InActor)
{
}

void UFortPhysicsObjectComponent::SetAngularDamping(AActor* PhysicsObject, const TArray<FGameplayTag>& PresetTagsRequired, const bool bUsePresetValue, const float InAngularDamping)
{
}

void UFortPhysicsObjectComponent::SetBaseDamageOverrides(const FFortPhysicsObjectBaseDamageOverrides& InBaseDamageOverrides)
{
}

void UFortPhysicsObjectComponent::SetGravityOverride(const bool bInGravityOverridden, const float InGravityOverride)
{
}

void UFortPhysicsObjectComponent::SetLinearDampingOverride(const float InLinearDampingOverride)
{
}

void UFortPhysicsObjectComponent::SetMassOverride(const float InMassOverride, const bool bInScaleMassWithObjectScale)
{
}

void UFortPhysicsObjectComponent::SetMaxLinearVelocity(const float InMaxLinearVelocityOverride)
{
}

void UFortPhysicsObjectComponent::SetPhysicsObjectPhysicalDataTag(AActor* PhysicsObject, const FGameplayTag& InPhysicsObjectPresetTag)
{
}

void UFortPhysicsObjectComponent::WakeUp(EFortPhysicsObjectActivationType InActivationType)
{
}

void UFortPhysicsObjectComponent::WakeUpPhysicsObject(AActor* PhysicsObject, EFortPhysicsObjectActivationType InActivationType)
{
}

void UFortPhysicsObjectComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPhysicsObjectComponent, PhysicsObjectSetupTags);
	DOREPLIFETIME(UFortPhysicsObjectComponent, GravityOverride);
	DOREPLIFETIME(UFortPhysicsObjectComponent, ActivationType);
	DOREPLIFETIME(UFortPhysicsObjectComponent, PhysicsObjectAwakeState);
	DOREPLIFETIME(UFortPhysicsObjectComponent, bServerHasSetupPhysicsObject);
	DOREPLIFETIME(UFortPhysicsObjectComponent, bForceStartActiveAndAwake);
	DOREPLIFETIME(UFortPhysicsObjectComponent, bDisableOverlapEvents);
	DOREPLIFETIME(UFortPhysicsObjectComponent, bDisableMovementStateUpdates);
	DOREPLIFETIME(UFortPhysicsObjectComponent, bGravityOverridden);
	DOREPLIFETIME(UFortPhysicsObjectComponent, DeactivationSnapshotData);
	DOREPLIFETIME(UFortPhysicsObjectComponent, IgnoredPawnsForBasing);
}
