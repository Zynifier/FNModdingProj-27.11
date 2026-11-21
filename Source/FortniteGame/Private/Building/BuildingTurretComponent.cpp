// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingTurretComponent.h"
#include "Net/UnrealNetwork.h"

bool UBuildingTurretComponent::AttemptSetCurrentTarget(AActor* NewTarget)
{
	return false;
}

AActor* UBuildingTurretComponent::ChooseBestTarget_Implementation(TArray<AActor*>& InOutPotentialTargets) const
{
	return nullptr;
}

bool UBuildingTurretComponent::IsValidTarget_Implementation(AActor* InTarget) const
{
	return false;
}

void UBuildingTurretComponent::OnFiringTimer()
{
}

void UBuildingTurretComponent::OnPerformTargetValidation()
{
}

void UBuildingTurretComponent::OnRep_CurrentTarget(AActor* OldTarget)
{
}

void UBuildingTurretComponent::OnTargetingBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UBuildingTurretComponent::OnTargetingEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void UBuildingTurretComponent::SetTargetingOverlapComponent(UPrimitiveComponent* NewTargetingOverlapComponent)
{
}

void UBuildingTurretComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UBuildingTurretComponent, CurrentTarget);
}
