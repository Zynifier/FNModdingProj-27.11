// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Traverse.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_Traverse::OnRep_CurrentPointIndex()
{
}

void AFortAthenaMutator_Traverse::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Traverse, TraversePoints);
	DOREPLIFETIME(AFortAthenaMutator_Traverse, CurrentPointIndex);
}
