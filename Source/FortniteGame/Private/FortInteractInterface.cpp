// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortInteractInterface.h"

bool IFortInteractInterface::ServerOnAttemptInteract(const FInteractionType& InteractType)
{
	return false;
}

TInteractionType UInteractionTypeContext::GetInteractionType() const
{
	return TInteractionType();
}
