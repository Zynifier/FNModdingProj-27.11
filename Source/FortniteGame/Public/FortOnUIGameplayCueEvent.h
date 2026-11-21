// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "FortOnUIGameplayCueEvent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnUIGameplayCueEvent, FName, CueName, TEnumAsByte<EGameplayCueEvent::Type>, EventType, const FGameplayCueParameters&, Parameters);

