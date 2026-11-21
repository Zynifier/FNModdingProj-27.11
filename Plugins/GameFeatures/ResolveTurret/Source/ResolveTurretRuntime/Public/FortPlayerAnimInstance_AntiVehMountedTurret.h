// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerAnimInstance_AntiVehMountedTurret.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_AntiVehMountedTurret : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Anti Vehicle Mounted Turret Player")
	FVector HandAttachL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Anti Vehicle Mounted Turret Player")
	FVector HandAttachR;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Anti Vehicle Mounted Turret Player|Settings")
	FName HandAttachBoneNameL;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Anti Vehicle Mounted Turret Player|Settings")
	FName HandAttachBoneNameR;

};

