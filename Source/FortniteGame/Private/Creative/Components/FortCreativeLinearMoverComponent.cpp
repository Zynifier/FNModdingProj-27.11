// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/FortCreativeLinearMoverComponent.h"
#include "Net/UnrealNetwork.h"

void UFortCreativeLinearMoverComponent::AddActorToIgnoreDuringMovement(AActor* Actor)
{
}

void UFortCreativeLinearMoverComponent::ComponentHit(const UPrimitiveComponent* HitComponent, const AActor* OtherActor, const UPrimitiveComponent* OtherComp, const FVector NormalImpulse, const FHitResult& Hit)
{
}

ABuildingActor* UFortCreativeLinearMoverComponent::GetNearestOverlappingBuildingActor() const
{
	return nullptr;
}

bool UFortCreativeLinearMoverComponent::IsMovementFinished() const
{
	return false;
}

void UFortCreativeLinearMoverComponent::OnEnabledStateChanged(const bool bEnabled)
{
}

void UFortCreativeLinearMoverComponent::OnMinigamePlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode)
{
}

void UFortCreativeLinearMoverComponent::OnRep_ActorsToIgnoreDuringMovement()
{
}

void UFortCreativeLinearMoverComponent::OnRep_RotationMovementData()
{
}

void UFortCreativeLinearMoverComponent::OnRep_Target(TWeakObjectPtr<ABuildingActor> OldTarget)
{
}

void UFortCreativeLinearMoverComponent::OnRep_TranslationMovementData()
{
}

void UFortCreativeLinearMoverComponent::ResetActorsToIgnoreDuringMovement()
{
}

void UFortCreativeLinearMoverComponent::ResetRotation()
{
}

void UFortCreativeLinearMoverComponent::ResetTranslation()
{
}

void UFortCreativeLinearMoverComponent::Rotate(const bool bTeleport)
{
}

void UFortCreativeLinearMoverComponent::RotateTo(const FRotator& TargetRotation, const bool bTeleport)
{
}

void UFortCreativeLinearMoverComponent::SetRotationDirection(EFortCreativeLinearMoverRotationDirection InRotationDirection, AController* Instigator)
{
}

void UFortCreativeLinearMoverComponent::SetTranslationType(EFortCreativeLinearMoverTranslationType InTranslationType, AController* Instigator)
{
}

void UFortCreativeLinearMoverComponent::StopRotation()
{
}

void UFortCreativeLinearMoverComponent::StopTranslation()
{
}

void UFortCreativeLinearMoverComponent::Translate(const bool bTeleport)
{
}

void UFortCreativeLinearMoverComponent::TranslateTo(const FVector& TargetLocation, const bool bTeleport)
{
}

void UFortCreativeLinearMoverComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCreativeLinearMoverComponent, Target);
	DOREPLIFETIME(UFortCreativeLinearMoverComponent, TranslationMovementData);
	DOREPLIFETIME(UFortCreativeLinearMoverComponent, RotationMovementData);
	DOREPLIFETIME(UFortCreativeLinearMoverComponent, ActorsToIgnoreDuringMovement);
}
