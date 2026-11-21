// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/BoneReference.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "RockBouncyChassis.h"
#include "AnimNode_RockVehicleController.generated.h"

USTRUCT(BlueprintType, meta=(BlueprintInternalUseOnly="true"))
struct ROCKVEHICLERUNTIME_API FAnimNode_RockVehicleController : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RockVehicle")
	FBoneReference ChassisBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockVehicle", meta=(PinShownByDefault))
	FBouncyChassisState BouncyChassis;

};

