// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaTutorialBase::ExecuteTutorialStep_Client_Implementation(int32 StepIndex)
{
}

bool AFortAthenaTutorialBase::IsExecuting() const
{
	return false;
}

void AFortAthenaTutorialBase::OnClientStepCompleted_Server_Implementation(int32 StepIndex)
{
}

void AFortAthenaTutorialBase::OnRep_TrackedActor()
{
}

void AFortAthenaTutorialBase::OnStartTutorial_Client_Implementation()
{
}

void AFortAthenaTutorialBase::OnStopTutorial_Client_Implementation()
{
}

void AFortAthenaTutorialBase::SetEasyInteractIconActor_Implementation(AActor* TrackedActor)
{
}

void AFortAthenaTutorialBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaTutorialBase, bExecuting);
	DOREPLIFETIME(AFortAthenaTutorialBase, CurrentStepIndex);
	DOREPLIFETIME(AFortAthenaTutorialBase, CurrentTrackedActor);
}
