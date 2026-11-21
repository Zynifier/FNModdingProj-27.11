// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricInteractionTool.h"
#include "Net/UnrealNetwork.h"

void AFabricInteractionTool::ClientDeactiveWeaponAndState_Implementation()
{
}

void AFabricInteractionTool::ClientStopInteracting_Implementation()
{
}

void AFabricInteractionTool::DeactiveWeaponAndState()
{
}

float AFabricInteractionTool::GetContinuousInteractableValueNormalized()
{
	return float();
}

EFabricContinuousInteractionDirection AFabricInteractionTool::GetContinuousInteractionDirection()
{
	return EFabricContinuousInteractionDirection();
}

float AFabricInteractionTool::GetContinuousMovementValue()
{
	return float();
}

int32 AFabricInteractionTool::GetContinuousStateValue()
{
	return int32();
}

EFabricInteractionToolStates AFabricInteractionTool::GetFabricInteractionToolState()
{
	return EFabricInteractionToolStates();
}

USceneComponent* AFabricInteractionTool::GetHoveredInteractableHitComponent()
{
	return nullptr;
}

EFabricInteractableType AFabricInteractionTool::GetHoveredInteractableType()
{
	return EFabricInteractableType();
}

UObject* AFabricInteractionTool::GetPressedInteractable()
{
	return nullptr;
}

void AFabricInteractionTool::HandleMetasoundGeneratorCrossfade(float CrossfadeSeconds)
{
}

bool AFabricInteractionTool::IsHoldingCables()
{
	return false;
}

bool AFabricInteractionTool::IsRunningOnOwningClient() const
{
	return false;
}

void AFabricInteractionTool::OnRep_ServerContinuousInteractableValue()
{
}

void AFabricInteractionTool::OnRep_ServerInteractionData()
{
}

void AFabricInteractionTool::OnRep_ServerIsHoldingCable()
{
}

void AFabricInteractionTool::OnRep_ServerTriggerPressed()
{
}

void AFabricInteractionTool::ServerHandleFITFired_Implementation()
{
}

void AFabricInteractionTool::ServerSetContinuousInteractableValue_Implementation(float Value)
{
}

void AFabricInteractionTool::ServerSetInteractionData_Implementation(FInteractionData NewData)
{
}

void AFabricInteractionTool::ServerSetIsHoldingCable_Implementation(bool bHoldingCable)
{
}

void AFabricInteractionTool::ServerSetSplinePoints_Implementation(FInteractionSplinePoints SplinePoints)
{
}

void AFabricInteractionTool::ServerSetTriggerPressed_Implementation(bool bPressed)
{
}

void AFabricInteractionTool::UnholsterWeapon()
{
}

void AFabricInteractionTool::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFabricInteractionTool, ServerInteractionData);
	DOREPLIFETIME(AFabricInteractionTool, bServerTriggerPressed);
	DOREPLIFETIME(AFabricInteractionTool, bServerIsHoldingCable);
	DOREPLIFETIME(AFabricInteractionTool, ServerSplinePoints);
	DOREPLIFETIME(AFabricInteractionTool, ServerContinuousInteractableValue);
}
