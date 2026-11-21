// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Markers/FortAutoMarkableActorComponent.h"

void UFortAutoMarkableActorComponent::OnAutoMarkCollisionChanged(UPrimitiveComponent* ChangedComponent)
{
}

void UFortAutoMarkableActorComponent::OnAutoMarkCollisionComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UFortAutoMarkableActorComponent::OnAutoMarkCollisionComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void UFortAutoMarkableActorComponent::SetAutoMarkCollisionComponent(UPrimitiveComponent* InAutoMarkCollisionComponent)
{
}
