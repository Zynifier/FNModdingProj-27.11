// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "FortAnimNotify_MeleeAnimTrails.generated.h"

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="Melee Anim Trails Off"))
class UFortAnimNotify_MeleeAnimTrails_Off : public UAnimNotify
{
	GENERATED_BODY()

};

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="Melee Anim Trails On"))
class UFortAnimNotify_MeleeAnimTrails_On : public UAnimNotify
{
	GENERATED_BODY()

};

