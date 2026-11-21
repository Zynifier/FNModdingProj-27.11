// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeakPoints/FortWeakPointsCoordinatorComponent.h"
#include "Net/UnrealNetwork.h"

UFortWeakPointsCoordinatorComponent::UFortWeakPointsCoordinatorComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortWeakPointsCoordinatorComponent::ActivateAllWeakPointsByTag(const FGameplayTag& WeakPointsTag)
{
}

void UFortWeakPointsCoordinatorComponent::DeactivateAllWeakPointsByTag(const FGameplayTag& WeakPointsTag)
{
}

void UFortWeakPointsCoordinatorComponent::OnRep_WeakPoints()
{
}

void UFortWeakPointsCoordinatorComponent::OnWeakPointDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum)
{
}

void UFortWeakPointsCoordinatorComponent::OnWeakPointStateChanged(AFortWeakPoint* WeakPoint, EFortWeakPointState NewState)
{
}

void UFortWeakPointsCoordinatorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortWeakPointsCoordinatorComponent, WeakPointTypes);
}
