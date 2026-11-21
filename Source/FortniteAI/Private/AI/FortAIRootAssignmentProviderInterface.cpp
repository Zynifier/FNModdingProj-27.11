// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAIRootAssignmentProviderInterface.h"

const FFortAIAssignmentIdentifier& IFortAIRootAssignmentProviderInterface::GetRootAssignmentIdentifier() const
{
	static FFortAIAssignmentIdentifier Dummy;
	return Dummy;
}
