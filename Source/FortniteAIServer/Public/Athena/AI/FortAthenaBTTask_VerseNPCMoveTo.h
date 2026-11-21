// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaBTTask_MoveTo.h"
#include "FortAthenaBTTask_VerseNPCMoveTo.generated.h"

UCLASS()
class UFortAthenaBTTask_VerseNPCMoveTo : public UFortAthenaBTTask_MoveTo
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess))
	FName AcceptableRadiusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess))
	FName AllowStrafeKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess))
	FName AllowPartialPathName;

};

