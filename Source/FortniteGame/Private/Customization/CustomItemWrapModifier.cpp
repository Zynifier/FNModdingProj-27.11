// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/CustomItemWrapModifier.h"

AActor* ACustomItemWrapModifier::GetVehicle() const
{
	return nullptr;
}

AFortWeapon* ACustomItemWrapModifier::GetWeapon() const
{
	return nullptr;
}

UMeshComponent* ACustomItemWrapModifier::GetWrappedMeshComponent() const
{
	return nullptr;
}

TArray<UMeshComponent*> ACustomItemWrapModifier::GetWrappedMeshComponents() const
{
	return TArray<UMeshComponent*>();
}

void ACustomItemWrapModifier::HandlePawnPostResIn(AFortPlayerPawn* Pawn)
{
}

void ACustomItemWrapModifier::OnSetWrapTarget_Implementation()
{
}
