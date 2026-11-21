// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMDeviceCable.h"
#include "Net/UnrealNetwork.h"

void AFMDeviceCable::BuildMeshOnSpline(bool bCollisionEnabled)
{
}

void AFMDeviceCable::ConnectConstantPort(UFMDeviceCablePortComponent* Port)
{
}

void AFMDeviceCable::ConnectPort(UFMDeviceCablePortComponent* Port)
{
}

void AFMDeviceCable::Disconnect()
{
}

EDeviceCablePortDataType AFMDeviceCable::GetCableDataType() const
{
	return EDeviceCablePortDataType();
}

USplineComponent* AFMDeviceCable::GetCableSpline() const
{
	return nullptr;
}

UFMDeviceCablePortComponent* AFMDeviceCable::GetConstantPort() const
{
	return nullptr;
}

UStaticMeshComponent* AFMDeviceCable::GetDeviceCableHead() const
{
	return nullptr;
}

UFMDeviceCablePortComponent* AFMDeviceCable::GetPortA() const
{
	return nullptr;
}

UFMDeviceCablePortComponent* AFMDeviceCable::GetPortB() const
{
	return nullptr;
}

void AFMDeviceCable::OnRep_ServerPortA()
{
}

void AFMDeviceCable::OnRep_ServerPortB()
{
}

void AFMDeviceCable::SetFocusedVisuals(bool bIsFocused)
{
}

void AFMDeviceCable::UpdateDeviceCableAnimator()
{
}

void AFMDeviceCable::UpdateVisualParameters()
{
}

void AFMDeviceCable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFMDeviceCable, ConstantPort);
	DOREPLIFETIME(AFMDeviceCable, ServerPortA);
	DOREPLIFETIME(AFMDeviceCable, ServerPortB);
}
