// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ForwardingChannelsSubsystem.generated.h"

class IForwardingChannelFactory;

UCLASS(Transient, meta=(DisplayName="Forwarding Channels Subsystem"))
class FORWARDINGCHANNELS_API UForwardingChannelsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TScriptInterface<IForwardingChannelFactory>> ForwardingChannelFactories;

};

