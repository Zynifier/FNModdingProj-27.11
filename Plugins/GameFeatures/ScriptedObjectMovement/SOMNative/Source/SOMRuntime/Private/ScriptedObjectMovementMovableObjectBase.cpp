// Copyright Epic Games, Inc. All Rights Reserved.

#include "ScriptedObjectMovementMovableObjectBase.h"
#include "Net/UnrealNetwork.h"

void AFortScriptedObjectMovement_MovableObjectBase::BeginMovingToStaticPathNode_Implementation(const FScriptedObjectMovement_StaticPathStepData& StepData)
{
}

bool AFortScriptedObjectMovement_MovableObjectBase::BlockOverlappingStaticPathSteps_Implementation() const
{
	return false;
}

void AFortScriptedObjectMovement_MovableObjectBase::Cheat_NetMulticast_SendDebugTimerInfo_Implementation(const float ServerTimeWhenQueryInvoked, const float RemainingTime)
{
}

void AFortScriptedObjectMovement_MovableObjectBase::CheatDrawKeyframes()
{
}

void AFortScriptedObjectMovement_MovableObjectBase::ConfigureStaticMeshToSlotDefinition(UFortScriptedObjectMovement_SlotDefinition* SlotDefinition, UStaticMeshComponent* StaticMeshComponent)
{
}

void AFortScriptedObjectMovement_MovableObjectBase::Editor_ClearResetObjectLocation()
{
}

void AFortScriptedObjectMovement_MovableObjectBase::Editor_DebugLogStaticPathTravelIndex()
{
}

void AFortScriptedObjectMovement_MovableObjectBase::Editor_NextStep()
{
}

void AFortScriptedObjectMovement_MovableObjectBase::Editor_PreviousStep()
{
}

void AFortScriptedObjectMovement_MovableObjectBase::Editor_ResetObject()
{
}

void AFortScriptedObjectMovement_MovableObjectBase::Editor_TryJumpToStartStep()
{
}

UStaticMeshComponent* AFortScriptedObjectMovement_MovableObjectBase::GetScriptedObjectStaticMeshComponent_Implementation()
{
	return nullptr;
}

void AFortScriptedObjectMovement_MovableObjectBase::GetStaticPathTravelingBounds_Implementation(FVector& OutBoxExtent) const
{
}

float AFortScriptedObjectMovement_MovableObjectBase::GetStaticPathZOffsetHeight_Implementation() const
{
	return float();
}

void AFortScriptedObjectMovement_MovableObjectBase::HandleSlotDefinitionSlotted_Implementation(UFortScriptedObjectMovement_SlotDefinition* SlotDefinition)
{
}

void AFortScriptedObjectMovement_MovableObjectBase::NotifyStaticPathStepComplete(bool bReachedBeginPlaySkipStep)
{
}

void AFortScriptedObjectMovement_MovableObjectBase::OnRep_CurrentStepData()
{
}

void AFortScriptedObjectMovement_MovableObjectBase::SetCanEverAffectNavigation(bool bCanEverAffectNavigation, UActorComponent* TargetActorComponent)
{
}

void AFortScriptedObjectMovement_MovableObjectBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortScriptedObjectMovement_MovableObjectBase, CurrentStepData);
}
