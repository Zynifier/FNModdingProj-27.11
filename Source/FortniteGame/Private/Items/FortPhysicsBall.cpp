// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortPhysicsBall.h"
#include "Net/UnrealNetwork.h"

void AFortPhysicsBall::AuthTriggerTargetHit_Implementation(FVector StartPos, FVector EndPos)
{
}
bool AFortPhysicsBall::AuthTriggerTargetHit_Validate(FVector StartPos, FVector EndPos)
{
	return true;
}

void AFortPhysicsBall::UpdateDirectionAndRotation(float DeltaSeconds)
{
}

void AFortPhysicsBall::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPhysicsBall, bApplyingBackspin);
	DOREPLIFETIME(AFortPhysicsBall, bApplyingLift);
}
