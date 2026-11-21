// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Building/AthenaCapturePoint.h"
#include "Net/UnrealNetwork.h"

ECapturePointState AAthenaCapturePoint::GetCaptureState() const
{
	return ECapturePointState();
}

int32 AAthenaCapturePoint::GetNumDancingPlayers()
{
	return int32();
}

bool AAthenaCapturePoint::HasDancingPlayer()
{
	return false;
}

void AAthenaCapturePoint::OnCapturePointActiveStateChange_Implementation(bool bInActive)
{
}

void AAthenaCapturePoint::OnCapturePointLockStateChange_Implementation(bool bInLocked)
{
}

void AAthenaCapturePoint::OnCapturePointStateChange_Implementation(ECapturePointState InState, uint8 InTeam)
{
}

void AAthenaCapturePoint::OnEnterCapturePoint(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AAthenaCapturePoint::OnLeaveCapturePoint(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AAthenaCapturePoint::OnRep_bActivated()
{
}

void AAthenaCapturePoint::OnRep_bLocked()
{
}

void AAthenaCapturePoint::OnRep_bPermanentShutdown()
{
}

void AAthenaCapturePoint::OnRep_CaptureState()
{
}

void AAthenaCapturePoint::OnRep_IconMaterialIndexParameter()
{
}

void AAthenaCapturePoint::OnRep_ReplicatedCapturePercentage()
{
}

void AAthenaCapturePoint::SetActivatedState(bool bInActivated)
{
}

void AAthenaCapturePoint::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAthenaCapturePoint, IconMaterialIndexParameter);
	DOREPLIFETIME(AAthenaCapturePoint, bPermanentShutdown);
	DOREPLIFETIME(AAthenaCapturePoint, bActivated);
	DOREPLIFETIME(AAthenaCapturePoint, bLocked);
	DOREPLIFETIME(AAthenaCapturePoint, NumCapturingPoint);
	DOREPLIFETIME(AAthenaCapturePoint, TeamCapturingPoint);
	DOREPLIFETIME(AAthenaCapturePoint, TeamControllingPoint);
	DOREPLIFETIME(AAthenaCapturePoint, TeamOwningPoint);
	DOREPLIFETIME(AAthenaCapturePoint, CaptureState);
	DOREPLIFETIME(AAthenaCapturePoint, ReplicatedCapturePercentage);
}
