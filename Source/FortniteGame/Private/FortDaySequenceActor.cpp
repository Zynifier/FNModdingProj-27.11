// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortDaySequenceActor.h"
#include "Net/UnrealNetwork.h"

void AFortDaySequenceActor::HandleAntiAliasingQualityChanged()
{
}

void AFortDaySequenceActor::HandleEffectsQualityChanged()
{
}

void AFortDaySequenceActor::HandleGlobalIlluminationQualityChanged()
{
}

void AFortDaySequenceActor::HandlePostProcessQualityChanged()
{
}

void AFortDaySequenceActor::HandleReflectionQualityChanged()
{
}

void AFortDaySequenceActor::HandleShadowQualityChanged()
{
}

void AFortDaySequenceActor::HandleTextureQualityChanged()
{
}

void AFortDaySequenceActor::HandleViewDistanceQualityChanged()
{
}

void AFortDaySequenceActor::OnRep_ServerTodIsVisible()
{
}

void AFortDaySequenceActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortDaySequenceActor, bServerTODIsVisible);
}
