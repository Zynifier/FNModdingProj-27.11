// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_Interaction.h"

void UFortControllerComponent_Interaction::AddInteractionPointOptions(const FInteractionPointOptions& Options, UObject* ContextObject, float Priority, bool bEnabled)
{
}

bool UFortControllerComponent_Interaction::BP_ServerAttemptInteractInternal(APawn* InteractingPawn, float InInteractDistance, AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, TInteractionType InteractType, UObject* OptionalObjectData, EInteractionBeingAttempted InteractionBeingAttempted)
{
	return false;
}

void UFortControllerComponent_Interaction::ClientAddInteractionPointOptions_Implementation(const FInteractionPointOptions& ContextObject, UObject* Caller, float Priority)
{
}

void UFortControllerComponent_Interaction::ClientDisableTracingFromPlayerOnFail_Implementation()
{
}

void UFortControllerComponent_Interaction::ClientEnableTracingFromPlayerOnFail_Implementation(float InInteractDistanceFromPlayer)
{
}

void UFortControllerComponent_Interaction::ClientRemoveInteractionPointOptions_Implementation(UObject* ContextObject)
{
}

void UFortControllerComponent_Interaction::ClientSetInteractionPointOptionsEnabled_Implementation(UObject* ContextObject, bool bEnabled)
{
}

void UFortControllerComponent_Interaction::FixupInteractionWidgetsOnUnzoom()
{
}

AActor* UFortControllerComponent_Interaction::GetInteractActor() const
{
	return nullptr;
}

UFortInteractContextInfo* UFortControllerComponent_Interaction::K2_GetInteractResponse()
{
	return nullptr;
}

void UFortControllerComponent_Interaction::OnEnterAircraft(AController* EnteringController)
{
}

void UFortControllerComponent_Interaction::OnExitAircraft(AController* ExitingController)
{
}

void UFortControllerComponent_Interaction::RemoveInteractionPointOptions(UObject* ContextObject)
{
}

void UFortControllerComponent_Interaction::ServerAttemptInteract_Implementation(AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, TInteractionType InteractType, UObject* OptionalObjectData, EInteractionBeingAttempted InteractionBeingAttempted, int32 RequestId)
{
}
bool UFortControllerComponent_Interaction::ServerAttemptInteract_Validate(AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, TInteractionType InteractType, UObject* OptionalObjectData, EInteractionBeingAttempted InteractionBeingAttempted, int32 RequestId)
{
	return true;
}

void UFortControllerComponent_Interaction::ServerNotifyEndLongUse_Implementation(AActor* ReceivingActor, bool bUseCompleted)
{
}
bool UFortControllerComponent_Interaction::ServerNotifyEndLongUse_Validate(AActor* ReceivingActor, bool bUseCompleted)
{
	return true;
}

void UFortControllerComponent_Interaction::ServerNotifyStartLongUse_Implementation(AActor* ReceivingActor)
{
}
bool UFortControllerComponent_Interaction::ServerNotifyStartLongUse_Validate(AActor* ReceivingActor)
{
	return true;
}

void UFortControllerComponent_Interaction::SetInteractionPointOptionsEnabled(UObject* ContextObject, bool bEnabled)
{
}

void UFortControllerComponent_Interaction::SetShouldAutoOpenSwingingDoors(const bool bOpenSwingingDoorsAutomatically)
{
}
