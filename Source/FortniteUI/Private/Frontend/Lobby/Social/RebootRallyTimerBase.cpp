// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/Lobby/Social/RebootRallyTimerBase.h"

URebootRallyTimerBase::URebootRallyTimerBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const FText& URebootRallyTimerBase::GetRemainingTimeForRebootRallyEnd() const
{
	static FText Dummy;
	return Dummy;
}
