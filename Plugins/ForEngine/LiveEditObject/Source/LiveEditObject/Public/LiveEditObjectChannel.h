// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Channel.h"
#include "LiveEditObjectChannel.generated.h"

UCLASS(Abstract)
class LIVEEDITOBJECT_API ULiveEditNetworkStreamChannel : public UChannel
{
	GENERATED_BODY()

};

UCLASS()
class LIVEEDITOBJECT_API ULiveEditLargeNetworkMessageChannel : public ULiveEditNetworkStreamChannel
{
	GENERATED_BODY()

};

UCLASS()
class LIVEEDITOBJECT_API ULiveEditObjectChannel : public ULiveEditLargeNetworkMessageChannel
{
	GENERATED_BODY()

};

