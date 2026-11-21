// Copyright Epic Games, Inc. All Rights Reserved.

#include "Replay/FortReplayMovableSpotLight.h"
#include "Net/UnrealNetwork.h"

void AFortReplayMovableSpotLight::OnRep_RepColor()
{
}

void AFortReplayMovableSpotLight::OnRep_RepEnabled()
{
}

void AFortReplayMovableSpotLight::OnRep_RepInnerAngle()
{
}

void AFortReplayMovableSpotLight::OnRep_RepIntensity()
{
}

void AFortReplayMovableSpotLight::OnRep_RepOuterAngle()
{
}

void AFortReplayMovableSpotLight::OnRep_RepRadius()
{
}

void AFortReplayMovableSpotLight::OnRep_RepTemperature()
{
}

void AFortReplayMovableSpotLight::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortReplayMovableSpotLight, bGroupMoveLocked);
	DOREPLIFETIME(AFortReplayMovableSpotLight, LightIndex);
	DOREPLIFETIME(AFortReplayMovableSpotLight, RepInnerAngle);
	DOREPLIFETIME(AFortReplayMovableSpotLight, RepOuterAngle);
	DOREPLIFETIME(AFortReplayMovableSpotLight, RepIntensity);
	DOREPLIFETIME(AFortReplayMovableSpotLight, RepRadius);
	DOREPLIFETIME(AFortReplayMovableSpotLight, RepColorR);
	DOREPLIFETIME(AFortReplayMovableSpotLight, RepColorG);
	DOREPLIFETIME(AFortReplayMovableSpotLight, RepColorB);
	DOREPLIFETIME(AFortReplayMovableSpotLight, RepTemperature);
	DOREPLIFETIME(AFortReplayMovableSpotLight, bRepEnabled);
	DOREPLIFETIME(AFortReplayMovableSpotLight, bDebugDraw);
}
