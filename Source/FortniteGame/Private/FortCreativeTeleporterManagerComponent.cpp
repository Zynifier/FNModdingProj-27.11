// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativeTeleporterManagerComponent.h"

const TSet<AFortCreativeTeleporter*> UFortCreativeTeleporterManagerComponent::GetTeleportersInGroup(const EFortCreativeTeleporterGroup Group) const
{
	return TSet<AFortCreativeTeleporter*>();
}

void UFortCreativeTeleporterManagerComponent::RegisterTeleporterWithGroup(AFortCreativeTeleporter* TeleporterToRegister, const EFortCreativeTeleporterGroup GroupToRegisterOn)
{
}

void UFortCreativeTeleporterManagerComponent::UnregisterTeleporterFromGroup(AFortCreativeTeleporter* TeleporterToUnregister, const EFortCreativeTeleporterGroup GroupToUnregisterOn)
{
}
