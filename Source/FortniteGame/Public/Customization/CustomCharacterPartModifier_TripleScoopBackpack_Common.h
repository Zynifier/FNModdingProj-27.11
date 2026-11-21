// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartModifier.h"
#include "CustomCharacterPartModifier_TripleScoopBackpack_Common.generated.h"

UCLASS(meta=(ChildCanTick="FALSE"))
class ACustomCharacterPartModifier_TripleScoopBackpack_Common : public ACustomCharacterPartModifier
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Triple Scoop", meta=(ClampMin="0.01"))
	float BaseWheelSpeed;

	UPROPERTY(EditAnywhere, Category="Triple Scoop", meta=(ClampMin="0"))
	float IdlePlayerSpeed;

	UPROPERTY(EditAnywhere, Category="Triple Scoop", meta=(ClampMin="1"))
	int32 RollingPeriod;

};

