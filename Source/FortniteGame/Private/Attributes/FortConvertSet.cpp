// Copyright Epic Games, Inc. All Rights Reserved.

#include "Attributes/FortConvertSet.h"
#include "Net/UnrealNetwork.h"

void UFortConvertSet::OnRep_ConvertResistance(const FFortGameplayAttributeData& OldValue)
{
}

void UFortConvertSet::OnRep_MaxConvertResistance(const FFortGameplayAttributeData& OldValue)
{
}

void UFortConvertSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortConvertSet, ConvertResistance);
	DOREPLIFETIME(UFortConvertSet, MaxConvertResistance);
}
