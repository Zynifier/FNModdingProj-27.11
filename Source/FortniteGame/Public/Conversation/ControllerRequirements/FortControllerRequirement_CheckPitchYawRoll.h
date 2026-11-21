// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_CheckPitchYawRoll.generated.h"

USTRUCT()
struct FRotatorErrorCheck
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RotatorErrorCheck")
	bool bEnabled;

	UPROPERTY(EditAnywhere, Category="RotatorErrorCheck", meta=(editCondition="bEnabled"))
	float TestFromAngle;

	UPROPERTY(EditAnywhere, Category="RotatorErrorCheck", meta=(editCondition="bEnabled"))
	float ToleratedErrorInDegrees;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Check Pitch Yaw Roll"))
class UFortControllerRequirement_CheckPitchYawRoll : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_CheckPitchYawRoll")
	FRotatorErrorCheck PitchErrorCheck;

	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_CheckPitchYawRoll")
	FRotatorErrorCheck YawErrorCheck;

	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_CheckPitchYawRoll")
	FRotatorErrorCheck RollErrorCheck;

};

