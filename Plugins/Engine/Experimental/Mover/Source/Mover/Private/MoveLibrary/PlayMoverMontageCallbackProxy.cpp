// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoveLibrary/PlayMoverMontageCallbackProxy.h"

UPlayMoverMontageCallbackProxy* UPlayMoverMontageCallbackProxy::CreateProxyObjectForPlayMoverMontage(UKinematicMoverComponent* InMoverComponent, UAnimMontage* MontageToPlay, float PlayRate, float StartingPosition, FName StartingSection)
{
	return nullptr;
}

void UPlayMoverMontageCallbackProxy::OnMoverMontageEnded(FName IgnoredNotifyName)
{
}
