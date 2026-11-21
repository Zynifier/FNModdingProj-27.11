// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWeaponDelegates.generated.h"

class AFortWeapon;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponHudKeyActionUpdated, AFortWeapon*, Weapon);

