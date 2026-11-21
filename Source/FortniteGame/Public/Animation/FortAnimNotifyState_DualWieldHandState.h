// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Athena/FortWeaponPickaxeDualWieldAthena.h"
#include "FortAnimNotifyState_DualWieldHandState.generated.h"

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_DualWieldHandState : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WeaponState")
	EFortDualWieldSwingState EnterWeaponState;

	UPROPERTY(EditAnywhere, Category="WeaponState")
	EFortDualWieldSwingState ExitWeaponState;

};

