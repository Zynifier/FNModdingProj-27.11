// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "Vehicles/FortTreadVehicleAnimInstance.h"
#include "FortAnimNode_TransformRollerTreads.generated.h"

class AFortTreadVehicle;

USTRUCT()
struct FFortAnimNode_TransformRollerTreads : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortTreadVehicle> OwnerTreadVehicle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RollerTreads", meta=(PinShownByDefault))
	TMap<FName, FRollerAnimState> RollerAnimStates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RollerTreads", meta=(PinShownByDefault))
	FString RotationBoneName;

protected:
	UPROPERTY(Transient)
	uint8 bRequiresMovementComponentToEvaluateAsValid : 1;

	UPROPERTY(Transient)
	bool bHasBeenInitialized;

};

