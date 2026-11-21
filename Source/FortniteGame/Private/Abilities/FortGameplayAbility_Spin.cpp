// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortGameplayAbility_Spin.h"
#include "Net/UnrealNetwork.h"

UFortPawnSpinParamsObj* UFortPawnSpinParamsObj::BP_CreateFortPawnSpinParamsObjInstance(UObject* WorldContextObject)
{
	return nullptr;
}

void UFortPawnSpinParamsObj::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPawnSpinParamsObj, bReplicatedFlag);
}
