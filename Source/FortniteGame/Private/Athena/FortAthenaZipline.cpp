// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaZipline.h"
#include "Net/UnrealNetwork.h"

bool AFortAthenaZiplineBase::AttempOverrideLaunch_Implementation(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent, const bool bJumped, const bool bReachedEnd, const FVector& CurrentVelocity) const
{
	return false;
}

bool AFortAthenaZiplineBase::AttemptOverrideZiplineSocketOffset_Implementation(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent, const FVector& BaseSocketOffset, FVector& OutSocketOffset) const
{
	return false;
}

void AFortAthenaZiplineBase::AuthorityForceEndZiplining(AFortPlayerPawn* PawnToStop)
{
}

bool AFortAthenaZiplineBase::CanBeginZiplining_Implementation(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent) const
{
	return false;
}

void AFortAthenaZiplineBase::HandleActorHitWhileMoving_Implementation(AFortPlayerPawn* InteractingPawn, AActor* HitActor, bool& bOutIsHitActorImmobile) const
{
}

bool AFortAthenaZiplineBase::IsVariableSpeedEnabled_Implementation(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent) const
{
	return false;
}

void AFortAthenaZiplineBase::OnZipliningStarted_Implementation(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent)
{
}

void AFortAthenaZiplineBase::OnZipliningStopped_Implementation(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent, float ZiplineUsageDuration)
{
}

bool AFortAthenaZiplineBase::ShouldIgnoreWaterBody_Implementation(AFortPlayerPawn* InteractingPawn, AFortWaterBodyActor* WaterBody) const
{
	return false;
}

bool AFortAthenaZiplineBase::ShouldOverrideVelocityDirection_Implementation(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent, float& OutVelocityDirection) const
{
	return false;
}

bool AFortAthenaZiplineBase::UseInteractToEnterZipline() const
{
	return false;
}

void AFortAthenaZipline::Initialize(const FVector& NewStartPosition, const FVector& NewEndPosition)
{
}

void AFortAthenaZipline::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaZipline, StartPosition);
	DOREPLIFETIME(AFortAthenaZipline, EndPosition);
	DOREPLIFETIME(AFortAthenaZipline, bInitialized);
}
