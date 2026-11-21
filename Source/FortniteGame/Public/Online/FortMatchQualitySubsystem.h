// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortMatchQualitySubsystem.generated.h"

UENUM()
enum class EBadMatchType : uint8
{
	None = 0,
	Ping = 1,
	PacketLoss = 2,
	NotMonitored = 3,
};

UCLASS(MinimalAPI)
class UFortMatchQualitySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

};

