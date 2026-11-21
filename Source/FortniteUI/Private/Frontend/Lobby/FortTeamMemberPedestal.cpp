// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/Lobby/FortTeamMemberPedestal.h"

void AFortTeamMemberPedestal::ApplyUniformOverrideMaterial(UMaterialInterface* OverrideMaterial)
{
}

void AFortTeamMemberPedestal::ClearOverrideMaterial()
{
}

int32 AFortTeamMemberPedestal::GetCurrentTeamSize() const
{
	return int32();
}

FString AFortTeamMemberPedestal::GetTeamMemberDisplayName() const
{
	return FString();
}

void AFortTeamMemberPedestal::HandleOnAnimInstanceEventReceived(const UFortAnimInputEvent* AnimInputEvent)
{
}

void AFortTeamMemberPedestal::HandlePlaceholderMeshBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
}

void AFortTeamMemberPedestal::HandlePlaceholderMeshClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
}

void AFortTeamMemberPedestal::HandlePlaceholderMeshEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
}

void AFortTeamMemberPedestal::HandlePlaceholderMeshInputTouchEnd(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
}

void AFortTeamMemberPedestal::InitializePlaceholderMesh(UStaticMeshComponent* PlaceholderMesh)
{
}

bool AFortTeamMemberPedestal::IsCurrentMemberLocal() const
{
	return false;
}

bool AFortTeamMemberPedestal::IsInFrontend() const
{
	return false;
}

bool AFortTeamMemberPedestal::IsInLocalSquadGroup() const
{
	return false;
}

bool AFortTeamMemberPedestal::IsValidTeamMember() const
{
	return false;
}
