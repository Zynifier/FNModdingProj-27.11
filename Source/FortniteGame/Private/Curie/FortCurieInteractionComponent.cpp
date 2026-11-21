// Copyright Epic Games, Inc. All Rights Reserved.

#include "Curie/FortCurieInteractionComponent.h"

void UFortCurieInteractionComponent::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UFortCurieInteractionComponent::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void UFortCurieInteractionComponent::HandleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

void UFortCurieInteractionComponent::OnCurieStateAttached(UObject* Owner, FCurieContainerHandle ContainerHandle, const FGameplayTag& StateIdentifier)
{
}

void UFortCurieInteractionComponent::OnCurieStateDetached(UObject* Owner, FCurieContainerHandle ContainerHandle, const FGameplayTag& StateIdentifier)
{
}

void UFortCurieInteractionComponent::RegisterCollisionComponent(UPrimitiveComponent* InCollisionComponent)
{
}

void UFortCurieInteractionComponent::UnregisterCollisionComponent()
{
}
