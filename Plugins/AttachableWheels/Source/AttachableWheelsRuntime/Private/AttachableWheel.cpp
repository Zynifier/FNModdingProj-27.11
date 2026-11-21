// Copyright Epic Games, Inc. All Rights Reserved.

#include "AttachableWheel.h"
#include "Net/UnrealNetwork.h"

bool AAttachableWheel::AttachInPlace(UPrimitiveComponent* InComponent)
{
	return false;
}

bool AAttachableWheel::AttachTo(UPrimitiveComponent* InComponent, const FVector& WorldLocation, const FVector& AxleDirection)
{
	return false;
}

void AAttachableWheel::Detach()
{
}

bool AAttachableWheel::DetachFrom(UPrimitiveComponent* InComponent)
{
	return false;
}

void AAttachableWheel::DrawDebug() const
{
}

AActor* AAttachableWheel::GetActorRef()
{
	return nullptr;
}

UPrimitiveComponent* AAttachableWheel::GetAttachedComponent() const
{
	return nullptr;
}

bool AAttachableWheel::GetWorldSpaceAttachData(FAttachableWheelAttachData& OutAttachData, UPrimitiveComponent* PrimitiveComponent, const FName BodyName) const
{
	return false;
}

void AAttachableWheel::OnPhysicsStateChanged(UPrimitiveComponent* PrimitiveComponent, EComponentPhysicsStateChange StateChange)
{
}

void AAttachableWheel::OnRep_AttachData(const FAttachableWheelAttachData& AttachDataPrev)
{
}

void AAttachableWheel::SetActorRef(AActor* NewActorRef)
{
}

void AAttachableWheel::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAttachableWheel, AttachData);
}
