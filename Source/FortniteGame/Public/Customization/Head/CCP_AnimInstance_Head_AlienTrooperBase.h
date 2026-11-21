// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/HeadPartAnimInstance.h"
#include "CCP_AnimInstance_Head_AlienTrooperBase.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Head_AlienTrooperBase : public UHeadPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="Male Alien Trooper Head Base")
	FVector GravityOverride;

};

