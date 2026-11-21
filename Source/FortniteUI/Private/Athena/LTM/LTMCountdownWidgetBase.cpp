// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/LTMCountdownWidgetBase.h"

FText ULTMCountdownWidgetBase::GetTimeText(int32 TimeRemaining)
{
	return FText();
}

void ULTMCountdownWidgetBase::HandleCountdownFinished()
{
}

void ULTMCountdownWidgetBase::HandleCountdownStarted(int32 TimeRemaining)
{
}

void ULTMCountdownWidgetBase::HandleCountdownUpdate(int32 TimeRemaining)
{
}

void ULTMCountdownWidgetBase::HandleFinalCountdownStarted(int32 TimeRemaining)
{
}
