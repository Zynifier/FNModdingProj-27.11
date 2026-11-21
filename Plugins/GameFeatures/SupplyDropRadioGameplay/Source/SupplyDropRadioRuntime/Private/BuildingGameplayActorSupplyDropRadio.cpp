// Copyright Epic Games, Inc. All Rights Reserved.

#include "BuildingGameplayActorSupplyDropRadio.h"
#include "Net/UnrealNetwork.h"

ESupplyDropRadioBalloonState ABuildingGameplayActorSupplyDropRadio::GetBalloonState() const
{
	return ESupplyDropRadioBalloonState();
}

float ABuildingGameplayActorSupplyDropRadio::GetGravityZ() const
{
	return float();
}

AActor* ABuildingGameplayActorSupplyDropRadio::GetHighestAttachParent(const AActor* InActor) const
{
	return nullptr;
}

void ABuildingGameplayActorSupplyDropRadio::HandleMoveIgnoredActorEndPlay(AActor* EndPlayActor, EEndPlayReason::Type Reason)
{
}

bool ABuildingGameplayActorSupplyDropRadio::IsMoving() const
{
	return false;
}

void ABuildingGameplayActorSupplyDropRadio::SetBalloonState(const ESupplyDropRadioBalloonState InBalloonState)
{
}

void ABuildingGameplayActorSupplyDropRadio::SetGravityMultiplier(const float InGravityMultiplier)
{
}

void ABuildingGameplayActorSupplyDropRadio::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorSupplyDropRadio, DistanceFromOriginalSpawnLocForBalloonOpen);
	DOREPLIFETIME(ABuildingGameplayActorSupplyDropRadio, BalloonState);
	DOREPLIFETIME(ABuildingGameplayActorSupplyDropRadio, bMoving);
	DOREPLIFETIME(ABuildingGameplayActorSupplyDropRadio, FallSpeed);
	DOREPLIFETIME(ABuildingGameplayActorSupplyDropRadio, BalloonOpenedFallSpeed);
	DOREPLIFETIME(ABuildingGameplayActorSupplyDropRadio, GravityMultiplier);
	DOREPLIFETIME(ABuildingGameplayActorSupplyDropRadio, ServerLocation);
	DOREPLIFETIME(ABuildingGameplayActorSupplyDropRadio, ClientLocationCorrectionMaxDistSqWhenBalloonDisabled);
	DOREPLIFETIME(ABuildingGameplayActorSupplyDropRadio, ClientLocationCorrectionMaxDistSqWhenBalloonEnabled);
}
