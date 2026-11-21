// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerAnimInstance_GolfCartDriver.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_GolfCartDriver : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	FFortAnimInput_GolfCart GolfCartInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GolfCartDriver")
	FFortAnimInput_VelocityImpact VelocityImpact;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCartDriver")
	FVector ImpactDisplacement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GolfCart")
	FFortAnimInput_SocketBasedIKTarget RightHandIKTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GolfCart")
	FFortAnimInput_SocketBasedIKTarget LeftHandIKTarget;

};

