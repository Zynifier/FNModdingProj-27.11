// Copyright Epic Games, Inc. All Rights Reserved.

#include "DynamicUI/DynamicUIDirectorBase.h"

void ADynamicUIDirectorBase::AddScene(const UDynamicUIScene* Scene)
{
}

ULocalPlayer* ADynamicUIDirectorBase::GetOwningLocalPlayer() const
{
	return nullptr;
}

APlayerController* ADynamicUIDirectorBase::GetOwningLocalPlayerController() const
{
	return nullptr;
}

void ADynamicUIDirectorBase::RemoveScene(const UDynamicUIScene* Scene)
{
}
