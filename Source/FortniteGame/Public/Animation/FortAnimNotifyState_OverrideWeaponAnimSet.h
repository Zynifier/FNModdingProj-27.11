// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_OverrideWeaponAnimSet.generated.h"

class UFortWeaponAnimSet;

UCLASS(HideCategories=("Object"), meta=(DisplayName="Override Weapon AnimSet"))
class UFortAnimNotifyState_OverrideWeaponAnimSet : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_OverrideWeaponAnimSet")
	TObjectPtr<UFortWeaponAnimSet> WeaponOverrideAnimSet;

};

