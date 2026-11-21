// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveSoundUpdateInterface.h"
#include "Subsystems/AudioEngineSubsystem.h"
#include "FortMetaSoundInterfaceSubsystem.generated.h"

UENUM(meta=(Bitflags))
enum class EFortMetaSoundAutoInterfaceTypes : uint8
{
	None = 0,
	Movement = 1,
	Time = 2,
	ActiveSound = 4,
};

UCLASS()
class UFortMetaSoundInterfaceSubsystem : public UAudioEngineSubsystem, public IActiveSoundUpdateInterface
{
	GENERATED_BODY()

};

