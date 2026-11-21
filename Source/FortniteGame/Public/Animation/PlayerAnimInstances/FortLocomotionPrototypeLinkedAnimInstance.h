// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortLocomotionPrototypeLinkedAnimInstance.generated.h"

class UFortLocomotionPrototypeAnimInstance;

UCLASS(HideCategories=("AnimInstance"))
class FORTNITEGAME_API UFortLocomotionPrototypeLinkedAnimInstance : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<UFortLocomotionPrototypeAnimInstance> MainProtoAnimInstanceWeakPtr;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	bool bEnableDistanceMatching;

};

